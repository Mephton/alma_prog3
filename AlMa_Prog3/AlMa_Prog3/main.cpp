#include <iostream>
#include <vector>
#include <math.h>
long double f(long double x){return((1+x)*log(1+x)-x);} int main(){long double t=42;std::cin>>t; std::vector<long double>b={1e-5,1,1e50,1}; while((b[2]-b[0])>(1e-10)*b[0]){b[3]=((b[1]=(b[0] + b[2])/2.0)!=-42&&f(b[1])<t)?b[0]=b[1]:b[2]=b[1];}std::cout<<std::cout.precision(50)<<"\rf("<<b[0]<<")="<<f(b[0])<<"\n"; std::cin>>t;}
