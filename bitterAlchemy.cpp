#include <bits/stdc++.h>

using namespace std;


int mymin(int m[]){
    int min = m[0];

    for(int i = 1; i < m.size(); ++i){

        if(m[i] < min) min = m[i];
    }
    return min;
}

int mysum(int m[]){
    int sum = 0;

    for(int i = 0; i < m.size(); ++i){
        sum += m[i];
    }
    return sum;
}

int main(){
    int N, X;
    int m[110];

    cin >> N >> X;

    for(int i = 0; i < N; ++i) cin >> m[i];

    X -= mysum(m);
    int res = N;

    res += X / mymin(m);

    cout << res << endl;
}