#include <bits/stdc++.h>
using namespace std;

int main(){
    long N;
    long A[110];
    cin >> N;

    for(int i = 0; i < N; ++i) cin >> A[i];
    long min = A[0];
    long max = A[0];

    for(int i = 1; i < N; ++i){

        if(A[i] > max) max = A[i];
        if(A[i] < min) min = A[i];
    }
    cout << max - min << endl;
}