#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int hms2sec(string hms){
    int h = 10*(hms[0]-'0') + (hms[1]-'0');
    int m = 10*(hms[3]-'0') + (hms[4]-'0');
    int s = 10*(hms[6]-'0') + (hms[7]-'0');

    return 3600*h + 60*m + s;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    while(1){
        int n;
        cin >> n;

        if(n == 0) break;

        const int DAY = 24 * 60 * 60;

        vector<int> imos(DAY+10);
        rep(i, n){
            string fr_str, to_str;
            cin >> fr_str >> to_str;

            int from = hms2sec(fr_str);
            int to = hms2sec(to_str);

            ++imos[from];
            --imos[to];
        }
        int res = 0;
        rep1(i, DAY+10){
            imos[i] += imos[i-1];
            res = max(res, imos[i]);
        }

        cout << res << endl;

    }

    return 0;
}