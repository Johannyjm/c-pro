#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int N, K;
    cin >> N >> K;
    int A[N], B[N], C[N];
    int res = 0;

    for(int i = 0; i < N; ++i) {
        cin >> A[i] >> B[i];
        C[i] = A[i] - B[i];
    }
    sort(C, C + N, greater<int>());
    for(int i = 0; i < N; ++i) res += A[i];
    for(int i = 0; i < K; ++i) res -= C[i];

    cout << res << endl;
    return 0;
}
