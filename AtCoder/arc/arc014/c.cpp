#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> cnt(3, 0);
    for(int i = 0; i < n; ++i){
        if(s[i] == 'R') ++cnt[0];
        else if(s[i] == 'G') ++cnt[1];
        else ++cnt[2];
    }

    cout << cnt[0]%2 + cnt[1]%2 + cnt[2]%2 << endl;

    return 0;
}
