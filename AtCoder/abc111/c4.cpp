#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    map<int, int> even;
    map<int, int> odd;

    rep(i, n){
        int v;
        cin >> v;

        if(i%2) ++even[v];
        else ++odd[v];
    }

    sort(even.begin(), even.end(), greater<int>());

    
}