#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;

    for(int i = 2; i < N; ++i){

        if(N % i == 0){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;

}