#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, X;
    int m;
    int min = 1e9;

    cin >> N >> X;
    
    for(int i = 0; i < N; ++i){
        cin >> m;

        if(m < min) min = m;

        X -= m;

    }

    int res = N + X / min;
    cout << res << endl;
}