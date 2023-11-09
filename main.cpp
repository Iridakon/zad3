#include <iostream>
#include "math.h"
#include "windows.h"
double f(double x)
{
    return log(x)/100;
}
double df(double x)
{
    return 1.0/x/100;
}

double Del (double a,double b,double e,double N)//метод половинных отрезков
{
    int n=0;
    double x1=a,x2=b,y;
    while ((abs(x1-x2)>e))
    {
        if (n>N){ printf("Превышено число итераций \n"); return NAN;}
        y=(x1+x2)/2;
        if(f(x1)*f(y)<0) x2=y;
        else x1=y;
        n++;
    }
    printf("Деление пополам \nотв: %20.15f итераций: %i точное значение: %16.15f \n",y,n,f(y));
    return y;
}
double Nut (double a,double b,double e,double N)//метод Ньтона
{
    double x0,x1;
    int n=0,d2f;
    double p=(a+b)/2;
    if (f(p)>(f(p+p/2)+f(p-p/2))/2.0) d2f=-1;
    else d2f=1;
    if(f(a)*d2f>0)
        x0=a;
    else
        x0=b;
    do
    {
        x1=x0;
        x0= x1 - f(x1) / df(x1);
        //printf("%f %f\n",x0,x1);
        n++;
        if (n>N){ printf("Превышено число итераций \n");
            return NAN;}
    }
    while (abs(f(x0)) >= e*df(x0-d2f*e));
    printf("Метод Ньютона \nотв: %20.15f итераций: %i точное значение: %16.15f \n",x0,n,f(x0));
    return x0;
}
int main() {
    SetConsoleOutputCP(CP_UTF8);
    double a=0.01,b=1000,e=1.0e-4;
    double s=Del(a,b,e,1000);
    double l=Nut(a,b,e,1000);
    //printf("Орезки %f\n",s);
    //printf("Ньютон %f\n",l);

    return 0;
}
