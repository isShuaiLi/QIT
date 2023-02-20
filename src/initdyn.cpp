#include <headers/initdyn.hpp>
#include <headers/globals.hpp>
#include <headers/mt.h>
#include <cmath>
#include <headers/constants.hpp>
#include <iostream>
#include <fstream>
void InitDyn()
{
    ions = new coarse[numberofions];
    CalcInfo();

    Init_r();
    Init_v(); //
    Init_a();
}

void CalcInfo()
{
    double matua,matuq,matub,fsecular;

    mass_kg = mass_Da /(xn * 1e3);
    q_C = q_net * xe;
    cout<<"================= CoarseInfo ================"<<endl;
    cout<<"mass_kg =\t"<<mass_kg<<endl;
    cout<<"q_C =\t"<<q_C<<endl; 
    cout<<"m/z =\t"<<mass_kg/q_C<<"("<< mass_Da / q_net <<")"<<endl;

    matuq = 4*q_C*Urf/(mass_kg*0.004*0.004*(2*pi*frf)*(2*pi*frf)) ;
    matua = 0.0;
    matub = sqrt(matua + 0.5 * matuq*matuq) ;
    fsecular = 0.5 * frf * matub;
    cout<<"matiuEqu.q =\t" << matuq<<"\tmatiuEqu.b =\t"<<matub<<"\tfsecular =\t"<<fsecular<<"\tfsecular(precisely) =\t"<<q2fac(matuq,0.0)<<endl;
    cout<<"k =\t" << 2*q_C*Urf/0.004/0.004<<"\tf=\t"<<sqrt( 2*q_C*Urf/0.004/0.004/mass_kg)<<endl;
    
    cout<<"\t"<<endl; 
}
double q2fac(double qu,double au)
{
    double A,B,C;
    double a[50],b[50],c[50],d[50];
    unsigned int NN = 50;
    double beta,betaold,fac_;
    double error = 10000;

    //初始beta
    A = qu*qu*(au-1.)/((au-1.)*(au-1.)*2. - qu*qu);
    B = pow(qu,4.)*(5.*au+7.)/(32. * pow((au-1),3) * (au-4.));
    C = pow(qu,6.)*(9.*au*au+58.*au+29.)/(64.* pow(au-1,5.) *(au-4)*(au-9));
    beta = sqrt(au-A-B-C);
    betaold = beta;
    //迭代
    do
    {
        for(unsigned i = 0; i<NN; i++)
        {
            a[i] = (beta + 2*(i+1))*(beta + 2*(i+1)) - au ; 
            b[i] = (beta - 2*(i+1))*(beta - 2*(i+1)) - au ; 
        }

        c[NN-1] = qu*qu / (a[NN-1]);
        d[NN-1] = qu*qu / (b[NN-1]);

        for(unsigned i = NN-1; i>0; i--)
        {
            c[i-1] = qu*qu / (a[i-1] - c[i]); 
            d[i-1] = qu*qu / (b[i-1] - d[i]);
        }

        beta = sqrt(au + c[0] + d[0]);
        error = fabs(beta - betaold);
        betaold = beta;
    } while (error < 1e-8);
    
    fac_ = 0.5 * beta * frf;

    return fac_;
    
}

void Init_r()
{
    double* randx,*randy,*randz;
    randx = new double[numberofions];
    randy = new double[numberofions];
    randz = new double[numberofions];
    GenGauss(seed*1,randx,numberofions,0.0,radiusofions);
    GenGauss(seed*2,randy,numberofions,0.0,radiusofions);
    GenGauss(seed*3,randz,numberofions,0.0,radiusofions);

    for(unsigned i = 0; i<numberofions ; i++)
    {
      //  ions[i].r.VSet(randx[i],randy[i],randz[i]);
         ions[i].r.VSet(0,0,0);
    }

    delete[] randx;
    delete[] randy;
    delete[] randz;
}

void Init_v()
{
    double* randvx,*randvy,*randvz;
    double vsigma,vsigma2; 

    randvx = new double[numberofions];
    randvy = new double[numberofions];
    randvz = new double[numberofions];

    vsigma2 = xk*temperature / mass_kg;
    vsigma = sqrt(vsigma2);  

    GenGauss(seed*4,randvx,numberofions,0.0,vsigma);
    GenGauss(seed*5,randvy,numberofions,0.0,vsigma);
    GenGauss(seed*6,randvz,numberofions,0.0,vsigma);

    for(unsigned i = 0; i<numberofions ; i++)
    {
        if(use_randv)
            ions[i].v.VSet(randvx[i],randvy[i],randvz[i]); 
        else
            ions[i].v = initv; 
    }

    delete[] randvx;
    delete[] randvy;
    delete[] randvz;    
}

void Init_a()
{
    for(unsigned i = 0; i<numberofions ; i++)
    {
        ions[i].a.VSet(0.0,0.0,0.0);
    }  
}

void GenRand(long long randseed, double* randval, unsigned int num,double minval,double maxval)
{
    MersenneTwister mt1;
    mt1.init_genrand(randseed);
    for (unsigned int i=0;i<num;i++)
    {
        randval[i] = minval + (maxval-minval)*mt1.genrand_res53();
    }
}

void GenGauss(long long randseed, double* randval, unsigned int num,double meanval,double sigmaval)
{
    MersenneTwister mt1,mt2;
    double A,B,C;

    mt1.init_genrand(randseed);
    mt2.init_genrand(randseed + 10000);
    for (unsigned int i=0;i<num;i++)
    {

        A = sqrt(-2*log(mt1.genrand_res53()));
        B = 2*3.14159*(mt2.genrand_res53());
        C = A * cos(B);
        randval[i] = meanval + C * (sigmaval);
    }
}







