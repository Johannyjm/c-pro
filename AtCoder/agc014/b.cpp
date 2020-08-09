#include <iostream>
#include <map>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    map<int, int> cnt;
    for(int i = 0; i < m; ++i){
        int a, b;
        cin >> a >> b;

        ++cnt[a];
        ++cnt[b];
    }

    for(auto elem: cnt){
        if(elem.second % 2 == 1){
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;

    return 0;
}
