#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> a(n), d(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        d[i] = a[i];
    }

    sort(a.begin(), a.end());
    sort(d.begin(), d.end(), greater<int>());
    
    deque<int> dq;
    dq.push_back(a[0]);
    int a_ptr = 1;
    int d_ptr = 0;
    for(int i = 0; i < n; ++i){
        dq.push_front(d[d_ptr]);
        if(dq.size() == n) break;
        ++d_ptr;
        dq.push_back(d[d_ptr]);
        if(dq.size() == n) break;
        ++d_ptr;
        dq.push_front(a[a_ptr]);
        if(dq.size() == n) break;
        ++a_ptr;
        dq.push_back(a[a_ptr]);
        if(dq.size() == n) break;
        ++a_ptr;
    }

    long long res = 0;
    int prev = dq[0];
    for(int i = 1; i < n; ++i){
        int now = dq[i];
        res += abs(now - prev);

        prev = now;
    }

    cout << res << endl;

    return 0;
}
