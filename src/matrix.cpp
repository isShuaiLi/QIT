#include <headers/matrix.hpp>

Mat::Mat()
{

}
Mat::~Mat()
{

}

vec Mat::operator* (const vec& v)
{
    vec temp;
    temp.x = m00 * v.x + m01*v.y + m02*v.z;
    temp.y = m10 * v.x + m11*v.y + m12*v.z; 
    temp.z = m20 * v.x + m21*v.y + m22*v.z; 
    return temp;
}

void Mat::Zero()
{
    m00 = 0.0;
    m01 = 0.0;
    m02 = 0.0;
    m10 = 0.0;
    m11 = 0.0;
    m12 = 0.0;
    m20 = 0.0;
    m21 = 0.0;
    m22 = 0.0;
}