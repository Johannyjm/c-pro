#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, k;
    string s;
    cin >> n >> k >> s;

    vector<vector<int>> cnt(26, vector<int>(n, -1));
    for(int i = 0; i < n; ++i){
        cnt[s[i] - 'a'][i] = i+1;
    }

    for(int i = 0; i < 26; ++i){
        for(int j = n-1; j > 0; --j){
            if(cnt[i][j-1] == -1) cnt[i][j-1] = cnt[i][j];
        }
    }

    // for(int i = 0; i < 26; ++i){
    //     for(int j = 0; j < n; ++j) cout << cnt[i][j] << " ";
    //     cout << endl;
    // }

    string res = "";
    int ptr = 0;
    while(res.size() < k){
        for(int i = 0; i < 26; ++i){
            if(cnt[i][ptr] == -1 || cnt[i][ptr] + (k-res.size()) - 1 > n) continue;
            res += char(i + 'a');
            ptr = cnt[i][ptr];
            break;
        }
    }

    cout << res << endl;

    return 0;
}
