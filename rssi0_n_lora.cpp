#include <iostream>
#include <cmath>
int main(void)
{
    double rssi1;
    double dist1;
    std::cout<<"rssi1:";
    std::cin>>rssi1;
    std::cout<<"dist1:";
    std::cin>>dist1;
    if(rssi1>0)
    {
        std::cout<<"rssi>0! rssi should be minus"<<std::endl;
        return 0;
    }

    double rssi2;
    double dist2;
    std::cout<<"rssi2:";
    std::cin>>rssi2;
    std::cout<<"dist2:";
    std::cin>>dist2;
    if(rssi2>0)
    {
        std::cout<<"rssi>0! rssi should be minus"<<std::endl;
        return 0;
    }
    
    double n = (rssi2-rssi1)/(10*std::log10(dist1/dist2));
    double rssi0 = rssi1 + 10*n*std::log10(dist1);
    if(n<2 || n>6)
    {
        std::cout<<"[WARNING] n is bad. n is should be 2<n<6."<<std::endl;
        std::cout<<"値が正しくない可能性があるので、確認してください."<<std::endl;
    }
    if(rssi0>0)
    {
        std::cout<<"[WARNING] rssi0 is bad. rssi should be minus."<<std::endl;
        std::cout<<"値が間違っています．確認、もしくは、測定し直しをしてください."<<std::endl;
    }
    std::cout<<"n="<<n<<std::endl;
    std::cout<<"rssi0="<<rssi0<<std::endl;
    return 0;
}
