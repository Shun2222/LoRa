#include <iostream>
#include <cmath>
int main(void)
{
    // graund param
    // double rssi0 = -17.1;
    // double n = 3.65;
    // desert param (first day)
    double rssi0=-61.2;
    double n=2.29

    double rssi;
    double azimuth;
    std::cout<<"rssi:";
    std::cin>>rssi;
    std::cout<<"azimuth:";
    std::cin>>azimuth;

    double dist = (rssi0-rssi)/(n*10);
    dist = std::pow(10, dist);
    std::cout<<"dist:"<<dist<<std::endl;

    double x = dist*std::cos((azimuth/180.0) * M_PI);
    double y = dist*std::sin((azimuth/180.0) * M_PI);
    std::cout<<"(x,y) = ("<<x<<","<<y<<")"<<std::endl;
}
