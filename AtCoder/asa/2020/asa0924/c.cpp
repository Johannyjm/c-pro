#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    priority_queue<int> pq;
    vector<int> b(m);
    rep(i, n){
        int a;
        cin >> a;
        pq.push(a);
    }
    rep(i, m) cin >> b[i];

    sort(b.begin(), b.end(), greater<int>());

    rep(i, m){
        if(pq.empty()){
            cout << "NO" << endl;
            return 0;
        }
        while(pq.top()<b[i]){            
            pq.pop();
            if(pq.empty()){
                cout << "NO" << endl;
                return 0;
            }
        }
        pq.pop();
    }

    cout << "YES" << endl;


    return 0;
}