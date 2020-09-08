#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int s2i(string s){
    int d = s.size();
    int ret = 0;
    rep(i, s.size()){
        ret += (s[i] - '0') * pow(10, d-1);
        --d;
    }

    return ret;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;

    vector<int> month = {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int y = s2i(s.substr(0, 4));
    int m = s2i(s.substr(5, 2));
    int d = s2i(s.substr(8, 2));

    cout << y << " " << m << " " << d << endl;

    while(1){
        if(y%m==0 && (y/m)%d==0){
            string M, D;
            if(m<10) M = "0";
            else  M = "";
            if(d<10) D = "0";
            else D = "";
            cout << y << '/' << M << m << '/' << D << d << endl;
            return 0;
        }

        if(m==12 && d==31){
            cout << ++y << "/01/01" << endl;
            return 0;
        }

        if(d==month[m]){
            if(m==2 && (y%400==0 || (y%4==0 && y%100!=0))){
                if(y%2==0 && (y/2)%29==0){
                    cout << y << "/02/29" << endl;
                    return 0;
                }
                else{
                    m = 3;
                    d = 1;
                }
            }
            
            else {
                ++m;
                d = 1;
            }
        }
        
        ++d;
    }

    return 0;
}