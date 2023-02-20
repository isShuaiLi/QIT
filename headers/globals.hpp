
#ifndef SRC_HEADERS_GLOBALS_HPP_
#define SRC_HEADERS_GLOBALS_HPP_
#include <headers/coarse.hpp>
#include <headers/vector.hpp>

#include <string>
using namespace std;

//File
extern std::string filename_trans;

//init
extern bool use_randv;
extern vec initv;

//
extern coarse *ions;
extern long long numberofions ;

extern double radiusofions;
extern double mass_Da ;
extern double mass_kg ;
extern double q_net ;
extern double q_C   ;

// step
extern long long nstep_trans;
extern double dt_trans;
extern long long nstep_trans_save;
extern long long nstep_trans_show;


//ele
extern bool bUeff;
extern double Urf ;
extern double frf;
extern double Uac;
extern double fac;

extern double damp1 ;
extern double damp2 ;

//T
extern double temperature;

// seed
extern long long seed;


extern double time_now;
extern int outnum;

#endif