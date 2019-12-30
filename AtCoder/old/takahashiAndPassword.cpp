#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s;
    int k;
    cin >> s >> k;

    if(k>s.length()){
        cout << 0 << endl;
        return 0;
    }

    map<string, int> mp;
    for(int i = 0; i < s.length()-k+1; ++i){
        string cand_key = s.substr(i, k);
        ++mp[cand_key];
    }

    cout << mp.size() << endl;
}