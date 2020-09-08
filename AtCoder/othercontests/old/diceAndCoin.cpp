#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;

    double res = 0.;
    for(int i = 1; i <= n; ++i){
        int cnt = 0;
        int score = i;
        while(score < k){
            score *= 2;
            cnt++;
        }
        res +=  1./(n*(1<<cnt));
    }
    printf("%.10f\n", res);
}