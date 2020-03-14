#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

vector<int> res;

vector<int> dfs(vector<int> b){

    vector<int> stack;
    rep(i, b.size()){
        if(i+1 == b[i]) stack.push_back(i);
    }

    if(b.size()==1 && stack.size()==1){
        res.push_back(b[0]);
        return res;
    }

    while(!stack.empty()){
        int pop_idx = stack.back();
        int pop_value;
        stack.pop_back();

        vector<int> nxt;
        rep(i, b.size()){
            if(i == pop_idx) pop_value = b[i];
            else nxt.push_back(b[i]);
        }

        bool ngflg = false;
        rep(i, nxt.size()){
            if(nxt[i] > i+1) ngflg = true;
        }
        if(ngflg) continue;

        res = dfs(nxt);
        
        if(res.size()>0){
            res.push_back(pop_value);
            return res;
        }
    }

    return vector<int> {};
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> b(n);
    rep(i, n) cin >> b[i];

    res = dfs(b);

    if(res.empty()) cout << -1 << endl;
    else rep(i, res.size()) cout << res[i] << endl;


    return 0;
}