#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll a, b, c, d;
    cin >> a >> b >> c >> d;

    if(a==c && b==d){
        cout << 0 << endl;
        return 0;
    }

    if(a+b == c+d){
        cout << 1 << endl;
        return 0;
    }

    if(a-2<=c && c<=a+2 && b-2<=d && d<=b+2){
        cout << 1 << endl;
        return 0;
    }

    if(a==c && b-3<=d && d<=b+3){
        cout << 1 << endl;
        return 0;
    }

    if(c==d && a-3<=c && c<=a+3){
        cout << 1 << endl;
        return 0;
    }

    if((a+b)%2 == (c+d)%2){
        cout << 2 << endl;
        return 0;
    }



    if((a+b)%2 != (c+d)%2){
        if(a!=c && b!=d){
            ll a_ = c;
            ll b_ = b - (a-c);
            // if(b_>=1){
                if(a_==c && b_==d){
                    cout << 1 << endl;
                    return 0;
                }

                if(a_+b_ == c+d){
                    cout << 2 << endl;
                    return 0;
                }

                if(a_-2<=c && c<=a_+2 && b_-2<=d && d<=b_+2){
                    cout << 2 << endl;
                    return 0;
                }

                if(a_==c && b_-3<=d && d<=b_+3){
                    cout << 2 << endl;
                    return 0;
                }

                if(c==d && a_-3<=c && c<=a_+3){
                    cout << 2 << endl;
                    return 0;
                }
            // }

            b_ = d;
            a_ = a - (b-d);
            // cout << a_ << " " << b_ << endl;
            // if(a_>=1){
                if(a_==c && b_==d){
                    cout << 1 << endl;
                    return 0;
                }

                if(a_+b_ == c+d){
                    cout << 2 << endl;
                    return 0;
                }

                if(a_-2<=c && c<=a_+2 && b_-2<=d && d<=b_+2){
                    cout << 2 << endl;
                    return 0;
                }

                if(a_==c && b_-3<=d && d<=b_+3){
                    cout << 2 << endl;
                    return 0;
                }

                if(c==d && a_-3<=c && c<=a_+3){
                    cout << 2 << endl;
                    return 0;
                }
            // }
        }

        if(a==c){
            if(abs(b-d) <= 5){
                cout << 2 << endl;
                return 0;
            }
        }
        if(b==d){
            if(abs(a-c) <= 5){
                cout << 2 << endl;
                return 0;
            }
        }

        if(a-5<=c && c<=a+5 && b-5<=d && d<=b+5){
            cout << 2 << endl;
            return 0;
        }
        

        cout << 3 << endl;
        return 0;
    }


    return 0;
}