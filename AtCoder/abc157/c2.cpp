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

    vector<int> s(m), c(m);
    rep(i, m) cin >> s[i] >> c[i];

    if(n==1){
        int res = -1;
        rep(i, m){
            if(s[i] != 1){
                cout << -1 << endl;
                return 0;
            }
            if(!(res == -1 || res == c[i])){
                cout << -1 << endl;
                return 0;
            }
        }
    }

    if(n==2){
        for(int i = 10; i < 100; ++i){
            int one = i/10;
            int two = i%10;

            bool flg = true;
            rep(j, m){
                if(s[j] == 1){
                    if(one != c[j]){
                        flg = false;
                        break;
                    }
                }
                if(s[j] == 2){
                    if(two != c[j]){
                        flg = false;
                        break;
                    }
                }
            }
            if(flg){
                cout << i << endl;
                return 0;
            }
        }
    }

    if(n==3){
        for(int i = 100; i < 1000; ++i){
            int one = i/100;
            int two = i%100/10;
            int three = i%10;

            bool flg = true;
            rep(j, m){
                if(s[j] == 1){
                    if(one != c[j]){
                        flg = false;
                        break;
                    }
                }
                if(s[j] == 2){
                    if(two != c[j]){
                        flg = false;
                        break;
                    }
                }
                if(s[j] == 3){
                    if(three != c[j]){
                        flg = false;
                        break;
                    }
                }
            }

            if(flg){
                cout << i << endl;
                return 0;
            }
        }
    }

    cout << -1 << endl;

    return 0;
}