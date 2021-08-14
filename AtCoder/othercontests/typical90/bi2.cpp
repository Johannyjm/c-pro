#include <iostream>
#include <deque>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int q;
    cin >> q;

    deque<int> dq;
    for(int i = 0; i < q; ++i){
        int t, x;
        cin >> t >> x;

        if(t == 1){
            dq.push_front(x);
        }
        if(t == 2){
            dq.push_back(x);
        }
        if(t == 3){
            --x;
            cout << dq[x] << "\n";
        }
    }



    return 0;
}
