#ifndef ROBOTALGORITHM_H
#define ROBOTALGORITHM_H
#include <math.h>
struct RobotPose{
    double x{0};
    double y{0};
    double theta{0};
};
// Degrees to radians
inline double deg2rad(double x){
    return M_PI*x/180.0;
}
// Radians to degrees
inline double rad2deg(double x ){
    return 180.0*x/M_PI;
}
#endif // ROBOTALGORITHM_H
