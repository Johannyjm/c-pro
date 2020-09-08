#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll q, l;
    cin >> q >> l;

    vector<pair<ll, ll>> stack;
    ll stacksize = 0;
    for(int i = 0; i < q; ++i){
        string ord;
        cin >> ord;

        if(ord == "Push"){
            int n, m;
            cin >> n >> m;
            if(stacksize + n > l){
                cout << "FULL" << endl;
                return 0;
            }
            if(stacksize == 0) stack.push_back({m, n});
            else{
                if(stack.back().first == m) stack.back().second += n;
                else stack.push_back({m, n});
            }
            
            stacksize += n;
        }

        if(ord == "Pop"){
            int n;
            cin >> n;
            if(stacksize - n < 0){
                cout << "EMPTY" << endl;
                return 0;
            }
            stacksize -= n;
            while(n){
                if(stack.back().second > n){
                    stack.back().second -= n;
                    n = 0;
                }
                else{
                    n -= stack.back().second;
                    stack.pop_back();
                }
            }
        }
        if(ord == "Top"){
            if(stacksize == 0){
                cout << "EMPTY" << endl;
                return 0;
            }
            cout << stack.back().first << endl;
        }
        if(ord == "Size"){
            cout << stacksize << endl;
        }
    }

    cout << "SAFE" << endl;

    return 0;
}
