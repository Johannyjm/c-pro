#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    int c[3][3] = {{0}};
    int max = 0;


    for(int i = 0; i < 3; ++i){

        for(int j = 0; j < 3; ++j){
            cin >> c[i][j];

            if(c[i][j] > max) max = c[i][j];
        }
    }

    for(int a1 = 0; a1 < max; ++a1){

        for(int a2 = 0; a2 < max; ++a2){

            for(int a3 = 0; a3 < max; ++a3){

                for(int b1 = 0; b1 < max - a1; ++b1){

                    for(int b2 = 0; b2 < max - a2; ++b2){

                        for(int b3 = 0; b3 < max - a3; ++b3){

                            int a[3] = {a1, a2, a3};
                            int b[3] = {b1, b2, b3};
                            bool flg = true;

                            for(int i = 0; i < 3; ++i){

                                for(int j = 0; j < 3; ++j){

                                    if(c[i][j] == a[i] + b[j]) flg = flg and true;
                                    else flg = false;
                                }
                            }
                            
                            if(flg){
                                cout << "Yes" <<endl;
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }

    cout << "No" << endl;

    // for(int i = 0; i < 3; ++i){
    //     for(int j = 0; j < 3; ++j){
    //         cout << c[i][j];
    //     }
    //     cout << endl;
    // }

}