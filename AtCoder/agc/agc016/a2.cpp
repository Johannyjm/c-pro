#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

bool is_allsame(string t){
    set<char> char_set;
    rep(i, t.size()){
        char_set.insert(t[i]);
    }
    if(char_set.size() == 1) return true;
    else return false;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    int n = s.size();


    int res = 1000;

    rep(c, 26){
        int cnt = 0;
        char ch = 'a' + c;
        string t = s;

        while(!is_allsame(t)){
            string t_ = "";
            rep(i, t.size()-1){
                if(t[i]==ch || t[i+1]==ch) t_ += ch;
                else t_ += t[i];
            }
            ++cnt;
            t = t_;
        }
        
        res = min(res, cnt);
    }

        
    cout << res << endl;


    return 0;
}