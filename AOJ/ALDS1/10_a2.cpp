#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

map<int, ll> memo;

ll fib(ll n){
    if(memo[n] == 0) memo[n] = fib(n-1) + fib(n-2);
    return memo[n];
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    memo[1] = 1;
    memo[0] = 1;
    cout << fib(n) << endl;

    return 0;
}