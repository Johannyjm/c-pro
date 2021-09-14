#include <iostream>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    int q = 0;
    pair<int, int> now = {0, 0};

    for(char c: s){
        if(c == 'U') --now.first;
        if(c == 'D') ++now.first;
        if(c == 'L') --now.second;
        if(c == 'R') ++now.second;
        if(c == '?') ++q;
    }

    int t;
    cin >> t;
    int dist = abs(now.first) + abs(now.second);
    if(t == 1) cout << dist + q << endl;
    if(t == 2){
        
        if(dist >= q) cout << dist - q << endl;
        else if(s.size() % 2 == 0) cout << 0 << endl;
        else cout << 1 << endl;
    }

    return 0;
}
