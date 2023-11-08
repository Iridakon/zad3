#include <iostream>
#include "math.h"
double f(double x)
{
    return log(x)-0.5;
}
double df(double x)
{
    return 1.0/x;
}
double df2(double x)
{
    return -1.0/(x*x);
}
double Del (double a,double b,double e,double N)//метод половинных отрезков
{
    int n=0;
    double x1=a,x2=b,y;
    while ((abs(x1-x2)>e))
    {
        if (n>N){ printf("NaN ");
        return NAN;}
        y=(x1+x2)/2;
        if(f(x1)*f(y)<0) x2=y;
        else x1=y;
        n++;
    }
    return y;
}
double Nut (double a,double b,double e,double N)//метод Ньтона
{
    double x0,x1;

    if(f(a)*df2(a)>0)
        x0=a;
    else
        x0=b;
    do
    {
        x1=x0;
        x0= x1 - f(x1) / df(x1);
        printf("%f %f\n",x0,x1);
        //n++;
    }
    while (abs(f(x0)) >= e);
    return x0;
}
int main() {
    double a=0.00001,b=10;
    double s=Del(a,b,0.001,1000);
    double l=Nut(a,b,0.001,1000);
    printf("Otr %f\n",s);
    printf("Nut %f\n",l);

    return 0;
}
