#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int past(int y, int m, int d){
    return 365*y + y/4 - y/100 + y/400 + (306*(m+1))/10 + d - 429;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int y, m, d;
    cin >> y >> m >> d;

    if(m==1 || m==2){
        --y;
        m+=12;
    }

    cout << past(2014, 5, 17) - past(y, m, d) << endl;

    return 0;
}