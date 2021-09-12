#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    queue<int> q;
    priority_queue<int, vector<int>, greater<int>> pq;
    while(t--){
        int cmd;
        cin >> cmd;
        
        if(cmd == 1){
            int x;
            cin >> x;
            q.push(x);
        }
        if(cmd == 2){
            if(!pq.empty()){
                cout << pq.top() << endl;
                pq.pop();
            }
            else{
                cout << q.front() << endl;
                q.pop();
            }
        }
        if(cmd == 3){
            while(!q.empty()){
                pq.push(q.front());
                q.pop();
            }
        }
    }

    return 0;
}