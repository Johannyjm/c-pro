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

    map<string, int> remain{
        {"Sunday", 0}, 
        {"Monday", 5}, 
        {"Tuesday", 4}, 
        {"Wednesday", 3}, 
        {"Thursday", 2}, 
        {"Friday", 1}, 
        {"Saturday", 0}
    };

    cout << remain[s] << endl;


    return 0;
}