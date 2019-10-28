#include <bits/stdc++.h>

using namespace std;

int main(){
    int N;
    cin >> N;

    int A[N];
    for(int i = 0; i < N; ++i) cin >> A[i];

    int Alice = 0;
    int Bob = 0;

    sort(A, A + N, greater<int>());

    for (int i = 0; i < N; ++i){

        if(i % 2 == 0) Alice += A[i];
        else Bob += A[i];
    }
    cout << abs(Alice - Bob) << endl;
}