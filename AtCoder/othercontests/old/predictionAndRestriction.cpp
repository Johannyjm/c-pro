#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    int r, s, p;
    cin >> r >> s >> p;
    string t;
    cin >> t;
    char hand[t.length()];

    int res = 0;
    rep(i, t.length()){
        if(i<k){
            if(t[i] == 's') {
                res += r;
                hand[i] = 'r';
            }
            if(t[i] == 'p') {
                res += s;
                hand[i] = 's';
            }
            if(t[i] == 'r') {
                res += p;
                hand[i] = 'p';
            }
        }
        else{
            if(t[i] == 's') {
                if(hand[i-k] != 'r'){
                    res += r;
                    hand[i] = 'r';
                }
                else hand[i] = '?';
            }
            if(t[i] == 'p') {
                if(hand[i-k] != 's'){
                    res += s;
                    hand[i] = 's';
                }
                else hand[i] = '?';
            }
            if(t[i] == 'r') {
                if(hand[i-k] != 'p'){
                    res += p;
                    hand[i] = 'p';
                }
                else hand[i] = '?';
            }            
        }
    }
    cout << res << endl;
    return 0;

}