#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int N, K;
    cin >> N >> K;
    char pom;
    int cand[N];
    int fcand[N];
    int pcand[N];
    int fcnt = 0;
    int pcnt = 0;

    for(int i = 0; i < N; ++i){
        cin >> cand[i] >> pom;

        if(pom == 'P'){
            cand[i] *= -1;
            pcand[pcnt] = cand[i];
            pcnt++;
        }else{
            fcand[fcnt] = cand[i];
            fcnt++;
        }

    }
    sort(cand, cand + N, greater<int>());
    sort(fcand, fcand + fcnt);
    sort(pcand, pcand + pcnt);

    // for (int i = 0; i < N; ++i) cout << cand[i] << endl;
    // for (int i = 0; i < fcnt; ++i) cout << fcand[i] << endl;
    // for (int i = 0; i < pcnt; ++i) cout << pcand[i] << endl;

    int diff = K - 2019;
    int res = 0;

    for (int i = 0; i < N; ++i){
        
    }

    return 0;
}
