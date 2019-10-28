#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, x;
    cin >> N >> x;
    int a[110];

    for(int i = 0; i < N; ++i) cin >> a[i];
    
    sort(a, a + N);

    int stock = x;
    int res = 0;
    for(int i = 0; i < N - 1; ++i){

        if(a[i] <= stock){
            stock -= a[i];
            res++;
        }
    }
    if(stock == a[N - 1]) res++;

    cout << res << endl;
}