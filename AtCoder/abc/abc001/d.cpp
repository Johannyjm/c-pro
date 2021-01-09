#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> from(n), to(n);
    rep(i, n){
        string s;
        cin >> s;
        int f = 0;
        int t = 0;

        f += ((s[0] - '0') * 10 + (s[1] - '0')) * 60;
        f += (s[2] - '0') * 10;
        f += (s[3] - '0') - (s[3] - '0') % 5;

        t += ((s[5] - '0') * 10 + (s[6] - '0')) * 60;
        t += (s[7] - '0') * 10;
        t += (s[8] - '0') + (5 - (s[8] - '0') % 5);
        if((s[8] - '0')%5 == 0) t -= 5;

        from[i] = f;
        to[i] = t;
    }

    vector<int> time(60 * 24 + 10, 0);
    rep(i, n){
        for(int j = from[i]; j <= to[i]; ++j){
            time[j] = 1;
        }
    }

    vector<pair<int, int>> resfrom, resto;
    int f = -1;
    int t = -1;
    if(time[0] == 1) f = 0;

    rep(i, 60*24+10){
        if(time[i-1] == 0 && time[i] == 1){
            f = i;
        }
        if(time[i-1] == 1 && time[i] == 0){
            t = i-1;
            resfrom.push_back({f/60, f%60});
            resto.push_back({t/60, t%60});
        }
    }

    int m = resfrom.size();
    rep(i, m){
        int a = resfrom[i].first;
        int b = resfrom[i].second;
        int c = resto[i].first;
        int d = resto[i].second;

        cout << ((a < 10)? "0": "") << a << ((b < 10)? "0": "") << b << "-" << ((c < 10)? "0": "") << c << ((d < 10)? "0": "") << d << endl;
    }

    return 0;
}