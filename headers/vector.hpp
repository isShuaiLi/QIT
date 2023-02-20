#ifndef SRC_HEADERS_VECTOR_HPP_
#define SRC_HEADERS_VECTOR_HPP_


class vec
{
public:
    double x;
    double y;
    double z;

    vec();
    vec(double xset,double yset,double zset);
    

    double Len();
    double Len2();
    void VZero();
    void VNorm();
    double VSumAb();
    void VSet(double xset,double yset,double zset);
    
    vec operator+ (const vec& v);
    vec operator- (const vec& v);
    vec operator* (const vec& v);
    vec operator* (const double& v);    
    ~vec();
};


#endif