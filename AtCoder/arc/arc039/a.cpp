#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int a, b;
    cin >> a >> b;

    if(a/100 == 9 && b/100 == 1){
        if((a%100)/10 == 9 && (b%100)/10 == 0){
            if(a%10 == 9 && b%10 == 0){
                cout << 899 << endl;
            }
            else{
                cout << max(999 - b, a - 100) << endl;
            }
        }
        else{
            cout << max(990+(a%10) - b, a - (100 + b%10)) << endl;
        }
    }

    else{
        cout << max((900+a%100) - b, a - (100+b%100)) << endl;
    }

    return 0;
}