#include <bits/stdc++.h>
using namespace std;

int d(int num){
    int cnt = 1;
    while(num/10){
        num /= 10;
        cnt++;
    }
    return cnt;
}

bool is_squared(int num){
    for(int i = 1; i*i <= num; ++i){
        if(i*i==num) return true;
    }
    return false;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int a, b;
    cin >> a >> b;
    
    for (int i = 0; i < d(b); ++i) a *= 10;

    if(is_squared(a+b)) cout << "Yes" << endl;
    else cout << "No" << endl;


}