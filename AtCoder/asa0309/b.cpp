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
    int a, b, c, d;
    a = s[0] - '0';
    b = s[1] - '0';
    c = s[2] - '0';
    d = s[3] - '0';

    for(int i = 0; i < (1<<3); ++i){
        int op[] = {1, 1, 1};
        for(int j = 0; j < 3; ++j){

            if(i & (1<<j)) op[j] = -1;

            if(a + b*op[0] + c*op[1] + d*op[2] == 7){
                cout << a << ((op[0]>0)? '+': '-') << b << ((op[1]>0)? '+': '-') << c << ((op[2]>0)? '+': '-') << d << "=7" << endl;
                return 0;
            }
        }
    }

    return 0;
}