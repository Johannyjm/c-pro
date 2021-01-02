#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, r;
    cin >> n >> r;
    string s;
    cin >> s;

    int lst = -1;
    vector<int> a(n);
    rep(i, n){
        if(s[i] == '.'){
            lst = i;
            a[i] = 0;
        }
        else a[i] = 1;
    }

    if(lst == -1){
        cout << 0 << endl;
        return 0;
    }

    lst = max(0, lst-r+1);

    int res = 0;
    rep(i, n){
        if(i == lst){
            ++res;
            break;
        }

        if(a[i] == 0){
            for(int j = i; j < min(n, i+r); ++j) a[j] = 1;
            ++res;
        }
        ++res;
    }

    cout << res << endl;

    return 0;
}