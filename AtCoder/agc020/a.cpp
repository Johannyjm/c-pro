#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, a, b;
    cin >> n >> a >> b;
    vector<int> board(n, 0);
    board[a-1] = 1;
    board[b-1] = 1;
    int player = 1; // 1: A, 0: B

    int ptr_a = a-1;
    int ptr_b = b-1;

    while(1){
        if(player){
            if(board[ptr_a+1] == 0){
                board[ptr_a+1] = 1;
                ++ptr_a;
            }
            else{
                if(ptr_a == 0){
                    puts("Borys");
                    return 0;
                }
                board[ptr_a] = 0;
                --ptr_a;
            }
        }
        else{
            if(board[ptr_b-1] == 0){
                board[ptr_b-1] = 1;
                --ptr_b;
            }
            else{
                if(ptr_b == n-1){
                    puts("Alice");
                    return 0;
                }
                board[ptr_b] = 0;
                ++ptr_b;
            }
        }
        player = 1 - player;
    }

    return 0;
}