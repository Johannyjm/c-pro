#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> even, odd;
    rep(i, n){
        int a;
        cin >> a;
        if(i%2==0) odd.push_back(a);
        else even.push_back(a);
    }

    if(n%2==1) swap(even, odd);

    reverse(even.begin(), even.end());

    rep(i, (int) even.size()) cout << even[i] << " ";
    rep(i, (int) odd.size()) cout << odd[i] << " ";
    cout << endl;

    return 0;
}