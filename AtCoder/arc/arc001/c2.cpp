#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;
const int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
const int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

bool available[8][8] = {};
void init(){
    rep(i, 8) rep(j, 8) available[i][j] = true;
}

void apply(int i, int j){
    available[i][j] = false;
    rep(dir, 8){
        int di = i;
        int dj = j;
        while(1){
            di += dy[dir];
            dj += dx[dir];
            if(di<0||di>=8||dj<0||dj>=8) break;
            available[di][dj] = false;
        }
    }
}

int main(){

    char c[8][8];
    init();
    int idx_fixed[3][2];

    int cnt = 0;
    rep(i, 8) rep(j, 8) {
        char a;
        cin >> a;
        c[i][j] = a;
        if(a=='Q') {
            idx_fixed[cnt][0] = i;
            idx_fixed[cnt][1] = j;
            ++cnt;

            if(available[i][j]) apply(i, j);
            else{
                cout << "No Answer" << endl;
                return 0;
            }
        }
    }

    



    return 0;
}