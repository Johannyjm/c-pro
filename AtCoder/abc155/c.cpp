#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    map<string, int> vote;

    int v_max = 0;
    rep(i, n){
        string s;
        cin >> s;
        ++vote[s];
        if(vote[s]>v_max){
            v_max = vote[s];
        }
    }

    vector<string> res;
    // for (const auto& [key, value]: vote){
    //     if(value==v_max) res.push_back(key);
    // }
    for(auto iter = vote.begin(); iter != vote.end(); ++iter){
        if(iter->second == v_max) cout << iter->first << endl;
    }

    // sort(res.begin(), res.end());

    // for(const auto& s: res){
    //     cout << s << endl;
    // }



    return 0;
}