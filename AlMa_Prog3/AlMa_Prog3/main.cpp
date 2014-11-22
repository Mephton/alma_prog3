#include<cstdio>
#include<cmath>
typedef long double ld;ld f(ld x){return((1+x)*log(1+x)-x);}main(){for(;;){ld y,u=1e50,l=1/u,m=scanf("%Lf",&y);for(;m=l/2+u/2,u-l>l/1e10;f(m)<y?l=m:u=m);printf("%.50Lf %.50Lf -> %.50Lf\n",l,u,f(m));}}