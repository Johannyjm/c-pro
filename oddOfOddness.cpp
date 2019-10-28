#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N; cin >> N;
    if(N % 2 == 0){
        printf("%.10f\n", 0.5);
        return 0;
    }
    
    double n = N;
    double res = ((n + 1) / 2) / n;
    
    printf("%.10f\n", res);
    return 0;
}