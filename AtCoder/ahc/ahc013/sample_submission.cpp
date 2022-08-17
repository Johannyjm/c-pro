#include <cassert>
#include <iostream>
#include <map>
#include <random>
#include <utility>
#include <vector>
#include <queue>
#include <algorithm>

#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)

using namespace std;


struct MoveAction {
    int before_row, before_col, after_row, after_col;
    MoveAction(int before_row, int before_col, int after_row, int after_col) : 
        before_row(before_row), before_col(before_col), after_row(after_row), after_col(after_col) {}
};

struct ConnectAction {
    int c1_row, c1_col, c2_row, c2_col;
    ConnectAction(int c1_row, int c1_col, int c2_row, int c2_col) : 
        c1_row(c1_row), c1_col(c1_col), c2_row(c2_row), c2_col(c2_col) {}
};

struct FromTo {
    int from_row, from_col, to_row, to_col;
    FromTo(int from_row, int from_col, int to_row, int to_col) : 
        from_row(from_row), from_col(from_col), to_row(to_row), to_col(to_col) {}
};

struct Result {
    vector<MoveAction> move;
    vector<ConnectAction> connect;
    Result(const vector<MoveAction> &move, const vector<ConnectAction> &con) : move(move), connect(con) {}
};

struct Solver {
    static constexpr char USED = 'x';
    static constexpr int INF = 1001001001;
    static constexpr int dr[4] = {0, 1, 0, -1};
    static constexpr int dc[4] = {1, 0, -1, 0};
    static constexpr int rdr[4] = {0, -1, 0, 1};
    static constexpr int rdc[4] = {-1, 0, 1, 0};

    int n, k;
    int action_count_limit;
    mt19937 engine;
    vector<string> field;

    Solver(int n, int k, const vector<string> &field, int seed = 0) : 
        n(n), k(k), action_count_limit(k * 100), field(field)
    {
        engine.seed(seed);
    }

    bool can_move(int row, int col, int dir) const
    {
        int nrow = row + dr[dir];
        int ncol = col + dc[dir];
        if (0 <= nrow && nrow < n && 0 <= ncol && ncol < n) {
            return field[nrow][ncol] == '0';
        }
        return false;
    }

    vector<MoveAction> move(int move_limit = -1)
    {
        vector<MoveAction> ret;
        if (move_limit == -1) {
            move_limit = k * 50;
        }

        for (int i = 0; i < move_limit; i++) {
            int row = engine() % n;
            int col = engine() % n;
            int dir = engine() % 4;
            if (field[row][col] != '0' && can_move(row, col, dir)) {
                swap(field[row][col], field[row + dr[dir]][col + dc[dir]]);
                ret.emplace_back(row, col, row + dr[dir], col + dc[dir]);
                action_count_limit--;
            }
        }

        return ret;
    }

    vector<MoveAction> move2(int move_limit = -1){
        vector<MoveAction> ret;

        if(move_limit == -1){
            move_limit = k * 50;
        }

        rep(si, n) rep(sj, n){


            if(field[si][sj] == '0') continue;
            
            bool cantmove = true;
            rep(dir, 4){
                if(can_move(si, sj, dir)) cantmove = false;
            }
            if(cantmove) continue;
            
            // BFS
            vector<vector<int>> dist(n, vector<int>(n, INF));
            dist[si][sj] = 0;

            queue<pair<int, int>> q;
            q.push({si, sj});

            char self = field[si][sj];
            vector<pair<pair<int, int>, int>> candidate; // {n_clusters, -n_move, id}

            unordered_map<int, vector<int>> id_ft;

            int num_clusters = count_clusters(si, sj, self, si, sj);
            int id = 0;

            candidate.push_back({{num_clusters, 0}, id});
            id_ft[id] = {si, sj, si, sj};

            while(!q.empty()){
                auto [r, c] = q.front();
                q.pop();

                rep(dir, 4){
                    int nr = r + dr[dir];
                    int nc = c + dc[dir];

                    if(nr<0 || nr>=n || nc<0 || nc>=n) continue;
                    if(field[nr][nc] != '0') continue;
                    if(dist[nr][nc] != INF) continue;

                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr, nc});

                    num_clusters = count_clusters(nr, nc, self, si, sj);
                    
                    ++id;
                    candidate.push_back({{num_clusters, -dist[nr][nc]}, id});
                    
                    id_ft[id] = {si, sj, nr, nc};
                }
            }

            sort(candidate.begin(), candidate.end(), greater<pair<pair<int, int>, int>>());

            if(candidate[0].first.second == 0) continue; // 最初が最適

            int idx = 0;
            while(candidate[idx].first.second > move_limit){
                ++idx;

                if(idx == (int)candidate.size()){
                    return ret;
                }
            }
            vector<int> ft = id_ft[candidate[idx].second];
            vector<MoveAction> subres = fromto2moveaction(ft, dist);
            // cout << candidate[idx].first.second << " " << (int)subres.size() << endl;
            assert(-candidate[idx].first.second == (int)subres.size());

            for(auto ma: subres){
                ret.push_back(ma);
            }

            move_limit -= (int)subres.size();
            action_count_limit -= (int)subres.size();

