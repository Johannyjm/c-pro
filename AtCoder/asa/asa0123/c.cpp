#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    deque<int> dq;
    rep(i, n){
        if(i%2 == n%2) dq.push_back(a[i]);
        else dq.push_front(a[i]);
    }

    while(!(dq.size() == 1)){
        cout << dq.front() << " ";
        dq.pop_front();
    }
    cout << dq.front() << endl;

    return 0;
}