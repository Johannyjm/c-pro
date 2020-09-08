#include <iostream>
#include <vector>
#include <string>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    int n = s.size();

    ll res = 0; // damage
    ll kub = 5;
    ll combos = 0;
    vector<ll> kub_ret(n+10, 0);
    vector<ll> combo_inc(n+10, 0);
    vector<bool> iswait(n+10, false);
    for(int i = 0; i < n; ++i){
        kub += kub_ret[i];
        combos += combo_inc[i];
        
        if(iswait[i]) continue;

        if(s[i] == 'N'){
            if(kub > 0){
                res += 10 + (combos/10);
                combo_inc[i+2] += 1;
                --kub;
                kub_ret[i+7] += 1;
            }
        }
        if(s[i] == 'C'){
            if(kub > 2){
                res += 50 + 5*(combos/10);
                combo_inc[i+4] += 1;
                kub -= 3;
                kub_ret[i+9] += 3;
                iswait[i+1] = true;
                iswait[i+2] = true;
            }
        }
    }

    cout << res << endl;

    return 0;

}
