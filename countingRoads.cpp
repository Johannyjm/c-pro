#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    int bucket[N] = {0};

    for(int i = 0; i < M; ++i){
        int a, b;
        cin >> a >> b;
        bucket[a - 1] += 1;
        bucket[b - 1] += 1;
    }
    for(int i = 0; i < N; ++i) cout << bucket[i] << endl;
}