#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    vector<string> dic;
    string s;
    rep(i, 15){
        cin >> s;
        dic.push_back(s);
    }

    sort(dic.begin(), dic.end());

    cout << dic[6] << endl;

    return 0;
}