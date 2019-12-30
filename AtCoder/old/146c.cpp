#include <bits/stdc++.h>
using namespace std;
using ULL = unsigned long long;

inline int d(ULL N) {
    return to_string(N).size();
}

ULL cost(ULL A, ULL B, ULL N) {
    return (A * N + B * d(N));
}

ULL resolver(ULL A, ULL B, ULL X, ULL start, ULL end) {
    ULL l = start;
    ULL r = end;
    ULL m = (l + r) / 2;

    while ((r - l) > 1)
    {
        /* code */
        if(cost(A, B, m) > X) {
            r = m;
        }
        else
        {
            /* code */
            l = m;
        }
        m = (l + r) / 2;
    }

    if (cost(A, B, r) > X)
    {
        /* code */
        return l;
    }
    else
    {
        return r;
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ULL A, B, X;
    cin >> A >> B >> X;

    if ((A * 1 + B * 1) > X)
    {
        /* code */
        cout << 0 << endl;
        return 0;
    }

    cout << resolver(A, B, X, 1, 1000000000) << endl;    
    return 0;
}