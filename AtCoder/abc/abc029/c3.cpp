#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int n;

void dfs(string res, int num){
    if(num == n) cout << res << endl;
    else{
        for(char c = 'a'; c <= 'c'; ++c){
            dfs(res+c, num+1);
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;

    dfs("", 0);

    return 0;
}