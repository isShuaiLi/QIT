#ifndef SRC_HEADERS_MATRIX_HPP_
#define SRC_HEADERS_MATRIX_HPP_

#include <headers/vector.hpp>
class Mat
{
public:
    double m00;
    double m01;
    double m02;
    double m10;
    double m11;
    double m12;
    double m20;
    double m21;
    double m22;

    Mat();
    ~Mat();

    //vec MVMul(const vec &v1);
    vec operator* (const vec &v);
    void Zero();
};


#endif