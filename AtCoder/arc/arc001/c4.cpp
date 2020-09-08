#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

bool check(vector<int> loc){
    rep(i, 8){
        rep(j, 8){
            if(i >= j) continue;
            if(abs(loc[j] - loc[i]) == j-i) return false;
        }
    }

    return true;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    vector<int> loc(8, -1);
    rep(i, 8){
        string s;
        cin >> s;
        rep(j, 8){
            if(s[j] == 'Q') loc[i] = j;
        }
    }

    vector<int> cand(8);
    rep(i, 8) cand[i] = i;
    
    do{
        bool con = false;
        rep(i, 8){
            if(loc[i] == -1) continue;
            if(loc[i] != cand[i]) con = true;
        }

        if(!con){
            if(check(cand)){
                rep(i, 8){
                    rep(j, 8){
                        if(cand[i] == j) cout << 'Q';
                        else cout << '.';
                    }
                    cout << endl;
                }
                return 0;
            }
        }
    } while(next_permutation(cand.begin(), cand.end()));

    cout << "No Answer" << endl;;

    return 0;
}