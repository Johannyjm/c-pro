#include <bits/stdc++.h>

using namespace std;

int main(){
    int N, K, Q;
    int A[Q];

    cin >> N >> K >> Q;
    for(int i = 0; i < Q; ++i) cin >> A[i];
    
    vector<int> member(N, K - Q);

    for(int i = 0; i < Q; ++i){
        member[A[i]]++;
    }
    for(int i = 0; i < Q; ++i){
        cout << member[i] << endl;
    }
    // cout << member << endl;
}