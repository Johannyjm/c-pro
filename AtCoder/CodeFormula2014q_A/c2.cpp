#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    
    vector<vector<int>> a(n, vector<int>(k));
    for(int i = 0; i < n; ++i) for(int j = 0; j < k; ++j) cin >> a[i][j];

    vector<int> passlist(n, 0);
    int cnt = 0;
    while(cnt < k){
        ++passlist[cnt % n];
        ++cnt;
    }
    
    vector<vector<bool>> seen(n, vector<bool>(k, false));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < passlist[i]; ++j){
            seen[i][j] = true;
        }
    }

    set<int> st;
    for(int i = 0; i < n; ++i){
        vector<int> pass;
        if(i == 0){
            for(int j = 0; j < passlist[i]; ++j){
                pass.push_back(a[i][j]);
                st.insert(a[i][j]);
            }
        }
        else{
            int dub = 0;
            for(int j = 0; j < passlist[i]; ++j){
                if(st.find(a[i][j]) != st.end()) ++dub;
            }

            if(dub == 0){
                for(int j = 0; j < passlist[i]; ++j) pass.push_back(a[i][j]);
            }
            else{
                for(int j = 0; j < dub; ++j){
                    ++cnt;
                    ++passlist[cnt % k];
                }
                //cout << "passlist: ";
                //for(auto elem: passlist) cout << elem << " ";
                //cout << endl;
                for(int ii = 0; ii <= i; ++ii){
                    for(int j = 0; j < passlist[ii]; ++j){
                        if(seen[ii][j]) continue;
                        if(st.find(a[ii][j]) == st.end()){
                            pass.push_back(a[ii][j]);
                            st.insert(a[ii][j]);
                            seen[ii][j] = true;
                        }
                        else{
                            ++cnt;
                            ++passlist[cnt % k];
                            seen[ii][j] = true;
                        }
                    }
                }
            }

        }

        if(pass.empty()) cout << endl;
        else{
            sort(pass.begin(), pass.end());

            for(int i = 0; i < pass.size()-1; ++i) cout << pass[i] << " ";
            cout << pass.back() << endl;
        }
    }


    return 0;

}
