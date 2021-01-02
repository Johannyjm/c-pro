#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    int h = n/3600;
    int m = n%3600/60;
    int s = n%60;

    string res1 = "0";
    if(h < 10) res1 += to_string(h);
    else res1 = to_string(h);
    string res2 = "0";
    if(m < 10) res2 += to_string(m);
    else res2 = to_string(m);
    string res3 = "0";
    if(s < 10) res3 += to_string(s);
    else res3 = to_string(s);



    cout << res1 << ":" << res2 << ":" << res3 << endl;

    return 0;
}