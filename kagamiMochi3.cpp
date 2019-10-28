#include <bits/stdc++.h>

using namespace std;

int main(){
    int N;
    int d[100];
    cin >> N;

    for(int i = 0; i < N; ++i) cin >> d[i];

    int bucket[100] = {0};
    for(int i = 0; i < N; ++i){
        bucket[d[i]]++;
    }
    int res = 0;

    for(int i = 0; i < 100; ++i){

        if(bucket[i] > 0) res++;
    }

    cout << res << endl;
}