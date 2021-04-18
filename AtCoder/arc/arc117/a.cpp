#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int a, b;
    cin >> a >> b;

    vector<int> res1, res2;
    if(a == b){
        rep1(i, a+1){
            res1.push_back(i);
            res2.push_back(-i);
        }
    }

    if(a > b){
        int sm = 0;
        rep1(i, a+1){
            res1.push_back(i);
            sm += i;
        }
        int sm2 = 0;
        rep1(i, b){
            res2.push_back(-i);
            sm2 += i;
        }
        res2.push_back(-(sm-sm2));
    }

    if(b > a){
        int sm = 0;
        rep1(i, b+1){
            res2.push_back(-i);
            sm += i;
        }
        int sm2 = 0;
        rep1(i, a){
            res1.push_back(i);
            sm2 += i;
        }
        res1.push_back(sm-sm2);
    }

    for(auto e: res1) cout << e << " ";
    for(auto e: res2) cout << e << " ";
    cout << endl;

    return 0;
}