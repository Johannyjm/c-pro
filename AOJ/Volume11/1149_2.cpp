#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<cmath>
#include<climits>
#include<ctime>
#include<cstring>
#include<numeric>

#define ALL(v) (v).begin(),(v).end()
#define REP(i,p,n) for(int i=p;i<(int)(n);++i)
#define rep(i,n) REP(i,0,n)
#define dump(a) (cerr << #a << "=" << (a) << endl)
#define DUMP(list) cout << "{ "; for(auto nth : list){ cout << nth << " "; } cout << "}" << endl;

using namespace std;

struct cake {
	int w, d, area, turn;
	cake(int w_, int d_, int turn_)
		: w(w_), d(d_), area(w_*d_), turn(turn_) {}
	bool operator<(const cake &c) const {
		if(turn != c.turn) { return turn < c.turn; }
		return area < c.area;
	}
};

vector<cake> cakes;

int main() {
	int n, w, d;
	while(cin >> n >> w >> d, w) {
		int turn=0;
		cakes.clear();
		cakes.push_back(cake(w, d, turn));
		int p, s;
		rep(i, n) {
			++turn;
			cin >> p >> s; p--;
			cake piece = cakes[p];
			cakes.erase(cakes.begin() + p);
			
			int k=1, diff=s;
			for(; diff > 0; ++k) {
				diff -= (k % 2) ? piece.w : piece.d;
			}
			
			diff *= -1;
			if(k % 2) { //縦分割
				int d1 = piece.d - diff;
				int d2 = diff;
				cakes.push_back(cake(piece.w, d1, turn));	
				cakes.push_back(cake(piece.w, d2, turn));	
			} 
			else { //横分割
				int w1 = piece.w - diff;
				int w2 = diff;
				cakes.push_back(cake(w1, piece.d, turn));	
				cakes.push_back(cake(w2, piece.d, turn));	
			}

			sort(ALL(cakes));
            rep(i, cakes.size()){
                cout << i+1 << " " << cakes[i].w << " " << cakes[i].d << endl;
            }
		}

		vector<int> result;
		rep(i, cakes.size()) result.push_back(cakes[i].area);

		sort(ALL(result));
		rep(i, result.size()) {
			if(i != 0) cout << " ";
			cout << result[i];
		}
		cout << endl;
	}
	return 0;
}