#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;

    vector<int> cnt(26, 0);
    for(int i = 0; i < s.size(); ++i) ++cnt[s[i] - 'a'];
    
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < 26; ++i){
        if(cnt[i] % 2 == 1) pq.push(cnt[i]);
    }

    if(pq.empty()){
        cout << s.size() << endl;
        return 0;
    }
        
    int n = s.size();
    int k = pq.size();
    cout << 2*((n-k)/(2*k))+1 << endl;

//    for(int i = 0; i < 26; ++i){
//        if(cnt[i] % 2 == 1) continue;
//        
//        for(int j = 0; j < cnt[i]/2; ++j){
//            int shortest = pq.top();
//            pq.pop();
//            shortest += 2;
//            pq.push(shortest);
//        }
//    }

//    cout << pq.top() << endl;
}
