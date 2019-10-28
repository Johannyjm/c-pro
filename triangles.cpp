#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    int L[N];

    for(int i = 0; i < N; ++i) cin >> L[i];

    sort(L, L + N, greater<int>());

    int res = 0;

    for(int i = 0; i < N - 2; ++i){

        for(int j = i + 1; j < N - 1; ++j){
            int d = L[i] - L[j];

            for(int k = N - 1; k > j; --k){
                if(L[k] > d){
                    int idx = k;
                    res += k - j;
                    break;
                }

            }
        }
    }
    cout << res << endl;
}