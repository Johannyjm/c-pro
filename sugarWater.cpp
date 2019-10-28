#include <bits/stdc++.h>
using namespace std;
using ld = long double;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ld A, B, C, D, E, F;
    cin >> A >> B >> C >> D >> E >> F;
    ld max_d = -1;
    ld res_w = -1;
    ld res_s = 0;

    for(int a = 0; a * A * 100 < F; ++a){
        ld A_water = a * A * 100;

        for(int b = 0; b * B * 100 < F - A_water; ++b){
            ld B_water = b * B * 100;

            for(int c = 0; c * C < F - A_water - B_water; ++c){
                ld C_sugar = c * C;

                for(int d = 0; d < F - A_water - B_water - C_sugar; ++d){
                    ld D_sugar = d * D;
                    if(A_water + B_water == 0) break;

                    ld den = 100 * (C_sugar + D_sugar) / (A_water + B_water);
                    if(A_water + B_water + C_sugar + D_sugar > F) break;

                    if((a * A + b * B) * E < C_sugar + D_sugar) break;
                    
                    if(max_d < den) {
                        res_w = A_water + B_water + C_sugar + D_sugar;
                        res_s = C_sugar + D_sugar;
                        max_d = den;

                        if(den == E){
                            cout << res_w << " " << res_s << endl;
                            return 0;
                        }
                    }

                }
            }
        }
    }

    cout << res_w << " " << res_s << endl;
}