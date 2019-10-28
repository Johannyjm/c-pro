#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    ll A[N];
    for(int i = 0; i < N; ++i) cin >> A[i];

    int res = 1;
    int step = 1;
    bool is_up;

    for(int i = 1; i < N; ++i){

        if(step == 0){
            step = 1;
        }

        if(A[i] > A[i - 1] and step == 1){
            is_up = true;
            step = 2;
        }
        if(A[i] < A[i - 1] and step == 1){
            is_up = false;
            step = 2;
        }
        if(A[i] > A[i - 1] and not is_up and step == 2){
            res++;
            step = 0;
        }
        if(A[i] < A[i - 1] and is_up and step == 2){
            res++;
            step = 0;
        }

    }
    cout << res << endl;
}