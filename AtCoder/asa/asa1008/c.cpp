#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> a(n);
    int sm = 0;
    rep(i, n){
        cin >> a[i];
        if(i == 0) sm += abs(a[i]);
        if(i > 0) sm += abs(a[i]-a[i-1]);
    }
    sm += abs(a.back());
    a.push_back(0);

    rep(i, n){
        if(i==0){
            if((0<=a[i]&&a[i]<=a[i+1]) || (0>=a[i]&&a[i]>=a[i+1])){
                cout << sm << endl;
            }
            else{
                cout << sm-(abs(0-a[i])+abs(a[i]-a[i+1])-abs(0-a[i+1])) << endl;
            }
        }
        else{
            if((a[i-1]<=a[i]&&a[i]<=a[i+1]) || (a[i-1]>=a[i]&&a[i]>=a[i+1])){
                cout << sm << endl;
            }
            else{
                cout << sm-(abs(a[i-1]-a[i])+abs(a[i]-a[i+1])-abs(a[i-1]-a[i+1])) << endl;
            }
        }
    }


    return 0;
}