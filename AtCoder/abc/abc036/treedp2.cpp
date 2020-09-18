#include <iostream>
#include <vector>
using namespace std;

int merge(int 

int rec(int v, int prev){
    
}

vector<vector<int>> g;
int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    int n;
    cin >> n;
    g.resize(n);
    for(int i = 0; i < n-1; ++i){
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    int r;
    --r;

    cout << rec(r, -1) << endl;

    return 0;
}
