#include <iostream>
#include <queue>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    int n, k;
    cin >> n >> k;
    
    priority_queue<pair<int, int>> pq;
    for(int i = 0; i < k; ++i){
        int a;
        cin >> a;
        pq.push({a, i});
    }

    cout << pq.top().second + 1 << endl;
    for(int i = k; i < n; ++i){
        int a;
        cin >> a;
        if(a < pq.top().first){
            pq.push({a, i});
            pq.pop();
        }
        cout << pq.top().second + 1 << endl;
    }
    
    return 0;
}
