#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_N = 500000;
multiset<ll> TopK, Others;
ll A[MAX_N+1], sumTopK = 0;
int N, K, Q, X, Y;

void add(ll y, int xi){
    if(TopK.size() < K){
        sumTopK += y;
        TopK.insert(y);
    }
    else if(y > *TopK.begin()){
        sumTopK += y - *TopK.begin();
        Others.insert(*TopK.begin());
        TopK.erase(TopK.begin());
        TopK.insert(y);
    }
    else Others.insert(y); 
    A[xi] = y;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K >> Q;
    for(int i=1; i<=N; i++){
        A[i] = 0;
        Others.insert(0);
    }

    while(Q--){
        int X, Y;
        cin >> X >> Y;

        if(A[X] >= *TopK.begin()){
            TopK.erase(TopK.find(A[X]));
            sumTopK -= A[X];
            if(!Others.empty() && Y < *Others.rbegin()){
                sumTopK += *Others.rbegin();
                TopK.insert(*Others.rbegin());
                Others.erase(Others.find(*Others.rbegin()));
            }
        }
        else Others.erase(Others.find(A[X]));

        add(Y, X);
        cout << sumTopK << '\n';
    }
    return 0;
}