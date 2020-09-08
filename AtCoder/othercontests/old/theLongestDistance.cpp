#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    double maxsqd = -1;
    double x[100], y[100];
    cin >> N;
    cin >> x[0] >> y[0];

    for(int i = 1; i < N; ++i){
        cin >> x[i] >> y[i];
        
        for(int j = 0; j < i; ++j){
            double distsqd = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);

            if(distsqd > maxsqd) maxsqd = distsqd;
        }

    }

    // cout << setprecision(6);
    // cout << setiosflags(ios::scientific); 
    // cout << sqrt(maxsqd) << endl;

    printf("%f",sqrt(maxsqd));
    cout << endl;

}