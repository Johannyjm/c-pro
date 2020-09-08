#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

vector<int> res;


bool dfs(vector<int> b, int idx = -1){

    vector<int> nxt;
    rep(i, b.size()){
        if(i == idx) continue;
        else nxt.push_back(b[i]);
    }

    vector<int> stack;
    rep(i, nxt.size()){
        if(i+1 == nxt[i]) {
            stack.push_back(i);
        }
    }

    if(b.size()==1 && stack.size()==1) {
        cout << b[0] << endl;
        return true;
    }

    while(!stack.empty()){

        int pop_idx = stack.back();
        stack.pop_back();
        // res.push_back(nxt[pop_idx]);
        bool flg = dfs(nxt, pop_idx);
        
        if(flg){
            cout << nxt[pop_idx] << endl;
            return true;
        }
    }

    return false;
}


int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> b(n);
    rep(i, n) cin >> b[i];

    dfs(b);

    // for(int i = res.size() - n; i < res.size(); ++i) cout << res[i] << endl;

    // rep(i, res.size()) cout << res[i] << endl;

    return 0;
}