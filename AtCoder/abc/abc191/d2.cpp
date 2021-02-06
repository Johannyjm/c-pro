#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;

int mceil(double d){
    int ret = ceil(d);
    if(double(ret-1) <= d && d <= double(ret)) return ret;
    if(double(ret-2) <= d && d <= double(ret-1)) return ret-1;
    if(double(ret) <= d && d <= double(ret+1)) return ret+1;
    
}

int mfloor(double d){
    int ret = floor(d);
    if(double(ret) <= d && d <= double(ret+1)) return ret;
    if(double(ret-1) <= d && d <= double(ret)) return ret-1;
    if(double(ret+1) <= d && d <= double(ret+2)) return ret+1;
}

int main(void){

double a,b,r,p;
int start,end,top,bottom,i,j;
long long num;

num=0;

// printf("a b r =");
// scanf("%lf %lf %lf",&a,&b,&r);
cin >> a >> b >> r;

start = mceil(a-r);
end = mfloor(a+r);

for(i=start;i<=end;i++){

p = sqrt(pow(r,2)-pow((a-(double)i),2));

// cf(b,p,&bottom,&top);
bottom = mceil(b-p);
top = mfloor(b+p);

for(j=bottom;j<=top;j++){
num = num + 1;
}

}
// printf("中心:(%lf,%lf) 半径:%lf 格子点の数: %d \n",a,b,r,num);
cout << num << endl;

return 0;
}