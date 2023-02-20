/*

*/


#include <iostream>
#include <headers/globals.hpp>
#include <headers/coarse.hpp>
#include <headers/fhandle.hpp>
#include <headers/initdyn.hpp>
#include <headers/transdyn.hpp>
#include <headers/print.hpp>

int main (int argc, char **argv)
{
    ftask(argv[1]);

    InitDyn();

    showtrans(0);
    savetrans(0);    
    for(long long istep_trans = 0; istep_trans < nstep_trans; istep_trans ++)
    {
        transdyn();
        time_now = time_now +  dt_trans; 
        showtrans(istep_trans+1);
        savetrans2(istep_trans+1); 

        //Out?
        if (IsOut())
        {
            cout<<"================ All Out ==============="<<endl;
            cout<<"Time_Now = "<<time_now<<endl;
            cout<<"saved frame = "<<istep_trans<<"/"<<nstep_trans_save<<"="<<istep_trans/nstep_trans_save<<endl;
            break;
        }

    }
    
    PrintSummary();

    delete [] ions;

    return 0;
}


