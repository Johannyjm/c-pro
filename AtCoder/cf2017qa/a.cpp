#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;

    if(s.size() >= 4){
        if(s.substr(0, 4) == "YAKI"){
            puts("Yes");
            return 0;
        }
    }
    puts("No");

    return 0;
}