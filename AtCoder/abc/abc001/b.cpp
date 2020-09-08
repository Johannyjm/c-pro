#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int m;
    cin >> m;

    if(m<100) cout << "00" << endl;
    else if(100<=m && m <1000) cout << "0" << m/100 << endl;
    else if(1000<=m && m<=5000) cout << m/100 << endl;
    else if(6000<=m && m<=30000) cout << m/1000 + 50 << endl;
    else if(35000<=m && m<=70000) cout << (m/1000 -30)/5 + 80 << endl;
    else if(70000<m) cout << "89" << endl;
}