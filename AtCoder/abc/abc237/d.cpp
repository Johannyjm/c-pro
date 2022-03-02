#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    string s;
    cin >> n >> s;
    
    deque<int> dq;
    dq.push_back(n);

    reverse(s.begin(), s.end());
    int now = n-1;
    for(char c: s){
        if(c == 'L') dq.push_back(now);
        else dq.push_front(now);

        --now;
    }

    while(dq.size() > 1){
        cout << dq.front() << " ";
        dq.pop_front();
    }

    cout << dq.front() << endl;

    return 0;
}
