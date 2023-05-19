#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

ll N;
string S;
ll ans = -1;

void dfs(int index, ll value) {
    if(index == S.size()) {
        if(value <= N) ans = max(ans, value);
        return;
    }
    if(S[index] != '?') {
        dfs(index + 1, value * 2 + (S[index] - '0'));
    } else {
        dfs(index + 1, value * 2);
        dfs(index + 1, value * 2 + 1);
    }
}

int main() {
    cin >> S >> N;
    dfs(0, 0);
    cout << ans << endl;
    return 0;
}