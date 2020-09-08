#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> b(n);
    rep(i, n) cin >> b[i];

    while(1){
        vector<int> stack;
        int mx = -1;
        rep(i, b.size()){
            if(i+1 > b[i]) stack.push_back(i);
        }
    }

    return 0;
}