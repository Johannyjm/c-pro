#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
vector<int> x, y;

int calc_s(int i, int j){
    return (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
}

pair<int, int> vec_from_origin(int x1, int y1, int x2, int y2){
    
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    x.assign(n, 0);
    y.assign(n, 0);
    set<pair<int, int>> st;

    rep(i, n){
        cin >> x[i] >> y[i];
        st.insert(make_pair(x[i], y[i]));
    }

    int res = 0;
    for(int i = 0; i < n-1; ++i){
        for(int j = i+1; j < n; ++j){
            int s = calc_s(i, j);

            if(s < res) continue;

            pair<int, int> vec1 = make_pair(x[j]-x[i], y[j]-y[i]);

            vector<pair<int, int>> vec2_cand;

            vec2_cand.push_back(make_pair(vec1.second, -vec1.first));
            vec2_cand.push_back(make_pair(-vec1.second, vec1.first));

            for (pair<int, int> vec2: vec2_cand){
                pair<int, int> vec2_cod = make_pair(vec2.first + x[i], vec2.second + y[i]);

                if(binary_search(st.begin(), st.end(), vec2_cod)){
                    int x1 = vec1.first;
                    int y1 = vec1.second;
                    int x2 = vec2.first;
                    int y2 = vec2.second;

                    pair<int, int> vec3_cod = make_pair(x1+x2+x[i], y1+y2+y[i]);

                    if(binary_search(st.begin(), st.end(), vec3_cod)){
                        res = max(res, s);
                    }
                }
            }
        }
    }

    cout << res << endl;

    return 0;
}