#ifndef SRC_HEADERS_INITDYN_HPP_
#define SRC_HEADERS_INITDYN_HPP_

void InitDyn();

void CalcInfo();
double q2fac(double qu,double au);

void Init_r();
void Init_v();
void Init_a();

void GenRand(long long randseed, double* randval, unsigned int num,double minval,double maxval);
void GenGauss(long long randseed, double* randval, unsigned int num,double meanval,double sigmaval);
#endif