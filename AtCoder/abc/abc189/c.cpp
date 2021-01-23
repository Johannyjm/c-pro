#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
	cin >> n;
    vector<ll> a(n);
	rep(i, n) cin >> a[i];
    stack<ll> st;
    vector<ll> l(110000), r(110000);

	rep(i, n){
		while(st.empty() == false && a[st.top()] >= a[i])st.pop();
		if(st.empty()){
			l[i] = 0;
		}else{
			l[i] = st.top()+1;
		}
		st.push(i);
	}

	while(!st.empty()) st.pop();

	for(int i = n-1; i >= 0; i--){
		while(st.empty() == false && a[st.top()] >= a[i])st.pop();
		if(st.empty()){
			r[i] = n-1;
		}
        else{
			r[i] = st.top()-1;
		}
		st.push(i);
	}

	ll res = 0;
	rep(i, n) res = max(res, a[i]*(r[i]-l[i]+1));

    cout << res << endl;

	return 0;


    return 0;
}