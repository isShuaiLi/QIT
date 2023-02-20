#include <headers/print.hpp>
#include <headers/globals.hpp>
#include <fstream>
#include <iostream>
#include <cmath>

using namespace std;


void savetrans(long long istep)
{
    if(istep % nstep_trans_save == 0)
    {
        ofstream transfile;
        unsigned int i;
        transfile.precision(10);

        transfile.open (filename_trans,ios::app);
        transfile <<"\t"<<numberofions<<endl;
        transfile << istep << " / " << nstep_trans <<"\t\t" << time_now <<endl;
        for (i = 0; i< numberofions; i++)
        {
            transfile<< "C" << "\t\t" << ions[i].r.x << "\t\t" << ions[i].r.y << "\t\t" << ions[i].r.z 
                            << "\t\t" << ions[i].v.x << "\t\t" << ions[i].v.y << "\t\t" << ions[i].v.z
                            << "\t\t" << ions[i].a.x << "\t\t" << ions[i].a.y << "\t\t" << ions[i].a.z <<endl;
        }

        transfile.close();
    }
    else{

    }
}

void savetrans2(long long istep)
{
    if(istep % nstep_trans_save == 0)
    {
        ofstream transfile;
        unsigned int i;
        transfile.precision(10);

        transfile.open (filename_trans,ios::app);
        for (i = 0; i< numberofions; i++)
        {
            transfile<< time_now << "\t" << ions[i].r.x << "\t" << ions[i].r.y << "\t" << ions[i].r.z 
                            << "\t" << ions[i].v.x << "\t" << ions[i].v.y << "\t" << ions[i].v.z
                            << "\t" << ions[i].a.x << "\t" << ions[i].a.y << "\t" << ions[i].a.z <<endl;
        }

        transfile.close();
    }
    else{

    }
}

void showtrans(long long istep)
{   
    if(istep % nstep_trans_show == 0)
    {
        double totEnergy = 0.0;
        for(unsigned int i = 0; i< numberofions; i++)
        {
            totEnergy = totEnergy + ions[i].CalcEk() + ions[i].CalcEp();
        }
        
        cout<< istep << " / " << nstep_trans <<"\tIons clouds motion step\t" <<"Ek + Ep = "<<totEnergy<<" Outnum = "<<outnum<<"/"<<numberofions<<endl;
    }
    else{

    }
}

void PrintSummary()
{
    cout <<"===============END============"<<endl;
    cout <<"SimTime = "<<nstep_trans * dt_trans<<" [s]"<<endl;
}
