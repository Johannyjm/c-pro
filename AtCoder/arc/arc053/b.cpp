#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    
    vector<int> cnt(26, 0);
    for(int i = 0; i < s.size(); ++i) ++cnt[s[i] - 'a'];

    int res = s.size();
    vector<int> odds, evens;
    int cnt_odd = 0;
    int cnt_even = 0;
    for(int i = 0; i < 26; ++i){
        if(cnt[i]!=0 && cnt[i]%2==0){
            ++cnt_even;
            evens.push_back(cnt[i]);
        }
        if(cnt[i]%2 == 1){
            ++cnt_odd;
            odds.push_back(cnt[i]);
        }
    }

    if(cnt_odd != 0){
        cout << res << endl;
        return 0;
    }


    sort(cnt.begin(), cnt.end());

    cout << cnt[cnt_even] << endl;

}
