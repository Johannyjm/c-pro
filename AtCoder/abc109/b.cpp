#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    string prev;
    cin >> prev;
    bool flg = true;
    map<string, int> exists;
    ++exists[prev];

    for(int i = 1; i < n; ++i){
        string next;
        cin >> next;

        if(prev[prev.length()-1] != next[0]) flg = false;
        if(exists[next] > 0) flg = false;

        prev = next;
        ++exists[next];
    }

    cout << (flg? "Yes": "No") << endl;
}