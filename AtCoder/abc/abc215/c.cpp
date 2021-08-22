#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s;
    int k;
    cin >> s >> k;

    vector<int> order;
    for(char c: s){
        order.push_back(c);
    }

    sort(order.begin(), order.end());

    int cnt = 1;
    do{
        if(cnt == k){
            for(char c: order){
                cout << c;
            }
            cout << endl;
            return 0;
        }

        ++cnt;
    } while(next_permutation(order.begin(), order.end()));


    return 0;
}