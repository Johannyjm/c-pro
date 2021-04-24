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
    }
  }
  return ret;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    Matrix<bool> g(n, vector<bool>(n, 0));
    rep(i, m){
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        g[a][b] = 1;
        g[b][a] = 1;
    }

    cout << chromatic_number(g) << endl;

    return 0;
}