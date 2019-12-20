#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int bucket[100000] = {0};

    for (int i = 0; i < n; ++i){
        int a;
        cin >> a;
        bucket[a]++;
    }
    int res = 0;
    for (int i = 2; i < 100000; ++i){
        res = max(res, bucket[i-2] + bucket[i-1] + bucket[i]);
    }
    cout << res << endl;
}