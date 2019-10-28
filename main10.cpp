#include <bits/stdc++.h>

using namespace std;

int main(){

    int N;
    int A[210];
    int counter = 0;

    cin >> N;

    for(int i = 0; i < N; ++i) cin >> A[i];

    while(true) {
        bool flg = true;

        for(int i = 0; i < N; ++i){

            if(A[i] % 2 != 0) flg = false;
        }

        if(flg){

            for(int i = 0; i < N; ++i) A[i] /= 2;
            ++counter;
        }else{
            break;
        }

    }
    cout << counter << endl;

}