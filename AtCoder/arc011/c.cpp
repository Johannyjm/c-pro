#include <iostream>
#include <string>
#include <vector>
using namespace std;

string fi, la;
int n, m;
vector<string> s;
const int INF = 1001001001;
vector<

vector<string> rec(string prev, vector<bool> seen){
    vector<string> ret;
    int cnt = 0;
    for(int j = 0; j < m; ++j){
        if(prev[j] != la[j]) ++cnt;
    }
    if(cnt == 1){
        ret.push_back(prev);
        return ret;
    }
    
    int mn_len = INF;
    int mn_idx = -1;
    for(int i = 0; i < n; ++i){
        if(seen[i]) continue;
        cnt = 0;
        for(int j = 0; j < m; ++j){
            if(prev[j] != s[i][j]) ++cnt;
        }
        if(cnt == 1){
            seen[i] = true;
            vector<string> tmp = rec(s[i], seen);
            if(tmp.size() != n+10 && tmp.size() < mn_len){
                ret = tmp;
                mn_len = tmp.size();
                mn_idx = i;
            }
        }
    }
    
    if(mn_len == INF){
        vector<string> fail(n+10, " ");
        return fail;
    }
    ret.push_back(prev);

    return ret;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> fi >> la;
    cin >> n;

    m = fi.size();
    for(int i = 0; i < n; ++i){
        string str;
        cin >> str;
        if(str == fi || str == la) continue;

        s.push_back(str);
    }
    n = s.size();
    
    if(fi == la){
        cout << 0 << endl;
        cout << fi << endl;
        cout << la << endl;
        return 0;
    }
    vector<bool> seen(n, false);
    
    vector<string> res = rec(fi, seen);

    if(res.size() == n+10){
        cout << -1 << endl;
        return 0;
    }

    cout << res.size() - 1 << endl;
    for(int i = res.size() - 1; i >= 0; --i){
        cout << res[i] << endl;
    }
    cout << la << endl;

    return 0;
}
