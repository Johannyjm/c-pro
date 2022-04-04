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

    for(int i = 0; i < k; ++i){
        int minl = s[i];
        int maxr = s[i];

        for(int j = 0; j < d; ++j){
            if(maxr < l[j] || r[j] < minl) continue;

            minl = min(minl, l[j]);
            maxr = max(maxr, r[j]);

            if(minl <= t[i] && t[i] <= maxr){
                cout << j+1 << "\n";
                break;
            }
        }
    }

    return 0;
}
