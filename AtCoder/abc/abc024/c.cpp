#include <iostream>
#include <vector>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, d, k;
    cin >> n >> d >> k;
    vector<int> l(d), r(d), s(k), t(k);
    for(int i = 0; i < d; ++i) cin >> l[i] >> r[i];
    for(int i = 0; i < k; ++i) cin >> s[i] >> t[i];
    
    vector<int> res(k);
    for(int kk = 0; kk < k; ++kk){
        int now = s[kk];
        int goal = t[kk];

        for(int i = 0; i < d; ++i){
            if(!(now >= l[i] && now <= r[i])) continue;
            if(goal >= l[i] && goal <= r[i]){
                res[kk] = i+1;
                break;
            }
            if(now < goal) now = r[i];
            if(now > goal) now = l[i];
        }
    }

    for(int i = 0; i < k; ++i) cout << res[i] << endl;

    return 0;
}
