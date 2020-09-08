#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    priority_queue<int> pq;
    pq.push(3);
    pq.push(5);
    pq.push(2);
    pq.push(1);
    pq.push(2);
    
    rep(i, 5){
        cout << pq.top() << endl;
        pq.pop();
    }
    
    priority_queue<int, vector<int>, greater<int>> pq1;
    pq1.push(3);
    pq1.push(5);
    pq1.push(2);
    pq1.push(1);
    pq1.push(2);

    rep(i, 5){
        cout << pq1.top() << endl;
        pq1.pop();
    }



    return 0;
}