            swap(field[ft[0]][ft[1]], field[ft[2]][ft[3]]);
        }
    }

    int count_clusters(int i, int j, char self, int si, int sj){
        
        int ret = 1;

        queue<pair<int, int>> q;
        q.push({i, j});

        vector<vector<int>> dist(n, vector<int>(n, INF));
        dist[i][j] = 0;

        while(!q.empty()){
            auto [y, x] = q.front();
            q.pop();

            rep(dir, 4){
                int ny = y + dr[dir];
                int nx = x + dc[dir];

                if(ny<0 || ny>=n || nx<0 || nx>=n) continue;
                if(field[ny][nx] != self) continue;
                if(dist[ny][nx] != INF) continue;
                if(ny==si && nx==sj) continue;

                dist[ny][nx] = dist[y][x] + 1;
                ++ret;

                q.push({ny, nx});                
            }
        }

        return ret;
    }

    vector<MoveAction> fromto2moveaction(vector<int> ft, vector<vector<int>> dist){
        vector<MoveAction> ret;
        int y = ft[2];
        int x = ft[3];

        while(1){

            rep(dir, 4){
                int py = y + dr[dir];
                int px = x + dc[dir];

                if(py<0 || py>=n || px<0 || px>=n) continue;
                if(dist[py][px] != dist[y][x] - 1) continue;

                ret.push_back(MoveAction(py, px, y, x));

                if(py == ft[0] && px == ft[1]){
                    reverse(ret.begin(), ret.end());

                    // for(auto e: ft) cout << e << " ";
                    // cout << endl;
                    // for(auto e: ret){
                    //     cout << e.before_row << " " << e.before_col << " " << e.after_row << " " << e.after_col << endl;
                    // }
                    return ret;
                }

                y = py;
                x = px;
                break;
            }
        }

        cerr << "Something is wrong..." << endl;
    }

    bool can_connect(int row, int col, int dir) const
    {
        int nrow = row + dr[dir];
        int ncol = col + dc[dir];
        while (0 <= nrow && nrow < n && 0 <= ncol && ncol < n) {
            if (field[nrow][ncol] == field[row][col]) {
                return true;
            } else if (field[nrow][ncol] != '0') {
                return false;
            }
            nrow += dr[dir];
            ncol += dc[dir];
        }
        return false;
    }

    ConnectAction line_fill(int row, int col, int dir)
    {
        int nrow = row + dr[dir];
        int ncol = col + dc[dir];
        while (0 <= nrow && nrow < n && 0 <= ncol && ncol < n) {
            if (field[nrow][ncol] == field[row][col]) {
                return ConnectAction(row, col, nrow, ncol);
            }
            assert(field[nrow][ncol] == '0');
            field[nrow][ncol] = USED;
            nrow += dr[dir];
            ncol += dc[dir];
        }
        assert(false);
    }

    vector<ConnectAction> connect()
    {
        vector<ConnectAction> ret;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (field[i][j] != '0' && field[i][j] != 'x') {
                    for (int dir = 0; dir < 2; dir++) {
                        if (can_connect(i, j, dir)) {
                            ret.push_back(line_fill(i, j, dir));
                            action_count_limit--;
                            if (action_count_limit <= 0) {
                                return ret;
                            }
                        }
                    }
                }
            }
        }
        return ret;
    }

    Result solve()
    {
        // create random moves
        auto moves = move2();
        // from each computer, connect to right and/or bottom if it will reach the same type
        auto connects = connect();
        return Result(moves, connects);
    }
};

struct UnionFind {
    map<pair<int,int>, pair<int, int>> parent;
    UnionFind() :parent() {}

    pair<int, int> find(pair<int, int> x)
    {
        if (parent.find(x) == parent.end()) {
            parent[x] = x;
            return x;
        } else if (parent[x] == x) {
            return x;
        } else {
            parent[x] = find(parent[x]);
            return parent[x];
        }
    }

    void unite(pair<int, int> x, pair<int, int> y)
    {
        x = find(x);
        y = find(y);
        if (x != y) {
            parent[x] = y;
        }
    }
};

int calc_score(int N, vector<string> field, const Result &res)
{
    for (auto r : res.move) {
        assert(field[r.before_row][r.before_col] != '0');
        assert(field[r.after_row][r.after_col] == '0');
        swap(field[r.before_row][r.before_col], field[r.after_row][r.after_col]);
    }

    UnionFind uf;
    for (auto r : res.connect) {
        pair<int, int> p1(r.c1_row, r.c1_col), p2(r.c2_row, r.c2_col);
        uf.unite(p1, p2);
    }

    vector<pair<int, int>> computers;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (field[i][j] != '0') {
                computers.emplace_back(i, j);
            }
        }
    }

    int score = 0;
    for (int i = 0; i < (int)computers.size(); i++) {
        for (int j = i+1; j < (int)computers.size(); j++) {
            auto c1 = computers[i];
            auto c2 = computers[j];
            if (uf.find(c1) == uf.find(c2)) {
                score += (field[c1.first][c1.second] == field[c2.first][c2.second]) ? 1 : -1;
            }
        }
    }

    return max(score, 0);
}

void print_answer(const Result &res)
{
    cout << res.move.size() << endl;
    for (auto m : res.move) {
        cout << m.before_row << " " << m.before_col << " "
            << m.after_row << " " << m.after_col << endl;
    }
    cout << res.connect.size() << endl;
    for (auto m : res.connect) {
        cout << m.c1_row << " " << m.c1_col << " "
            << m.c2_row << " " << m.c2_col << endl;
    }
}


int main(){
    
    int n, k;
    cin >> n >> k;
    
    vector<string> field(n);
    rep(i, n) cin >> field[i];

    Solver s(n, k, field);
    auto ret = s.solve();

    cerr << "Score = " << calc_score(n, field, ret) << endl;

    print_answer(ret);

    return 0;
}