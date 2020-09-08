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

    vector<int> ltor(s.size()+1, 0);
    vector<int> rtol(s.size()+1, 0);

    int cnt = 0;
    rep(i, s.size()-1){
        if(s[i] == '<' && s[i+1] == '>'){
            ltor[i] = cnt+1;
            cnt = 0;
        }
        else if(s[i] == '<') ++cnt;
    }
    if(s[s.size()-1] == '<') ltor[s.size()] = cnt+1;

    cnt = 0;
    for(int i = s.size()-1; i >= 1; --i){
        if(s[i] == '>' && s[i-1] == '<'){
            rtol[i] = cnt+1;
            cnt = 0;
        }
        else if(s[i] == '>') ++cnt;
    }
    if(s[0] == '>') rtol[0] = cnt+1;

    rep(i, s.size()+1) cout << ltor[i] << " ";
    cout << endl;
    rep(i, s.size()+1) cout << rtol[i] << " ";
    cout << endl;

    int res = 0;
    vector<int> num(s.size()+1);
    bool flg = false;
    int tmp;

    if(s[0] == '>') {
        res += rtol[0];
        num[0] = rtol[0];
        flg = true;
        tmp = num[0];
    }
    else num[0] = 0;

    rep(i, s.size()){
        if(s[i] == '>' && s[i+1] == '<') num[i+1] = 0;
        if(s[i] == '<' && s[i+1] == '>') {
            num[i+1] = max(ltor[i], rtol[i+1]);
            flg = true;
            tmp = min(ltor[i], rtol[i+1]);
            res += num[i+1];
        }
        if(s[i] == '<' && s[i+1] == '<') {
            num[i+1] = num[i] + 1;
            res += num[i+1];
        }
        if(s[i] == '>' && s[i+1] == '>') {
            if(flg){
                num[i+1] = tmp;
                res += num[i+1];
                flg = false;
                tmp = 0;
            }
            else {
                num[i+1] = num[i] - 1;
                res += num[i+1];
            }
        }

        cout << num[i] << " ";
    }
    if(s[s.size()-1]=='<'){
        num[s.size()] = ltor[s.size()];
        res += num[s.size()];
    }
    else num[s.size()] = 0;
    cout << num[s.size()];
    cout << endl;
    cout << res << endl;   

    return 0;
}