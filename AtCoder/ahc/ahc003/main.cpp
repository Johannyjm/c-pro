#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

const int h = 30;
const int w = 30;
int D, M;
int hij[900];
int vij[900];



void initialize(int seed=46){
    random_device rnd;
    mt19937 mt;
    mt.seed(rnd());

    uniform_int_distribution<> rand1002000(100, 2000);
    D = rand1002000(mt);
    uniform_int_distribution<> rand12(1, 2);
    M = rand12(mt);

    // int Hip[h][M] = {};
    vector<vector<int>> Hip(h, vector<int>(M, 0));
    uniform_int_distribution<> randHip(1000 + D, 9000 - D);
    rep(i, h) rep(p, M){
        Hip[i][p] = randHip(mt);
    }

    // int xiM[h][M+1] = {};
    vector<vector<int>> xiM(h, vector<int>(M+1, 0));
    uniform_int_distribution<> randxiM(1, 28);
    rep(i, h){
        xiM[i][0] = 0;
        if(M == 1){
            xiM[i][1] = 29;
        }
        if(M == 2){
            xiM[i][1] = randxiM(mt);
            xiM[i][2] = 29;
        }
    }

    // int delta[h][w-1] = {};
    vector<vector<int>> delta(h, vector<int>(w-1, 0));
    uniform_int_distribution<> randdelta(-D, D);
    rep(i, h) rep(j, w-1){
        delta[i][j] = randdelta(mt);
    }

    rep(i, h) rep(p, M) for(int j = xiM[i][p]; j < xiM[i][p+1]; ++j){
        hij[i*w + j] = Hip[i][p] + delta[i][j];
    }

    // int Vjp[w][M] = {};
    vector<vector<int>> Vjp(w, vector<int>(M, 0));
    rep(j, w) rep(p, M){
        Vjp[j][p] = randHip(mt);
    }

    // int yjM[w][M+1] = {};
    vector<vector<int>> yjM(w, vector<int>(M+1, 0));
    rep(j, w){
        yjM[j][0] = 0;
        if(M == 1){
            yjM[j][1] = 29;
        }
        if(M == 2){
            yjM[j][2] = 29;
            yjM[j][1] = randxiM(mt);
        }
    }

    // int gamma[h-1][w] = {};
    vector<vector<int>> gamma(h-1, vector<int>(w, 0));
    rep(i, h-1) rep(j, w){
        gamma[i][j] = randdelta(mt);
    }

    rep(j, w) rep(p, M) for(int i = yjM[j][p]; i < yjM[j][p+1]; ++i){
        vij[i*w + j] = Vjp[j][p] + gamma[i][j];
    }
}

const int INF = 1001001001;
const int dy[] = {1, 0, -1, 0};
const int dx[] = {0, 1, 0, -1};
vector<int> dijkstra(int sy, int sx){
    vector<int> ret(h*w, INF);
    ret[sy*w + sx] = 0;
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    pq.push({0, {sy, sx}});

    while(!pq.empty()){
        auto now = pq.top();
        pq.pop();
        int dist = now.first;
        auto [y, x] = now.second;

        if(ret[y*w + x] != dist) continue;

        rep(dir, 4){
            int ny = y + dy[dir];
            int nx = x + dx[dir];

            if(ny<0 || ny>=h || nx<0 || nx>=w) continue;

            int cost;
            if(dir % 2 == 0){
                cost = vij[y*w + x];
            }
            else{
                cost = hij[y*w + x];
            }

            if(ret[ny*w + nx] > ret[y*w + x] + cost){
                ret[ny*w + nx] = ret[y*w + x] + cost;
                pq.push({ret[ny*w + nx], {ny, nx}});
            }
        }

    }

    return ret;

}

char cmd[] = {'U', 'L', 'D', 'R'};
vector<pair<int, int>> reconstruction(vector<int> dist, int sy, int sx, int ty, int tx){
    vector<pair<int, int>> ret;
    ret.push_back({ty, tx});
    string pk = "";

    pair<int, int> now = {ty, tx};
    while(!(now.first == sy && now.second == sx)){
        int y = now.first;
        int x = now.second;

        int py, px;
        rep(dir, 4){
            py = y + dy[dir];
            px = x + dx[dir];

            if(py<0 || py>=h || px<0 || px>=w) continue;

            int diff;
            if(dir % 2 == 0){
                diff = vij[py*w + px];
            }
            else{
                diff = hij[py*w + px];
            }

            if(dist[y*w + x] - dist[py*w + px] > 0 && dist[y*w + x] - dist[py*w + px] == diff){
                pk += cmd[dir];
                ret.push_back({py, px});
                break;
            }
        }
        now = {py, px};
    }
    for(int i = (int)pk.size()-1; i >= 0; --i) cout << pk[i];
    cout << endl;
    reverse(ret.begin(), ret.end());

    return ret;
}

void update(int sy, int sx, vector<pair<int, int>> indices, pair<int, int> scale){
    int y = sy;
    int x = sx;
    rep1(i, (int)indices.size()){
        pair<int, int> p = indices[i];
        int ny = p.first;
        int nx = p.second;

        if(y == ny){
            hij[y*w + x] = hij[y*w + x] * scale.first / scale.second;
        }
        else{
            vij[y*w + x] = vij[y*w + x] * scale.first / scale.second;
        }

        y = ny;
        x = nx;
    }
}

void printmat(){
    rep(i, h){
        rep(j, w) cout << hij[i*w + j] << " ";
        cout << endl;
    }
    cout << endl;
    cout << endl;
    rep(i, h){
        rep(j, w) cout << vij[i*w + j] << " ";
        cout << endl;
    }
    cout << endl;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    initialize();



    int t = 1000;
    while(t--){

        // printmat();

        int sy, sx, ty, tx;
        cin >> sy >> sx >> ty >> tx;
        
        vector<int> dist = dijkstra(sy, sx);

        // cout << dist[ty*w + tx] << endl;

        vector<pair<int, int>> indices = reconstruction(dist, sy, sx, ty, tx);

        int dist_hat = dist[ty*w + tx];
        int dist_true;
        cin >> dist_true;
        pair<int, int> scale = {dist_true, dist_hat};

        update(sy, sx, indices, scale);
    }


    return 0;
}