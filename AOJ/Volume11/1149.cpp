#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    while(1){
        int n, w, d;
        cin >> n >> w >> d;

        if(n+w+d == 0) break;

        vector<pair<int, int>> cakes;
        cakes.push_back(make_pair(w, d));

        rep(i, n){
            int p, s;
            cin >> p >> s;
            --p;

            pair<int, int> pa = cakes[p];
            int cw = pa.first;
            int cd = pa.second;

            s %= 2*(cw + cd);

            if(0<s && s<=cw || cw+cd<s && s<=2*cw+cd){ // vertical
                int v_pos = s;
                if(cw+cd < s) v_pos = cw-(s-(cw+cd));

                int nw1 = min(v_pos, cw-v_pos);
                int nw2 = cw - nw1;

                if(p == i){
                    cakes[p] = make_pair(nw1, cd);
                    cakes.push_back(make_pair(nw2, cd));
                }
                
                else{
                    cakes.erase(cakes.begin()+p);
                    cakes.push_back(make_pair(nw1, cd));
                    cakes.push_back(make_pair(nw2, cd));
                }
            }

            else{ // horizontal
                int h_pos = s - cw;
                if(2*cw+cd < s) h_pos = cd-(s-(2*cw+cd));

                int nd1 = min(h_pos, cd-h_pos);
                int nd2 = cd - nd1;

                if(p == i){
                    cakes[p] = make_pair(cw, nd1);
                    cakes.push_back(make_pair(cw, nd2));
                }

                else{
                    cakes.erase(cakes.begin()+p);
                    cakes.push_back(make_pair(cw, nd1));
                    cakes.push_back(make_pair(cw, nd2));
                }

            }

        }

        vector<int> res;
        rep(i, cakes.size()){
            res.push_back(cakes[i].first * cakes[i].second);
        }
        sort(res.begin(), res.end());

        rep(i, res.size()){
            if(i!=res.size()-1) cout << res[i] << " ";
        }
        cout << res.back() << endl;
    }

    return 0;
}