#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;


int main(){

    char ans1[8][8] = {
        {'Q', '.', '.', '.', '.', '.', '.', '.'}, 
        {'.', '.', '.', '.', 'Q', '.', '.', '.'}, 
        {'.', '.', '.', '.', '.', '.', '.', 'Q'}, 
        {'.', '.', '.', '.', '.', 'Q', '.', '.'}, 
        {'.', '.', 'Q', '.', '.', '.', '.', '.'}, 
        {'.', '.', '.', '.', '.', '.', 'Q', '.'}, 
        {'.', 'Q', '.', '.', '.', '.', '.', '.'}, 
        {'.', '.', '.', 'Q', '.', '.', '.', '.'}, 
    };

        char ans2[8][8] = {
        {'.', '.', 'Q', '.', '.', '.', '.', '.'}, 
        {'.', '.', '.', '.', '.', 'Q', '.', '.'}, 
        {'.', '.', '.', 'Q', '.', '.', '.', '.'}, 
        {'.', 'Q', '.', '.', '.', '.', '.', '.'}, 
        {'.', '.', '.', '.', '.', '.', '.', 'Q'}, 
        {'.', '.', '.', '.', 'Q', '.', '.', '.'}, 
        {'.', '.', '.', '.', '.', '.', 'Q', '.'}, 
        {'Q', '.', '.', '.', '.', '.', '.', '.'}, 
    };

        char ans3[8][8] = {
        {'.', '.', '.', '.', 'Q', '.', '.', '.'}, 
        {'.', '.', '.', '.', '.', '.', 'Q', '.'}, 
        {'.', 'Q', '.', '.', '.', '.', '.', '.'}, 
        {'.', '.', '.', '.', '.', 'Q', '.', '.'}, 
        {'.', '.', 'Q', '.', '.', '.', '.', '.'}, 
        {'Q', '.', '.', '.', '.', '.', '.', '.'}, 
        {'.', '.', '.', 'Q', '.', '.', '.', '.'}, 
        {'.', '.', '.', '.', '.', '.', '.', 'Q'},  
    };

        char ans4[8][8] = {
        {'.', '.', '.', '.', '.', '.', '.', 'Q'}, 
        {'.', 'Q', '.', '.', '.', '.', '.', '.'}, 
        {'.', '.', '.', 'Q', '.', '.', '.', '.'}, 
        {'Q', '.', '.', '.', '.', '.', '.', '.'}, 
        {'.', '.', '.', '.', '.', '.', 'Q', '.'}, 
        {'.', '.', '.', '.', 'Q', '.', '.', '.'}, 
        {'.', '.', 'Q', '.', '.', '.', '.', '.'}, 
        {'.', '.', '.', '.', '.', 'Q', '.', '.'},  
    };


    vector<vector<char>> c(8, vector<char>(8));
    int one = 0;
    int two = 0;
    int three = 0;
    int four = 0;
    rep(i, 8) rep(j, 8) {
        char a;
        cin >> a;

        if(a=='Q'){
            if(ans1[i][j]=='Q') ++one;
            if(ans2[i][j]=='Q') ++two;
            if(ans3[i][j]=='Q') ++three;
            if(ans4[i][j]=='Q') ++four;
        }
    }

    if(one==3) {
        rep(i, 8) {
            rep(j, 8) cout << ans1[i][j];
            cout << endl;
        }
    }
    else if(two==3) {
        rep(i, 8) {
            rep(j, 8) cout << ans2[i][j];
            cout << endl;
        }
    }
    else if(three==3) {
        rep(i, 8) {
            rep(j, 8) cout << ans3[i][j];
            cout << endl;
        }
    }
    else if(four==3) {
        rep(i, 8) {
            rep(j, 8) cout << ans4[i][j];
            cout << endl;
        }
    }
    else cout << "No Answer" << endl;



    return 0;
}