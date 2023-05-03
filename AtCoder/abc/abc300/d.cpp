#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;

const int MAXN = 10000000;

// エラトステネスの篩を用いて素数を列挙する関数
vector<int> primes(int n) {
    vector<int> p(n+1, 1);
    vector<int> res;
    p[0] = p[1] = 0;
    for (int i = 2; i <= n; i++) {
        if (p[i]) {
            res.push_back(i);
            for (int j = i*2; j <= n; j += i) {
                p[j] = 0;
            }
        }
    }
    return res;
}

int main() {
    ll N;
    cin >> N;

    // エラトステネスの篩を用いて素数を列挙する
    int sqrtN = sqrt(N);
    vector<int> ps = primes(sqrtN);

    int k = ps.size();
    ll ans = 0;

    // 2乗数平方分割の実装
    for (int i = 0; i < k; i++) {
        ll p1 = ps[i];
        if (p1 * p1 * p1 * p1 > N) {
            break;
        }
        for (int j = i+1; j < k; j++) {
            ll p2 = ps[j];
            if (p1 * p1 * p2 * p2 > N) {
                break;
            }
            for (int l = j+1; l < k; l++) {
                ll p3 = ps[l];
                if (p1 * p1 * p2 * p3 * p3 > N) {
                    break;
                }

                // cout << p1 << " " << p2 << " " << p3 << endl;
                ans++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}