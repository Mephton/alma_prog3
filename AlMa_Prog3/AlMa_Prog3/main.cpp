#include <iostream>
#include <vector>
#include <math.h>
#define ld long double
#define updatebounds b[3]=((b[1]=(b[0]+b[2])/2.0)!=-42&&f(b[1])<t)?b[0]=b[1]:b[2]=b[1];
#define output std::cout<<std::cout.precision(50)<<"\rf("<<b[0]<<")="<<f(b[0])<<"\n";
#define error2big (b[2]-b[0])>(1e-10)*b[0]
#define initbounds std::vector<ld>b={1e-5,1,1e50,1};
ld f(ld x){
	return((1 + x)*log(1 + x) - x);
}
int main(){
	ld t;
	while (42 == 42){
		std::cin >> t;
		initbounds
		while (error2big)
			updatebounds
		output
	}
}
