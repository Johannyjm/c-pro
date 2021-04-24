#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;


template< typename T >
struct edge {
  int src, to;
  T cost;

  edge(int to, T cost) : src(-1), to(to), cost(cost) {}

  edge(int src, int to, T cost) : src(src), to(to), cost(cost) {}

  edge &operator=(const int &x) {
    to = x;
    return *this;
  }

  operator int() const { return to; }
};

template< typename T >
using Edges = vector< edge< T > >;
template< typename T >
using WeightedGraph = vector< Edges< T > >;
using UnWeightedGraph = vector< vector< int > >;
template< typename T >
using Matrix = vector< vector< T > >;

int chromatic_number(const Matrix< bool > &g) {
  int N = (int) g.size();
  vector< int > es(N);
  for(int i = 0; i < g.size(); i++) {
    for(int j = 0; j < g.size(); j++) {
      es[i] |= g[i][j] << j;
    }
  }
  int ret = N;
  for(int d : {7, 11, 21}) {
    int mod = 1e9 + d;
    vector< int > ind(1 << N), aux(1 << N, 1);
    ind[0] = 1;
    for(int S = 1; S < 1 << N; S++) {
      int u = __builtin_ctz(S);
      ind[S] = ind[S ^ (1 << u)] + ind[(S ^ (1 << u)) & ~es[u]];
    }
    for(int i = 1; i < ret; i++) {
      int64_t all = 0;
      for(int j = 0; j < 1 << N; j++) {
        int S = j ^(j >> 1);
        aux[S] = (1LL * aux[S] * ind[S]) % mod;
        all += j & 1 ? aux[S] : mod - aux[S];
      }
      if(all % mod) ret = i;

        rep(i, 0<<N) cout << ind[i] << " ";
        cout << endl;
        rep(i, 0<<N) cout << aux[i] << " ";
        cout << endl;
    }
  }

  rep(i, N) cout << es[i] << " ";
  cout << endl;
;
  return ret;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> g(n);
    Matrix<bool> gm(n, vector<bool>(n, 0));
    rep(i, m){
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        g[a].push_back(b);
        g[b].push_back(a);
        gm[a][b] = 1;
        gm[b][a] = 1;
    }

    if(chromatic_number(gm) > 3){
        cout << 0 << endl;
        return 0;
    }

    vector<ll> cnt(n, -1);
    rep(st, n){
        if(cnt[st] != -1) continue;
        
        cnt[st] = 3;
        queue<ll> q;
        q.push(st);
        while(!q.empty()){
            int v = q.front();
            q.pop();

            for(auto nv: g[v]){
                if(cnt[nv] != -1) continue;
                int c = 0;
                for(auto nnv: g[nv]){
                    if(cnt[nnv] != -1) ++c;
                }
                cnt[nv] = max(1, 3 - c);
                q.push(nv);
            }
        }
    }
    ll res = 1;
    rep(i, n) res *= cnt[i];

    cout << res << endl;


    return 0;
}