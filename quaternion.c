#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
void euler_quaternion(double yaw,double roll,double pitch,double quaternion[])//converts eulers coords to quaternion using a formula which i got from internet
{
//necessary conversions
    double y1=cos(yaw/2.0);
    double y2=sin(yaw/2.0);
    double r1=cos(roll/2.0);
    double r2=sin(roll/2.0);
    double p1=cos(pitch/2.0);
    double p2=sin(pitch/2.0);
    //formulae
    quaternion[0]=r1*p1*y1+r2*p2*y2;
    quaternion[1]=r2*p1*y1-r1*p2*y2;
    quaternion[2]=r1*p2*y1+r2*p1*y2;
    quaternion[3]=r1*p1*y2-r2*p2*y1;
}
int main()
{
    double yaw,pitch,roll;
    scanf("%lf %lf %lf",&yaw ,&roll ,&pitch);
//coverting input (degrees) to radians
    yaw=yaw*M_PI/180.0;
    roll=roll*M_PI/180.0;
    pitch=pitch*M_PI/180.0;
    double quaternion[4];//array to store 4 number system coords
    euler_quaternion(yaw,pitch,roll,quaternion);
    printf("Martian Quaternion: [%.4f, %.4f, %.4f, %.4f]\n",
          quaternion[0], quaternion[1], quaternion[2], quaternion[3]);
}
