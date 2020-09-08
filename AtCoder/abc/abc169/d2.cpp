#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

#define N 1000000
ll arr[N];

//エラトステネスの篩
void Eratosthenes(){
	for(int i = 0; i < N; i++){
		arr[i] = 1;
	}
	for(int i = 2; i < sqrt(N); i++){
		if(arr[i]){
			for(int j = 0; i * (j + 2) < N; j++){
				arr[i *(j + 2)] = 0;
			}
		}
	}

	for(int i = 2; i < N; i++){
		if(arr[i]){
			// cout << i << endl;
		}
	}
}

bool is_prime(ll n){
    if(n == 1) return false;
    
    for(int i = 2; i*i <= n; ++i){
        if(n%i == 0) return false;
    }

    return true;
}


int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n;
    cin >> n;

    if(n==1){
        cout << 0 << endl;
        return 0;
    }
    if(is_prime(n)){
        cout << 1 << endl;
        return 0;
    }
    
    Eratosthenes();
    set<ll> st;
    for(int i = 2; i < 1000000; ++i){

        if(arr[i] == 0) continue;
        ll cnt = 1;
        while(pow(i, cnt) <= n){
            st.insert(pow(i, cnt));
            ++cnt;
        }
    }

    // cout << st.size() << endl;
    // for(auto ele: st){
    //     cout << ele << " ";
    // }
    // cout << endl;

    int res = 0;
    for(auto ele: st){
        // cout << n << " " << is_prime(n) << endl;
        if(n%ele == 0){
            n /= ele;
            ++res;
        }

        if(is_prime(n)){
            cout << res << endl;
            return 0;
        }
    }
    
    cout << res << endl;

    return 0;
}