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

    int left_c = -1;
    int right_f = -1;

    rep(i, s.size()){
        if(s[i] == 'C' && left_c==-1) left_c = i;
        if(s[i] == 'F') right_f = i;
    }

    if(left_c<right_f && left_c>=0 && right_f>=0) puts("Yes");
    else puts("No");

    return 0;
}