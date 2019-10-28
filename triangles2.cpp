#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    int L[N];
    for(int i = 0; i < N; ++i) cin >> L[i];
    int res += 0;

    for(int a = 0; a < N - 2; ++a){

        for(int b = a + 1; b < N - 1; ++b){

            for(int c = a + b + 1; c < N; ++c){

                if(a + b > c and b + c > a and c + a > b) res++;

            }
        }
    }
    cout << res << endl;
}