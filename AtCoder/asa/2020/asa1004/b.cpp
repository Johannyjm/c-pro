#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int A, B;
    cin >> A >> B;

    int A1 = A/100;
    int A2 = A/10%10;
    int A3 = A%10;
    int B1 = B/100;
    int B2 = B/10%10;
    int B3 = B%10;
    
    int res = A-B;
    for(int a = 100; a <= 999; ++a){
        for(int b = 100; b <= 999; ++b){
            int a1 = a/100;
            int a2 = a/10%10;
            int a3 = a%10;
            int b1 = b/100;
            int b2 = b/10%10;
            int b3 = b%10;

            int cnt = 0;
            if(a1!=A1)++cnt;
            if(a2!=A2)++cnt;
            if(a3!=A3)++cnt;
            if(b1!=B1)++cnt;
            if(b2!=B2)++cnt;
            if(b3!=B3)++cnt;

            if(cnt==1){
                res = max(res, a-b);
            }
        }
    }

    cout << res << endl;

    return 0;
}