#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int h, w;
    cin >> h >> w;
    vector<string> grid(h);
    for(int i = 0; i < h; ++i) cin >> grid[i];

    const int INF = 1001001001;
    vector<vector<int>> dist(h, vector<int>(w, INF));
    dist[0][0] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});

    while(!q.empty()){
        pair<int, int> p = pq.top();
        pq.pop();

        int v = p.second;

        
    }

    cout << 0 << endl;

    return 0;
}
