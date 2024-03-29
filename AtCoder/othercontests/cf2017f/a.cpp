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

    string correct = "KIHBR";
    string clipped = "";
    int ptr = 0;
    rep(i, s.size()){
        if(s[i] == correct[ptr]){
            clipped += s[i];
            ++ptr;
        }
    }

    if(clipped == correct) puts("YES");
    else puts("NO");

    return 0;
}