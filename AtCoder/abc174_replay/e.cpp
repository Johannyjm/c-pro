#include <iostream>
#include <vector>
using namespace std;

int n, k;
vector<int> a;
bool check(int l){
    int times = 0;
    for(int i = 0; i < n; ++i){
        times += a[i] / l;
        if(a[i] % l == 0) --times;
    }

    return times <= k;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> k;

    a.resize(n);
    int ok = 0;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        ok = max(ok, a[i]);
    }
    int ng = 0;

    while(ok - ng > 1){
        int mid = (ok + ng) / 2;

        if(check(mid)) ok = mid;
        else ng = mid;
    }

    cout << ok << endl;

    return 0;
}
