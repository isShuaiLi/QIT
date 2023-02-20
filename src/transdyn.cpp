#include <headers/transdyn.hpp>
#include <headers/vector.hpp>
#include <headers/globals.hpp>
#include <headers/constants.hpp>
#include <cmath>
#include <omp.h>

void transdyn()
{
    LK4();
}

void LK4()
{

   // #pragma omp parallel for  
    for(unsigned int i = 0; i<numberofions; i++)
    {
        vec k1v,k1r,k2v,k2r,k3v,k3r,k4v,k4r;
        vec r_;
        vec v_;
        vec a_; 

        if(ions[i].bOut.VSumAb()) continue;
    
        r_ = ions[i].r;
        v_ = ions[i].v;
        CalcForce(&a_,r_,v_,time_now);
        k1v = a_ * dt_trans;
        k1r = v_ * dt_trans;

        r_ = ions[i].r + k1r * 0.5;
        v_ = ions[i].v + k1v * 0.5;
        CalcForce(&a_,r_,v_, time_now + dt_trans/2 );
        k2v = a_ * dt_trans;
        k2r = v_ * dt_trans;

        r_ = ions[i].r + k2r * 0.5;
        v_ = ions[i].v + k2v * 0.5;
        CalcForce(&a_,r_,v_,time_now + dt_trans/2);
        k3v = a_ * dt_trans;
        k3r = v_ * dt_trans;

        r_ = ions[i].r + k3r;
        v_ = ions[i].v + k3v;
        CalcForce(&a_,r_,v_,time_now + dt_trans);
        k4v = a_ * dt_trans;
        k4r = v_ * dt_trans;

        ions[i].v = ions[i].v + (k1v + k2v*2 + k3v*2 + k4v) * (1/6.);
        ions[i].r = ions[i].r + (k1r + k2r*2 + k3r*2 + k4r) * (1/6.);

        CalcForce(&a_,ions[i].r,ions[i].v,time_now + dt_trans);
        ions[i].a = a_ ;

        ions[i].v.z = 0.0;
        ions[i].r.z = 0.0;
        ions[i].a.z = 0.0;
    }
}

void CalcForce(vec* at,vec rt,vec vt,double t)
{
    double LIT_r0 = 0.004;
    double Urft,Uact;
    vec w0;

    vt.z = 0.0;

    //RF
    if(bUeff == 1)
    {
        Urft = 2*Urf;
        *at = rt * Urft * (1/LIT_r0/LIT_r0) * q_C * (-1.0);
        at->y = at->y * -1.0;        
    }
    else
    {
        Urft = 2*Urf * cos(2*pi*frf*t);
        *at = rt * Urft * (1/LIT_r0/LIT_r0) * q_C * (-1.0);
        at->y = at->y * -1.0;
    }


    //AC
    Uact = Uac * sin(2*pi*fac*t);
    //Uact = (0.05 + (0.09 - 0.05)/(nstep_trans*dt_trans) * t )* sin(2*pi*fac*t);
    at->x = at->x + Uact * (1/LIT_r0) * q_C * (-1.0) * 0.8;
    //at->y = at->y + Uact * (1/LIT_r0) * q_C * (-1.0) * 0.8;

    //damping
    *at = *at  +  vt * (-damp1) ; 
    //at->x = at->x + vt.y * damp2 * Urft/fabs(Urft);

    *at = *at * (1/mass_kg);
    at->z = 0.0;
}


bool IsOut()
{
    for(unsigned int i = 0; i<numberofions; i++)
    {
        if(ions[i].bOut.VSumAb() == 0)
        {
            if(ions[i].r.x * ions[i].r.x + ions[i].r.y * ions[i].r.y > 0.003999*0.003999 )
            {
                ions[i].bOut.x = 1;
                outnum = outnum + 1;
                continue;
            }

            if(fabs(ions[i].r.x) > 0.003999)
            {
                ions[i].bOut.x = 1;
                outnum = outnum + 1;
                continue;
            }
            if(fabs(ions[i].r.y) > 0.003999)
            {
                ions[i].bOut.y = 1;
                outnum = outnum + 1;
                continue;
            }
            if(fabs(ions[i].r.z) > 999999)
            {
                ions[i].bOut.z = 1;
                outnum = outnum + 1;
                continue;
            }
        }
    }
    if(outnum == numberofions)
    {
        return 1;
    }
    return 0;
}

