#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    vector<int> num(s.size()+1);
    vector<int> big(s.size()+1);
    s = '>' + s + '<';
    int res = 0;
    rep(i, s.size()-1){
        if(s[i] == '>' && s[i+1] == '<') num[i] = 0;
        if(s[i] == '<' && s[i+1] == '>') {
            num[i] = num[i-1] + 1;
            big[i] = num[i-1] + 1;
        }
        if(s[i] == '<' && s[i+1] == '<') num[i] = num[i-1] + 1;
        if(s[i] == '>' && s[i+1] == '>') num[i] = num[i-1] - 1;

    }

    for(int i = s.size()-2; i >= 0; --i){
        if(s[i] == '<' && s[i-1] == '>') num[i] = 0;
        if(s[i] == '>' && s[i-1] == '<') num[i] = max(big[i], num[i+1] + 1);
        if(s[i] == '>' && s[i-1] == '>') num[i] = num[i+1] + 1;
        if(s[i] == '<' && s[i-1] == '<') num[i] = num[i+1] - 1;
        res += num[i];
        cout << num[i] << " ";
    }
    cout << endl;

    cout << res << endl;

    return 0;
}