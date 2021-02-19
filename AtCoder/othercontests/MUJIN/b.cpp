#include <iostream>
#include <iomanip>
using namespace std;
const long double PI = 3.141592653589793238462643383279;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    long double a, b, c;
    cin >> a >> b >> c;
    long double r = a + b + c;
    
    long double res = 0;
    long double sr;
    if(a > b+c){
        sr = a - b - c;
        res = r*r*PI - sr*sr*PI;
    }
    else if(b > a+c){
        sr = b - a - c;
        res = r*r*PI - sr*sr*PI;
    }
    else if(c > a+b){
        sr = c - a - b;
        res = r*r*PI - sr*sr*PI;
    }
    else res = r*r*PI;
    
    cout << setprecision(20);
    cout << res << endl;
    

    return 0;
}
