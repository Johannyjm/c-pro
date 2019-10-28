#include <bits/stdc++.h>

using namespace std;

int main(){
    int N, elem;
    int d[100];
    int bucket[100] = {0};
    int res = 0;

    cin >> N;

    for(int i = 0; i < N; ++i) cin >> d[i];
       
    for(int i = 0; i < N; ++i){
        bucket[d[i]]++;
    }

    for(int j = 0; j < 100; ++j){

        if(bucket[j] > 0){
            res++;
        }
        //cout << bucket[j] << endl;
    }
    cout << res << endl;


}

// int main(){
//     int N;
//     int d[110];
//     cin >> N;
//     for (int i = 0; i < N; ++i) cin >> d[i];
    
//     int num[110] = {0};
//     for(int i = 0; i < N; ++i){
//         num[d[i]]++;
//     }
//     int res = 0;

//     for(int i = 0; i < 100; ++i){

//         if(num[i] > 0){
//             res++;
//         }
//     }
//     cout << res << endl;
// }