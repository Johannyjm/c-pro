#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, T, A;
    int H[1100];
    cin >> N >> T >> A;

    for(int i = 0; i < N; ++i) cin >> H[i];

    double alpha = 0.006;
    double min_diff = abs(A - (T - H[0] * alpha));
    int res = 1;

    for(int i = 1; i < N; ++i){
        int diff = abs(A - (T - H[i] * alpha));

        if(diff < min_diff) {
            min_diff = diff;
            res = i + 1;
        }
    }

    cout << res << endl;

}