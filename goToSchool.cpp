#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    int A[11000] = {0};

    for(int i = 0; i < N; ++i){
        int a;
        cin >> a;
        A[a - 1] = i + 1;
    }
    for(int i = 0; i < N; ++i) cout << A[i] << " ";
    cout << endl;

}