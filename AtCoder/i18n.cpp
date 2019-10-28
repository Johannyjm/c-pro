#include <bits/stdc++.h>
using namespace std;

int main(){
    string S;
    cin >> S;

    char begin = S[0];
    char end = S[S.length() - 1];
    int num = S.length() - 2;

    cout << begin << num << end << endl;
}