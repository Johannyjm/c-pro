#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    rep(i, n) cin >> a[i];

    int up_seq = 1;
    vector<int> up_seqs;
    rep1(i, n){
        if(a[i] > a[i-1]) ++up_seq;
        else{
            up_seqs.push_back(up_seq);
            up_seq = 1;
        }
    }

    up_seqs.push_back(up_seq);

    int res = 0;
    rep(i, up_seqs.size()){
        if(up_seqs[i] >= k){
            res += up_seqs[i] - k + 1;
        }
    }

    cout << res << endl;

    return 0;
}