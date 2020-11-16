#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int a, b, c;
    cin >> a >> b >> c;

    int mx = max({a, b, c});
    int demand = mx-a + mx-b + mx-c;
    if(demand%2==1) demand += 3;

    cout << demand/2 << endl;

    return 0;
}