#include <iostream>
#include <vector>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    if(n==2){
        if(k==0){
            cout << 1 << endl;
            cout << "1 2" << endl;
        }
        else cout << -1 << endl;

        return 0;
    }

    if(n==3){
        if(k==1){
            cout << 2 << endl;
            cout << "1 2" << endl;
            cout << "2 3" << endl;
        }
        if(k==2){
            cout << -1 << endl;
        }
        if(k==3){
            cout << 3 << endl;
            cout << "1 2" << endl;
            cout << "2 3" << endl;
            cout << "3 1" << endl;
        }
        return 0;
    }

    if(k==n-1 || k==n-2){
        if(k==n-2){
            cout << n-1 << endl;
            for(int i = 1; i < n; ++i){
                cout << i << " " << i+1 << endl;
            }
        }
        if(k==n-1){
            cout << n-1 << endl;
            for(int i = 1; i < n-1; ++i){
                cout << i << " " << i+1 << endl;
            }
            cout << n-2 << " " << n << endl;
        }

        return 0;
    }

    if(k < n-2){
        vector<pair<int, int>> res;

    }
    
    int circle = 0;
    for(int i = 3; i <=n; ++i){
        if(i + (n-i)*2 == k){
            circle = i;
            break;
        }
    }

    if(circle == 0){
        cout << -1 << endl;
        return 0;
    }

    int leg = n-circle;
    
    cout << n << endl;
    // for circle
    for(int i = 1; i < circle; ++i){
        cout << i << " " << i+1 << endl;
    }
    cout << circle << " " << 1 << endl;
    
    // for leg
    for(int i = 1; i <= leg; ++i){
        cout << i << " " << circle+i << endl;
    }

    return 0;
}
