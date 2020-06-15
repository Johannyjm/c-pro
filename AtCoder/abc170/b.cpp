#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int x, y;
    cin >> x >> y;

    int t2 = 4*x - y;
    if(t2<0 || t2%2==1){
        cout << "No" << endl;
        return 0;
    }

    int t = t2/2;
    int k = x - t;

    if(k>=0) cout << "Yes" << endl;
    else cout << "No" << endl;


    return 0;
}