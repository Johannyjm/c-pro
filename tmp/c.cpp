#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n);
    for(int i = 0; i < m; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        --a;
        --b;

        g[a].push_back(b);
        g[b].push_back(a);
    }


    return 0;
}
