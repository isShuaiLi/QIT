#ifndef SRC_HEADERS_COARSE_HPP_
#define SRC_HEADERS_COARSE_HPP_
#include <headers/vector.hpp>

class coarse
{
public:
    
    // trans
    vec r,v,a; //1 point for center
    vec bOut;

    double Ek;
    double Ep;

    coarse();
    ~coarse();

    //Energy
    double CalcEk();
    double CalcEp();

};


#endif 

