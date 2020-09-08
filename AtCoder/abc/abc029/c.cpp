#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;



int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    char words[] = {'a', 'b', 'c'};
    int cnt = 0;

    rep(i, 3){
        rep(j, 3){
            rep(k, 3){
                rep(l, 3){
                    rep(m, 3){
                        rep(o, 3){
                            rep(p, 3){
                                rep(q, 3){
                                    ++cnt;
                                    if(n>7) cout << words[i];
                                    if(n>6) cout << words[j];
                                    if(n>5) cout << words[k];
                                    if(n>4) cout << words[l];
                                    if(n>3) cout << words[m];
                                    if(n>2) cout << words[o];
                                    if(n>1) cout << words[p];
                                    cout << words[q] << endl;
                                    if(cnt >= pow(3, n)){
                                        return 0;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}