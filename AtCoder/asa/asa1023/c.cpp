#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int x, y;
    cin >> x >> y;

    
    if(x < y){

        if((x>=0&&y>=0) || (x<=0&&y<=0)){
            cout << y-x << endl;
            return 0;
        }

        if(abs(y) == abs(x)){
            cout << 1 << endl;
            return 0;
        }

        if(abs(y) > abs(x)){
            cout << abs(y)-abs(x)+1 << endl;
            return 0;
        }

        if(abs(x) > abs(y)){
            cout << abs(x)-abs(y)+1 << endl;
            return 0;
        }
    }

    else{
        if((x>0&&y>0) || (x<0&&y<0)){
            cout << x-y+2 << endl;
            return 0;
        }

        if(abs(y) == abs(x)){
            cout << 1 << endl;
            return 0;
        }

        if(abs(y) > abs(x)){
            cout << abs(y)-abs(x)+1 << endl;
            return 0;
        }

        if(abs(x) > abs(y)){
            cout << abs(x)-abs(y)+1 << endl;
            return 0;
        }
    }
        

    return 0;
}