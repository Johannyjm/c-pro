#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    vector<int> x(5);
    rep(i, 5) {
        cin >> x[i];
        if(x[i] == 0){
            cout << i+1 << endl;
            return 0;
        }
    }


    return 0;
}