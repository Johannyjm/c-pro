#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s;
    int k;
    cin >> s >> k;
    int n = s.size();

    vector<pair<char, int>> comp;
    comp.push_back({s[0], 1});
    for(int i = 1; i < n; ++i){
        if(s[i] == comp.back().first) ++comp.back().second;
        else comp.push_back({s[i], 1});
    }

    vector<pair<int, pair<int, int>>> dots;
    int leftx = 0;
    for(int i = 0; i < (int)comp.size(); ++i){
        if(comp[i].first == 'X'){
            leftx = comp[i].second;
            continue;
        }
        int rightx = 0;
        if(i != (int)comp.size()-1) rightx = comp[i+1].second;

        dots.push_back({comp[i].second, {leftx, rightx}});
    }

    // for(auto e: dots) cout << e.first << " " << e.second.first << " " << e.second.second << endl;

    int res = 0;
    for(int i = 0; i < (int)dots.size(); ++i){
        
    }

    return 0;
}
