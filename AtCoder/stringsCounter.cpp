#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;

    int bucket[6] = {0};

    for(int i = 0; i < s.length(); ++i){
        ++bucket[s[i]-'A'];
    }

    rep(i, 5) cout << bucket[i] << " ";

    cout << bucket[5] << endl;
}