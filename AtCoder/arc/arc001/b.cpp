#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int a, b;
    cin >> a >> b;

    const int INF = 1001001001;
    vector<int> cnt(100, INF);

    cnt[a] = 0;
    const int d[] = {10, -10, 5, -5, 1, -1};
    
    rep(_, abs(a-b)+1){
        rep(now, 100){
            rep(i, 6){
                int prev = now - d[i];
                if(prev < 0) continue;

                cnt[now] = min(cnt[now], cnt[prev]+1);
            }
        }
    }

    cout << cnt[b] << endl;


    return 0;
}