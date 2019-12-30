#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    int max_pop = -1;
    string max_city = "";
    int sum_pop = 0;

    rep(i, n){
        string s;
        int p;
        cin >> s >> p;

        if(p>max_pop){
            max_city = s;
            max_pop = p;
        }
        sum_pop += p;
    }
    
    if(max_pop * 2 > sum_pop) cout << max_city << endl;
    else cout << "atcoder" << endl;
}