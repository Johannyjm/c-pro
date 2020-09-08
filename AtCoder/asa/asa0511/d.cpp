#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<int> stack;
    vector<int> a(m);
    rep(i, m){
        cin >> a[i];
        stack.push_back(a[i]);
    }

    map<int, int> seen;
    for(int i = m-1; i >= 0; --i){
        if(seen[stack[i]] == 0) {
            cout << stack[i] << endl;
            ++seen[stack[i]];
        }
    }

    for(int i = 1; i <= n; ++i){
        if(seen[i] == 0) cout << i << endl;
    }

    return 0;
}