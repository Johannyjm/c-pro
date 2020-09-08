#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> x(n), y(n);
    set<pair<int, int>> st;
    rep(i, n){
        cin >> x[i] >> y[i];
        st.insert(make_pair(x[i], y[i]));
    }

    int res = 0;
    for(int i = 0; i < n-1; ++i){
        for(int j = 0; j < n; ++j){
            pair<int, int> vec1 = make_pair(x[j] - x[i], y[j] - y[i]);
            int s = (x[j]-x[i])*(x[j]-x[i]) + (y[j]-y[i])*(y[j]-y[i]);

            if(s < res) continue;

            vector<pair<int, int>> vec2_cand(2);
            vec2_cand[0] = make_pair(vec1.second, -vec1.first);
            vec2_cand[1] = make_pair(-vec1.second, vec1.first);

            rep(k, 2){
                pair<int, int> vec2 = vec2_cand[k];
                if(binary_search(st.begin(), st.end(), make_pair(vec2.first + x[i], vec2.second + y[i]))){ // vec2 exists
                    
                    pair<int, int> vec3 = make_pair(vec1.first + vec2.first, vec1.second + vec2.second);

                    if(binary_search(st.begin(), st.end(), make_pair(vec3.first + x[i], vec3.second + y[i]))){ // vec3 exists
                        res = max(res, s);
                    }
                }
            }
        }
    }

    cout << res << endl;

    return 0;
}