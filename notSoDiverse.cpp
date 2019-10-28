#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll N, K, A;
    cin >> N >> K;
    ll bucket[210000] = {0};

    for(int i = 0; i < N; ++i){
        cin >> A;
        bucket[A - 1]++;
    }
    
    sort(bucket, bucket + N);
    ll kinds = 0;

    for(int i = 0; i < N; ++i){
        
        if(bucket[i] > 0){
            kinds++;
        }
    }


    ll res = 0;
    ll cd = kinds - K;

    for(int i = 0; i < N; ++i){

        if(bucket[i] > 0 and cd > 0){
            res += bucket[i];
            cd--;
        }
    }
    cout << res << endl;


}