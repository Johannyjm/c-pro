#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint1000000007;

int n;
vector<map<string, mint>> dp(110);

bool check(string s){
    if(s[0]=='A'&&s[1]=='G'&&s[2]=='C') return false;
    if(s[1]=='A'&&s[2]=='G'&&s[3]=='C') return false;
    if(s[1]=='A'&&s[0]=='G'&&s[2]=='C') return false;
    if(s[2]=='A'&&s[1]=='G'&&s[3]=='C') return false;
    if(s[0]=='A'&&s[2]=='G'&&s[1]=='C') return false;
    if(s[1]=='A'&&s[3]=='G'&&s[2]=='C') return false;
    if(s[0]=='A'&&s[1]=='G'&&s[3]=='C') return false;
    if(s[0]=='A'&&s[2]=='G'&&s[3]=='C') return false;
    

    return true;
}

mint rec(int idx, string last3){
    if(dp[idx][last3].val() > 0) return dp[idx][last3];
    if(idx == n) return 1;

    mint ret = 0;
    for(char c: {'A', 'G', 'C', 'T'}){
        string s = last3;
        s += c;
        if(check(s)){
            ret += rec(idx+1, s.substr(1, 3));
        }
    }

    return dp[idx][last3] = ret;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;

    cout << rec(0, "TTT").val() << endl;    

    return 0;
}