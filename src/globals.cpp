#include <headers/globals.hpp>
#include <string>
#include <headers/vector.hpp>


// file
std::string filename_trans = "./result/trans.xyz";



//init
bool use_randv = 1;
vec initv;

// coarse
coarse* ions;
long long numberofions = 0;
double radiusofions = 0;
double mass_Da = 0;
double mass_kg = 0;
double q_net   = 0;
double q_C     = 0;

// step
long long nstep_trans = 0;
double dt_trans = 0;
long long nstep_trans_save = 0;
long long nstep_trans_show = 0;



//RF
bool bUeff = 0;
double Urf;
double frf;
double Uac;
double fac;

//
double damp1 = 0.;
double damp2 = 0.;

//T
double temperature = 0;

// seed
long long seed = 100000;



double time_now = 0;
int outnum = 0;
