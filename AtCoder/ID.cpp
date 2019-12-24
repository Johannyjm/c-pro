#include <bits/stdc++.h>
using namespace std;

int d(int num){
    int cnt = 1;
    while(num / 10){
        num /= 10;
        cnt++;
    }
    return cnt;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    pair <pair<int, int>, int> id[m];

    for (int i = 0; i < m; ++i){
        int p, y;
        cin >> p >> y;
        id[i] = make_pair(make_pair(p, y), i);
    }
    sort(id, id + m);
    
    pair <int, pair<int, int>> res[m];
    int cnt = 1;
    int prev = -1;
    for(int i = 0; i < m; ++i){
        // cout << id[i].first.first << " " << id[i].first.second << " " << id[i].second << endl;

        if(id[i].first.first != prev) cnt = 1;
        res[i] = make_pair(id[i].second, make_pair(id[i].first.first, cnt));
        cnt++;
        prev = id[i].first.first;
    }

    sort(res, res + m);

    for(int i = 0; i < m; ++i){
        //cout << res[i].first << " " << res[i].second.first << " " << res[i].second.second << endl;
    }

    for(int i = 0; i < m; ++i){
        int left = res[i].second.first;
        int right = res[i].second.second;
        int ld = d(left);
        int rd = d(right);
        
        for(int j = 0; j < 6-ld; ++j) cout << 0;
        cout << left;
        for(int j = 0; j < 6-rd; ++j) cout << 0;
        cout << right << endl; 
    }
    return 0;
}