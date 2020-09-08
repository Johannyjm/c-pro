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

    if(s=="AKIHABARA" || s=="KIHABARA" || s=="AKIHBARA" || s=="KIHBARA" || s=="AKIHABRA" || s=="KIHABRA" || s=="AKIHBRA" || s=="KIHBRA" || s=="AKIHABAR" || s=="KIHABAR" || s=="AKIHBAR" || s=="KIHBAR" || s=="AKIHABR" || s=="KIHABR" || s=="AKIHBR" || s=="KIHBR"){
        puts("YES");
    }
    else puts("NO");

    return 0;
}