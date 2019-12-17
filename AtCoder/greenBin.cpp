#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;

    map<string, int> ana_map{};
    for (int i = 0; i < n; ++i){
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        ana_map[s] += 1;
    }

    ll res = 0;

    auto begin = ana_map.begin(), end = ana_map.end();
    for (auto iter = begin; iter != end; iter++) {
        ll value = iter->second;
        res += value*(value-1)/2;
    }
    cout << res << endl;
}