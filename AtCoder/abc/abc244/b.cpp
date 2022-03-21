#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    string t;
    cin >> t;

    int x = 0;
    int y = 0;
    int dir = 0;

    for(char c: t){
        if(c == 'S'){
            x += dx[dir];
            y += dy[dir];
        }
        if(c == 'R'){
            ++dir;
            dir %= 4;
        }
    }

    cout << x << " " << y << endl;

    return 0;
}