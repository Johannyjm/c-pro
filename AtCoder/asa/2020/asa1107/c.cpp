#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int n;
vector<string> res;
void dfs(int idx, string now){
    if(idx == n){
        res.push_back(now);
        return;
    }

    for(char c = 'a'; c <= 'c'; ++c){
        dfs(idx+1, now+c);
    }

}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    dfs(0, "");

    for(auto e: res) cout << e << endl;

    return 0;
}