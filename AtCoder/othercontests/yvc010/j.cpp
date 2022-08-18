// #include <bits/stdc++.h>
// #include <atcoder/all
#include <iostream>
#include <vector>
using namespace std;
#define rep(i, n) for (ll i = 0; i < n; ++i)
#define rep2(i,j,n) for(ll i=j;i<n;++i)
#define Sort(a) sort(a.begin(), a.end())
#define Sortr(a) sort(a.rbegin(), a.rend())
using ll = long long;
#define tobit(x, i) (((x) >> (i)) & 1)
#define INF 1001001001001001000
#define yes "Yes"
#define no "No"
// template <class T>

// ll n;
// ll n;
// cin>>n;
// string s(n,'');
int main()
{
	ll n;
	cin>>n;
	vector<ll>a(n+1);
	vector<ll>counter(n+1);
	rep2(i,1,n+1){
		cin>>a[i];
	}
	vector<ll>ans(n+1);
	ll m=0;
	rep(i,n){
		ll j=n-i;
		ans[j]=(a[j]+counter[j])%2;
		if(ans[j]==1){m++;
			rep2(k,1,n+1){
				if(k*k>j)break;
				if(j%k==0){
					counter[k]++;
					counter[j/k]++;
				}
			}
		}
	}
	cout<<m <<endl;
	rep(i,n+1){
		if(ans[i]==1){
			cout<<i <<" ";
		}
	}
	cout<<""<<endl;

	
}