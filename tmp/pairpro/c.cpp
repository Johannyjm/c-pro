#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    unordered_map<string, ll> count;
    for(int i = 0; i < n; ++i){
        string s;
        cin >> s;

        sort(s.begin(), s.end());

        ++count[s];
    }

    ll res = 0;
    for(auto k: count){
        ll val = k.second;

        res += val * (val - 1) / 2;
    }

    cout << res << endl;

    return 0;
}
