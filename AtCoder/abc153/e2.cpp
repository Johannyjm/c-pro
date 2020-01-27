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

    vector<int> a(n), b(n);
    cin >> a[0] >> b[0];
    double max_cospa = a[0]/b[0];
    int max_idx;
    vector<double> debug(n);
    debug[0] = max_cospa;
    rep1(i, n){
        int A, B;
        cin >> A >> B;


        a[i] = A;
        b[i] = B;

        debug[i] = (double)A/B;

        if((double)A/B > max_cospa){
            max_cospa = A/B;
            max_idx = i;
        }
    }

    rep(i, n) cout << debug[i] << endl;

    cout << max_cospa << endl;
    cout << max_idx << endl;

    int at = a[max_idx];
    int mp = b[max_idx];

    int res = 0;
    int hp = h;
    while(1){
        res += mp;
        hp -= at;

        if(hp<=0){
            hp += at;
            res -= mp;
            break;
        }
    }


    cout << at << endl;
    cout << hp << endl;
    cout << res << endl;

    int min_mp = 101010;
    rep(i, n){
        if(a[i]>=hp){
            if(b[i] < min_mp){
                min_mp = b[i];
            }
        }
    }

    cout << res + min_mp << endl;


    return 0;
}