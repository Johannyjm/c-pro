#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    string s;
    cin >> n >> s;

    vector<char> rgb = {'B', 'G', 'R'};
    map<char, int> mp;
    mp['R'] = 0;
    mp['G'] = 1;
    mp['B'] = 2;

    vector<vector<int>> sum(3, vector<int>(n, 0));
    rep(i, n){
        if(i!=0) {
            rep(j, 3) sum[j][i] = sum[j][i-1];
        }
        if(s[i] == 'R') ++sum[0][i];
        if(s[i] == 'G') ++sum[1][i];
        if(s[i] == 'B') ++sum[2][i];
    }

    // rep(i, 3){
    //     rep(j, n) cout << sum[i][j] << " ";
    //     cout << endl;
    // }

    int res = 0;
    do{
        char one = rgb[0];
        char two = rgb[1];
        char three = rgb[2];

        int ptr = 0;
        for(int i = 0; i < n-2; ++i){
            if(s[i] == one){
                ptr = i;

                for(int j = ptr+1; j < n-1; ++j){
                    if(s[j] == two){
                        // cout << one << " " << two << " " << i << " " << j << " " << sum[mp[three]][n-1] - sum[mp[three]][j] << endl;
                        if(sum[mp[three]][n-1] - sum[mp[three]][j]) {
                            res += sum[mp[three]][n-1] - sum[mp[three]][j];
                            if(j+j-i < n && s[j+j-i] == three) {
                                --res;
                            }
                        

                        }
                    }
                }
            }
        }

    }while(next_permutation(rgb.begin(), rgb.end()));

    cout << res << endl;

    return 0;
}