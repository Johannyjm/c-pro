#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    int n = s.size();
    vector<int> c(n);
    for(int i = 0; i < n; ++i) c[i] = s[i] - 'A';

    int res = 0;
    for(int i = 0; i < n; ++i){
        int cnt = 0;
        for(int j = 0; j < n-2; ++j){
            if(c[j]==0 && c[j+1]==1 && c[j+2]==2){
                ++cnt;
                c[j] = 1;
                c[j+1] = 2;
                c[j+2] = 0;
                j += 2;
            }
        }

        res += cnt;
        if(cnt == 0) break;
    }

    cout << res << endl;

    return 0;
}
