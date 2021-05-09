#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <queue>

const int INF = 1001001001;

using namespace std;

string i2s(int num){
    string ret = "";
    while(num){
        ret += char('0' + num % 10);
        num /= 10;
    }
    reverse(ret.begin(), ret.end());

    return ret;
}

class Cell {
public:
    Cell () {
        neighbors.resize(6);
    }
    Cell (int cell_index, int richness, int neighbors) :
    cell_index{cell_index}, richness{richness}, neighbors{neighbors} {}

    void input() {
        cin >> cell_index >> richness;
        for (auto& n: neighbors) {
            cin >> n;
            neighbors_set.insert(n);
        }
    }
    int cell_index;
    int richness;
    vector<int> neighbors;
    unordered_set<int> neighbors_set;
};

class Tree {
public:
    Tree () = default;
    Tree (int cell_index, int size, int is_mine, int is_dormant) :
        cell_index{cell_index}, size{size}, is_mine{is_mine}, is_dormant{is_dormant} {}
    void input() {
        int cellIndex;
        int size;
        bool isMine;
        bool isDormant;
        cin >> cellIndex >> size >> isMine >> isDormant;
    }
    int cell_index;
    int size;
    int is_mine;
    int is_dormant;
};

class Game {
private:
        int day = 0;
        int nutrients = 0;
        vector<Cell> board;
        vector<Tree> trees;
        vector<pair<string,int>> possible_actions;
        int mySun;
        int oppSun;
        int score;
        int oppScore;
        int oppIsWaiting;

public:
    int numberOfCells;
    void inputInitData() {
        cin >> numberOfCells;
        for (int i = 0; i < numberOfCells; i++) {
            Cell cell;
            cell.input();
            board.push_back(cell);
        }
    }

    void inputInfo() {
        // input game info
        cin >> day;
        cin >> nutrients;
        cin >> mySun >> score;
        cin >> oppSun >> oppScore >> oppIsWaiting;

        // input trees info
        trees.clear();
        int numberOfTrees;
        cin >> numberOfTrees;
        for (int i = 0; i < numberOfTrees; i++) {
            Tree tree;
            tree.input();
            trees.push_back(tree);
        }

        // input possible actions
        possible_actions.clear();
        int numberOfPossibleMoves;
        cin >> numberOfPossibleMoves;
        for (int i = 0; i < numberOfPossibleMoves; i++) {
            string type;
            int index = 0;
            cin >> type;
            if (type == "COMPLETE") {
                cin >> index;
                possible_actions.emplace_back(type, index);
            }
        }
    }

    vector<int> search_seedable(int start, int size){

        if(board[start].cell_index != start){
            cerr << "board[start].cell_index != start" << endl;
            return {};
        }

        vector<int> dist(numberOfCells, INF);
        dist[start] = 0;
        queue<int> q;
        q.push(start);
        while(!q.empty()){
            Cell v = board[q.front()];
            q.pop();

            for(int nv: v.neighbors){
                if(nv == -1) continue;
                if(dist[nv] != INF) continue;

                dist[nv] = dist[v.cell_index] + 1;
                q.push(nv);
            }
        }

        vector<int> ret;
        for(int i = 0; i < numberOfCells; ++i){
            if(dist[i] == size) ret.push_back(i);
        }

        return ret;
    }

    string compute_next_action() {
        string action = "WAIT"; // default
        
        vector<int> cnt(4, 0);
        int mytree = 0;
        for(auto tree: trees){
            int a;
            if(tree.is_mine == 0) continue;
            if(tree.is_dormant == 1) continue;
            if(tree.size == 0) ++cnt[0];
            if(tree.size == 1) ++cnt[1];
            if(tree.size == 2) ++cnt[2];
            if(tree.size == 3) ++cnt[3];
            ++mytree;
            // ++cnt[int(tree.size)];
            // if(tree.size == 0) continue;

            // vector<pair<int, int>> candidate;
            // if(tree.size == 1){
            //     for(auto cell: board){
            //         if(cell.neighbors_set.count(tree.cell_index) == 0) continue;
                    
            //     }
            // }
        }

        // case1: few trees -> firstly seed
        if(mytree < 7){
            // case1-1: few origin trees -> firstly grow
            if(cnt[2] == 0 && cnt[3] == 0){
                for(auto tree: trees){
                    if(!tree.is_mine) continue;
                    if(tree.size == 1){
                        action = "GROW ";
                        action += i2s(tree.cell_index);
                        return action;
                    }
                }
                for(auto tree: trees){
                    if(!tree.is_mine) continue;
                    if(tree.size == 0){
                        action = "GROW ";
                        action += i2s(tree.cell_index);
                        return action;
                    }
                }
            }

            // case1-2: seed
            // from the tree its size of 2 or 3, to the cell "no tree", "less neighbors"
            else{
                for(auto tree: trees){
                    if(!tree.is_mine) continue;
                    if(tree.is_dormant) continue;

                    vector<int> seedable = search_seedable(tree.cell_index, tree.size);

                    vector<pair<int, int>> candidate;
                    for(auto to: seedable){
                        bool ng = false;
                        for(auto treee: trees){
                            if(treee.cell_index == to) ng = true;
                        }
                        if(ng) continue;

                        int count = 0;
                        for(auto nv: board[to].neighbors){
                            if(nv == -1) continue;
                            bool exsists = false;
                            for(auto treee: trees){
                                if(treee.cell_index == nv) exsists = true;
                            }
                            if(exsists) ++count;
                        }
                        candidate.push_back({count, to});
                    }

                    if(candidate.size() == 0) continue;

                    sort(candidate.begin(), candidate.end());

                    action = "SEED ";
                    action += i2s(tree.cell_index); // from
                    action += ' ';
                    action += i2s(candidate.front().second); // to
                    
                    return action;
                }
            }
        }
        // enough trees, just grow or complete!!
        else{
            // more than 3 biggest trees or last of game, complete biggest tree
            if(cnt[3] > 3 || day > 20){
                int target = -1;
                for(auto tree: trees){
                    if(!tree.is_mine) continue;
                    if(tree.is_dormant) continue;
                    if(tree.size == 3) target = tree.cell_index;
                }
                
                action = "COMPLETE ";
                action += i2s(target);
                if(target != -1) return action;
            }
            // prefer smaller trees
            else{
                vector<pair<int, int>> candidate;
                for(auto tree: trees){
                    if(!tree.is_mine) continue;
                    if(tree.is_dormant) continue;
                    if(tree.size == 3) continue;

                    candidate.push_back({tree.size, tree.cell_index}); 
                }
                
                sort(candidate.begin(), candidate.end());
                
                if(candidate.size() > 0){
                    int target = candidate.front().second;
                    action = "GROW ";
                    action += i2s(target);

                    return action;
                }
            }
        }

        return action;
    }
};

int main()
{
    Game game;
    game.inputInitData();

    while (true) {
        game.inputInfo();
        
        cout << game.compute_next_action() << endl;
    }
}