#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, k;
    cin >> n >> k;

    vector<int> a(n);
    rep(i, n) cin >> a[i];

    vector<int> s;
    vector<int> ord(n+1, -1);
    int c = 1;
    int l = 0;
    {
        int v = 1;
        while(ord[v] == -1){
            ord[v] = s.size();
            s.push_back(v);
            v = a[v-1];
        }
        c = s.size() - ord[v];
        l = ord[v];
    }

    if(k < l) cout << s[k] << endl;
    else{
        k -= l;
        k %= c;
        cout << s[l+k] << endl;
    }


    return 0;
}