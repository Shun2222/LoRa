#include <iostream>
#include <cmath>
using namespace std;

double toRadian(double degree)
{
    return degree/180.0 * M_PI;
}

double fromRadian(double radian)
{
    return radian/M_PI * 180.0;
}

double normalizeAbsolute(double deg)
{
    // NaNは足しても引いてもNaNのままなので無限ループに陥る
    if (std::isnan(deg))
    {
        std::cout << "Error: Failed to normalize degree! (deg=" << deg << ')' << std::endl;
        return deg;
    }
    // 値の指数が大きいと360を足しても引いても変わらなくて無限ループに陥る
    if (deg > 1e9 || deg < -1e9)
    {
        std::cout << "Error: Failed to normalize degree! (deg=" << deg << ')' << std::endl;
        return 0.0;
    }
    while (deg >= 180.0)
    {
        deg -= 360.0;
    }
    while (deg < -180.0)
    {
        deg += 360.0;
    }
    return deg;
}

double azimuthFrom(double lat, double lng, double otherLat, double otherLng)
{
    double latRadian = toRadian(lat);
    double lngRadian = toRadian(lng);
    double otherLatRadian = toRadian(otherLat);
    double otherLngRadian = toRadian(otherLng);
    double lngRadianDiff = otherLngRadian - lngRadian;
    
    double y = std::sin(lngRadianDiff);
    double x = std::cos(latRadian) * std::tan(otherLatRadian) - std::sin(latRadian) * std::cos(lngRadianDiff);
    double azimuth = normalizeAbsolute(fromRadian(atan2(y, x))+180);
    cout<<"x,y="<<x<<","<<y<<endl;
    cout<<"azimuth="<<azimuth<<endl;
    return azimuth;
}

double distanceFrom(double lat, double lng, double otherLat, double otherLng)
{
    // 地球の長半径
    constexpr double EARTH_RADIUS = 6378137.0;

    // ラジアンへ変換
    const double latRadian = toRadian(lat); // 緯度
    const double lngRadian = toRadian(lng); // 経度
    const double otherLatRadian = toRadian(otherLat);
    const double otherLngRadian = toRadian(otherLng);

    // 経度の差分
    const double lngRadianDiff = otherLngRadian - lngRadian;

    return EARTH_RADIUS * std::acos(
        std::sin(latRadian) * std::sin(otherLatRadian) +
        std::cos(latRadian) * std::cos(otherLatRadian) * std::cos(lngRadianDiff)
    );
}

int main()
{
    double lat, lng, otherLat, otherLng;
    cout<<"Start lat"<<endl;
    cin>>lat;
    cout<<"Start lng"<<endl;
    cin>>lng;
    cout<<"Target lat"<<endl;
    cin>>otherLat;
    cout<<"Target lng"<<endl;
    cin>>otherLng;
    
    double azimuth = toRadian(azimuthFrom(lat, lng, otherLat, otherLng)+90);
    double distance = distanceFrom(lat, lng, otherLat, otherLng);
    double x = distance * std::cos(azimuth); 
OB    double y = distance * std::sin(azimuth);
    cout<<"dist"<<distance<<endl;
    cout<<"x,y="<<x<<","<<y<<endl;
OB    cout<<"azimuth"<<azimuth<<endl;
    return 0;
}
