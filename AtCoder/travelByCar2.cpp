#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N, M, L;
    cin >> N >> M >> L;
    int** cost_graph = (int**)malloc(N * sizeof(int*));

    for(int i = 0; i < N; ++i){
        cost_graph[i] = (int*)malloc(N * sizeof(int));

        for(int j = 0; j < N; ++j){
            cost_graph[i][j] = -999;
        }
    }

    int A, B, C;

    for (int i = 0; i < N; ++i){
        cin >> A >> B >> C;
        cost_graph[A - 1][B - 1] = C;
        cost_graph[B - 1][A - 1] = C;
    }

    int Q;
    cin >> Q;
    int s, t

    for (int i = 0; i < Q; ++i){
        cin >> s >> t;

        

    }
    

}