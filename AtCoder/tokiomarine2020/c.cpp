#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

#define NUM 300005

ll uniformity[8*NUM],partial[8*NUM];
ll N = 1;

void init(ll first_N){
	while(N < first_N)N *= 2;
}

void add(ll left,ll right,ll value,ll node_id,ll node_left,ll node_right){

	if(right <= node_left || left >= node_right)return;
	else if(left <= node_left && right >= node_right){
		uniformity[node_id] += value;
	}else{
		partial[node_id] += (min(right,node_right)-max(left,node_left))*value;
		add(left,right,value,2*node_id+1,node_left,(node_left+node_right)/2);
		add(left,right,value,2*node_id+2,(node_left+node_right)/2,node_right);
	}
}

ll getSum(ll left,ll right,ll node_id,ll node_left,ll node_right){
	if(right <= node_left || left >= node_right)return 0;
	else if(left <= node_left && right >= node_right){
		return (node_right-node_left)*uniformity[node_id]+partial[node_id];

	}else{
		ll sum = (min(right,node_right)-max(left,node_left))*uniformity[node_id];

		sum += getSum(left,right,2*node_id+1,node_left,(node_left+node_right)/2);
		sum += getSum(left,right,2*node_id+2,(node_left+node_right)/2,node_right);
		return sum;
	}
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    init(n);
	for(ll i = 0; i <= 2*n-2; i++){
		uniformity[i] = 0;
		partial[i] = 0;
	}

    rep(i, n){
        add(i, i+1, a[i], 0, 0, n);
    }

    rep(c, 200){
        if(c == k) break;
        vector<pair<ll, ll>> addd(n);
        rep(i, n){
            int l = max(i - getSum(i, i+1, 0, 0, n), 0ll);
            int r = min(i + getSum(i, i+1, 0, 0, n), n-1);
            cout << l << " " << r << endl;

            addd[i] = make_pair(l, r);
        }

        rep(i, n){
            int l = addd[i].first;
            int r = addd[i].second;
            cout << l << " " << r << endl;

            add(l, r+1, 1, 0, 0, n);
        }
        rep(i, n) cout << getSum(i, i+1, 0, 0, n) << " ";
        cout << endl;

    }

    rep(i, n-1){
        cout << getSum(i, i+1, 0, 0, n) << " ";
    }
    cout << getSum(n-1, n, 0, 0, n) << endl;



    return 0;
}