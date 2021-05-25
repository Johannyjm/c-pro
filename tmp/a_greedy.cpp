#include <iostream>
#include <vector>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    int res = 0;
    for(int i = 0; i < n; ++i){
        int now = a[i];
        int cnt = 1;
        for(int j = i+1; j < n; ++j){
            if(a[j] == now + k){
                ++cnt;
                now += k;
            }
        }

        res = max(res, cnt);
    }

    cout << res << endl;

    return 0;    
}