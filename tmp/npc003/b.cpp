#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, k;
    string s;
    cin >> n >> s >> k;

    char chr = s[k-1];

    for(auto c: s){
        char out = c;
        if(out != chr) out = '*';
        cout << out;
    }
    cout << endl;

    return 0;
}