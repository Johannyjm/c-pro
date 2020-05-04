#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int n, m;
vector<vector<int>> A;

void gene_a(vector<int> arr, int idx, int c){
    if(idx == n) {
        A.push_back(arr);
        return;
    }
    for(int i = c; i <= m; ++i){
        arr[idx] = i;
        gene_a(arr, idx+1, i);
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int q;
    cin >> n >> m >> q;
    vector<int> a(q), b(q), c(q), d(q);
    rep(i, q) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
        --a[i];
        --b[i];
    }

    vector<int> arr(n, 0);
    gene_a(arr, 0, 1);

    int res = 0;
    rep(i, A.size()){
        vector<int> A_cand = A[i];
        int sum = 0;
        rep(j, q){
            if(A_cand[b[j]] - A_cand[a[j]] == c[j]) sum += d[j];
        }

        res = max(res, sum);
    }

    cout << res << endl;

    return 0;
}