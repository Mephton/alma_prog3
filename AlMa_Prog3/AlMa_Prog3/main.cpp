#include<cstdio>
#include<cmath>
typedef long double d;d f(d x){return((1+x)*log(1+x)-x);}main(){for(;;)for(d y,u=1e50,l=1/u,m=scanf("%Lf",&y);m=l/2+u/2,u-l>l/1e10||!printf("%.50Lf %.50Lf -> %.50Lf\n",l,u,f(m));f(m)<y?l=m:u=m);}