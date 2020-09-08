#include <iostream>
#include <vector>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> c(n-1), s(n-1), f(n-1);
    for(int i = 0; i < n-1; ++i) cin >> c[i] >> s[i] >> f[i];

    vector<int> res(n, 0);
    for(int i = 0; i < n-1; ++i){
        int time = 0;
        for(int j = i; j < n-1; ++j){
            int sj = s[j];
            int fj = f[j];

            while(sj < time) sj += fj;
            time = sj;
            time += c[j];
        }

        res[i] = time;
    }

    for(int i = 0; i < n; ++i) cout << res[i] << endl;
}
