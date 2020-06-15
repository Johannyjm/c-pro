#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){

    multiset<int> mst;
    
    while(1){
        cout << "insert(-1 to break): ";
        int n;
        cin >> n;
        if(n == -1) break;
        mst.insert(n);
        cout << "elements: ";
        for(auto ele: mst) cout << ele << " ";
        cout << endl;
        cout << "top: " << *mst.rbegin() << endl;
    }


    while(1){
        cout << "erase(-1 to break): ";
        int n;
        cin >> n;
        if(n==-1) break;
        mst.erase(mst.find(n));
        cout << "elements: ";
        for(auto ele: mst) cout << ele << " ";
        cout << endl;
        cout << "top: " << *mst.rbegin() << endl;
    }

    return 0;
}