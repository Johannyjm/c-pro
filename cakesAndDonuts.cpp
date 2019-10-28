#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    bool flg = false;

    for(int c = 0; c <= N / 4; ++c){

        for(int d = 0; d <= N / 7; ++ d){

            if(c * 4 + d * 7 == N) flg = true;
        }
    }

    if(flg) cout << "Yes" << endl;
    else cout << "No" << endl;
}