#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int h, n;
    cin >> h >> n;

    vector<pair<int, pair<int, int>>> diff_a_b(n);
    rep(i, n){
        int a, b;
        cin >> a >> b;

        diff_a_b[i] = make_pair(a-b, make_pair(a, b));
    }

    sort(diff_a_b.begin(), diff_a_b.end(), greater<int>());

    int hp = h;
    int res = 0;
    int termflg = false;

    rep(i, n){
        int at, mp;
        at = diff_a_b[i].second.first;
        mp = diff_a_b[i].second.second;

        if(at<=hp){
            if(at==hp) {
                res += mp;
                break;
            }
            hp -= at;
            res += mp;
        }

        else{
            for (int j = i+1; j < n; ++j){
                int at2;
                at2 = diff_a_b[j].second.first;

                if(at2>hp){
                    res += diff_a_b[j-1].second.second;
                    termflg = true;
                    break;
                }
            }
        }

        if(termflg) break;
    }

    cout << res << endl;

    return 0;
}