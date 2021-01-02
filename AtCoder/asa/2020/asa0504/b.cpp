#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    int is_t = 1;
    string prev;
    cin >> prev;
    map<string, int> exists;
    ++exists[prev];
    rep1(i, n){
        is_t = 1 - is_t;
        string curr;
        cin >> curr;

        if(curr.front() != prev.back() || exists[curr] > 0){
            if(is_t)puts("LOSE");
            else puts("WIN");
            return 0;
        }

        ++exists[curr];
        prev = curr;
    }

    puts("DRAW");

    return 0;
}