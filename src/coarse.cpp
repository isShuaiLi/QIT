#include <headers/coarse.hpp>
#include <headers/globals.hpp>
#include <headers/vector.hpp>
#include <headers/constants.hpp>
#include <cmath>
coarse::coarse()
{
    bOut.VSet(0.0,0.0,0.0);
}
coarse::~coarse()
{

}


double coarse::CalcEk()
{
    Ek = 0.5 * mass_kg * v.Len2();
    return Ek;
}

double coarse::CalcEp()
{
    double Urft;
    double r0 = 0.004;
    Urft = 2*Urf* cos(2*pi*frf * time_now);
    Ep = Urft/(2 * r0 * r0) * ((r.x)*(r.x) - (r.y)*(r.y)) * q_C;
    return Ep;
}