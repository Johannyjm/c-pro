#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;
using ll = long long;

ll s2i(string s){
    ll ret = 0;
    int n = s.size();
    ll offset = 10000;
    for(int i = 0; i < n; ++i){
        if(s[i] == '.'){
            offset = pow(10, 5-n+i);
            continue;
        }
        ret *= 10;
        ret += (s[i] - '0');
    }

    return ret * offset;
}

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

// double a,b,r,p;
ll start,end,top,bottom,i,j;
long long num;

num=0;

// printf("a b r =");
// scanf("%lf %lf %lf",&a,&b,&r);
// cin >> a >> b >> r;
string X, Y, R;
cin >> X >> Y >> R;

ll x = s2i(X);
ll y = s2i(Y);
ll r = s2i(R);

start = ((x-r)+10000-1)/10000;
end = (x+r)/10000;

for(i=start;i<=end;i++){

double p = sqrt(pow(r,2)-pow((x-i*10000),2));

// cf(b,p,&bottom,&top);
bottom = mceil((y-p)/10000);
top = mfloor((y+p)/10000);

for(j=bottom;j<=top;j++){
num = num + 1;
}

// cout << i << " " << top << " " << bottom << endl;
}
// printf("中心:(%lf,%lf) 半径:%lf 格子点の数: %d \n",a,b,r,num);
cout << num << endl;

return 0;
}