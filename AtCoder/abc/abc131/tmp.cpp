#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
#include <cstdint>
#include <string>
#include <sstream>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
#define rep(i,n) for (int i = 0; i < (n); ++i)
typedef long long ll;
using P = pair<int,int>;
const int INF=1001001001;
const int mod =1e9+7;

int main() {
  int N,K;
  cin>>N>>K;
  int mx=(N-1)*(N-2)/2;
  if(mx<K){cout<<-1<<endl;return 0;}
  vector<pair<int,int>>ans;
  for(int i=0;i<N-1;i++){
    ans.push_back(make_pair(i+1,N));
  }
  int res=mx-K;
  vector<pair<int,int>>e;
  for(int i=0;i<N-1;i++){
    for(int j=0;j<i;j++){
      e.push_back(make_pair(i+1,j+1));
    }
  }
  for(int i=0;i<res;i++){
    ans.push_back(e[i]);
  }
  cout<<ans.size()<<endl;
  for(int i=0;i<ans.size();i++){
    cout<<ans[i].first<<" "<<ans[i].second<<endl;
  }
  return 0;
}
