#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<int> c(n);
    rep(i, n) c[i] = i+1;

    int now = 0;
    rep(i, m){
        int disk;
        cin >> disk;
        if(now == disk) continue;

        rep(j, n){
            if(c[j] == disk){
                c[j] = now;
                now = disk;
                break;
            }
        }
    }

    rep(i, n) cout << c[i] << endl;


    return 0;
}