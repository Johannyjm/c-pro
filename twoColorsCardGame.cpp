#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int N, M;
    cin >> N;
    map<string, int> bucket;

    for(int i = 0; i < N; ++i){
        string s;
        cin >> s;
        bucket[s]++;
    }

    cin >> M;
    for(int i = 0; i < M; ++i){
        string t;
        cin >> t;
        bucket[t]--;
    }

    int res = 0;
    for(auto x : bucket){
        if(x.second > res) res = x.second;
    }

    cout << res << endl;
}