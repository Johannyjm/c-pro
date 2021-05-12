#include <iostream>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

int n, q;
ll l;
vector<ll> a;
vector<vector<pair<ll, ll>>> ts;
vector<int> k;

ll estimator(ll t, ll s, ll scatter){
  ll ok = 1001001;
  ll ng = -1;
  while(ok - ng > 1){
    ll mid = (ok + ng) / 2;
    if((mid * mid + 2 * s * mid - mid) / 2 >= scatter) ok = mid;
    else ng = mid;
  }
  return t + ok;
}

bool check(ll m){
  ll sm = 0;
  for(int i = 0; i < n; ++i){
    ll mn = 1ll << 60;

    // already clean
    if(a[i] <= l) continue;

    for(int j = 0; j < k[i]; ++j){
      ll time = ts[i][j].first;
      ll ability = ts[i][j].second;
      ll scat = a[i];

      time = estimator(time, ability, scat-l);
      
      mn = min(mn, time);
    }
    sm += mn;
  }
  return sm <= m;
}

int main(){
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int step;
  cin >> step;
  
  // step 1
  if(step == 1){
    cin >> n;
    a.resize(n);
    for(int i = 0; i < n; ++i) cin >> a[i];

    ts.resize(n);
    k.resize(n);
    for(int i = 0; i < n; ++i){
      cin >> k[i];
      for(int j = 0; j < k[i]; ++j){
        ll t, s;
        cin >> t >> s;
        ts[i].push_back({t, s});
      }
    }

    ll res = 0;
    for(int i = 0; i < n; ++i){
      ll mn = 1ll << 60;
      for(int j = 0; j < k[i]; ++j){
        ll time = ts[i][j].first;
        ll ability = ts[i][j].second;
        ll scat = a[i];

        //binary search in O(log(sqrt(n)))
        time = estimator(time, ability, scat);

        // // greedy in O(sqrt(n))
        // while(1){
        //   scat -= ability;
        //   ++time;
        //   if(scat <= 0) break;
        //   ++ability;
        // }

        mn = min(mn, time);
      }
      res += mn;
    }

    cout << res << endl;
  }

  // step 2
  if(step == 2){
    cin >> n;
    a.resize(n);
    for(int i = 0; i < n; ++i) cin >> a[i];

    ts.resize(n);
    k.resize(n);
    for(int i = 0; i < n; ++i){
      cin >> k[i];
      for(int j = 0; j < k[i]; ++j){
        ll t, s;
        cin >> t >> s;
        ts[i].push_back({t, s});
      }
    }

    cin >> q;
    for(int i = 0; i < q; ++i){
      cin >> l;

      ll ok = 1001001001;
      ll ng = -1;
      while(ok - ng > 1){
        ll mid = (ok + ng) / 2;
        
        if(check(mid)) ok = mid;
        else ng = mid;
      }

      cout << ok << endl;
    }

  }

  return 0;
}






bool check2(ll m){
  ll ok = 1ll << 60;
  ll ng = -1;

  while(ok - ng > 1){
    ll mid = (ok + ng) / 2;

    if(check3(mid)) ok = mid;
    else ng = mid;
  }

  return ok <= t;
}

bool check3(ll m){
  ll mx = 0;
  for(int i = 0; i < n; ++i){
    ll mn = 1ll << 60;

    // already clean
    if(a[i] <= m) continue;

    for(int j = 0; j < k[i]; ++j){
      ll time = ts[i][j].first;
      ll ability = ts[i][j].second;
      ll scat = a[i];

      time = estimator(time, ability, scat-m);
      
      mn = min(mn, time);
    }
    sm += mn;
  }
  return sm <= m;
}