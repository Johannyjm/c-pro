#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

vector<int> a;
vector<int> order;

int dp[200000]
int rec(int v, int p){

}


int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    a.resize(n);
    order.resize(n);
    rep(i, n){
        cin >> a[i];
        order[a[i]-1] = i;
    }

    rep(i, n) cout << order[i] << " ";
    cout << endl;

    cout << n + rec(0, 0) << endl;




    return 0;
}