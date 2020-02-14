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
    map<string, int> exists;

    string prev;
    cin >> prev;
    ++exists[prev];
    rep1(i, n){
        string current;
        cin >> current;

        if(prev.back() != current.front() || exists[current] > 0){
            if(i%2) puts("WIN");
            else puts("LOSE");
            return 0;
        }

        ++exists[current];
        prev = current;
    }

    puts("DRAW");

    return 0;
}