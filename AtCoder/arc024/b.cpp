#include <iostream>
#include <vector>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];

    vector<pair<int, int>> cnt;
    cnt.push_back({a[0], 1});
    for(int i = 1; i < n; ++i){
        if(a[i] == cnt.back().first) ++cnt.back().second;
        else cnt.push_back({a[i], 1});
    }
    
    if(cnt.size() == 1){
        cout << -1 << endl;
        return 0;
    }

    if(cnt.front().first == cnt.back().first){
        cnt.front().second += cnt.back().second;
        cnt.pop_back();
    }

    int max_seq = 0;
    for(int i = 0; i < cnt.size(); ++i){
        max_seq = max(max_seq, cnt[i].second);
    }
    
    cout << (max_seq + 1) / 2 << endl;

    return 0;

}
