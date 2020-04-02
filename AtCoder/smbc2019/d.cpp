#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    string s;
    cin >> s;

    int res = 0;
    rep(i, 1000){
        char one = '0' + (i/100);
        char two = '0' + (i%100/10);
        char three = '0' + (i%10);

        bool flg1 = false;
        bool flg2 = false;
        bool flg3 = false;

        int ptr = 0;
        for(int j = ptr; j < n-2; ++j){
            if(s[j] == one){
                flg1 = true;
                ptr = j+1;
                break;
            }
        }

        for(int j = ptr; j < n-1; ++j){
            if(s[j] == two){
                flg2 = true;
                ptr = j+1;
                break;
            }
        }

        for(int j = ptr; j < n; ++j){
            if(s[j] == three) {
                flg3 = true;
                break;
            }
        }

        if(flg1 && flg2 && flg3) ++res;
    }

    cout << res << endl;

    return 0;
}