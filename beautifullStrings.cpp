#include <bits/stdc++.h>
using namespace std;

int main(){
    string w;
    cin >> w;
    map<char, int> charmap;

    for(int i = 0; i < w.size(); ++i){

        charmap[w[i]]++;
    }

    bool flg = true;

    for(auto elem : charmap){
        
        if(elem.second % 2 == 1) flg = false;
    }
    
    if(flg) cout << "Yes" << endl;
    else cout << "No" << endl;
}