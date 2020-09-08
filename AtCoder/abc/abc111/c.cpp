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

    int bucket[100001] = {0};
    rep(i, n){
        int v;
        cin >> v;

        ++bucket[v];
    }

    sort(bucket, bucket+100001, greater<int>());

    if(bucket[1] == 0) cout << bucket[0] / 2 << endl;
    else if(bucket[2] == 0) cout << 0 << endl;
    else{
        int res = 0;
        for(int i = 2; i < 100001; ++i){
            if(bucket[i] == 0) break;
            res += bucket[i];
        }
        cout << res << endl;
    }
}