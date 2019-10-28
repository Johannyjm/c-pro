#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;
    string A[N], B[M];

    for(int i = 0; i < N; ++i) cin >> A[i];
    for(int i = 0; i < M; ++i) cin >> B[i];

    string clipped[M];

    for (int i = 0; i < N - M + 1; ++i){

        for (int j = 0; j < N - M + 1; ++j){

            for(int n = i; n < i + M; ++n) clipped[n - i] = A[n];

            for(int m = 0; m < M; ++m){
                clipped[m] = clipped[m].substr(j, M);
            }
            
            for(int m = 0; m < M; ++m){

                if(clipped[m] == B[m]){
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
        
    }
    cout << "No" << endl;
    return 0;
}