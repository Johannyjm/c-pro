#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int k, t;
    cin >> k >> t;
    priority_queue<pair<int, int>> pq;
    rep(i, t){
        int a;
        cin >> a;
        pq.push(make_pair(a, i));
    }

    pair<int, int> tmp = pq.top();
    pq.pop();
    int prev = tmp.second;
    --tmp.first;
    if(tmp.first != 0) pq.push(tmp);
    
    int res = 0;
    rep(_, k-1){
        pair<int, int> tmp = pq.top();
        pq.pop();

        if(tmp.second == prev){
            if(pq.empty()){
                ++res;
                --tmp.first;
                if(tmp.first != 0) pq.push(tmp);
            }
            else{
                pair<int, int> tmp2 = pq.top();
                pq.pop();
                --tmp2.first;
                prev = tmp2.second;
                if(tmp.first != 0) pq.push(tmp);
                if(tmp2.first != 0) pq.push(tmp2);
            }
        }
        else{
            --tmp.first;
            prev = tmp.second;
            if(tmp.first != 0) pq.push(tmp);
        }

    }

    cout << res << endl;


    return 0;
}