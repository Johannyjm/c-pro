#include <bits/stdc++.h>

using namespace std;

int main(){
    int N, elem;
    int bucket[100];
    int res = 0;

    cin >> N;


    for(int i = 0; i < N; ++i){
        cin >> elem;
        cout << elem << endl;
        bucket[elem]++;
        cout << bucket[elem] << endl;
    }

    for(int i = 0; i < 100; ++i){
        cout << bucket[i] << endl;
        
        if(bucket[i] > 0) res++;
    }
    cout << res << endl;
}