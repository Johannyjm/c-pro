#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> cnt;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        ++cnt[a[i]];
    }
    int res = 0;
    int even = 0;
    for(auto elem: cnt){
        ++res;
        if(elem.second % 2 == 0) ++even;
    }

    if(even % 2 == 1) --res;

    cout << res << endl;


}
