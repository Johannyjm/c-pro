#include <iostream>
#include <vector>
using namespace std;


struct point{
    double x;
    double y;
};

int check(point &a, point &b, point &c, point &d) {
    double s, t;
    s = (a.x - b.x) * (c.y - a.y) - (a.y - b.y) * (c.x - a.x);
    t = (a.x - b.x) * (d.y - a.y) - (a.y - b.y) * (d.x - a.x);
    if (s * t > 0) return false;

    s = (c.x - d.x) * (a.y - c.y) - (c.y - d.y) * (a.x - c.x);
    t = (c.x - d.x) * (b.y - c.y) - (c.y - d.y) * (b.x - c.x);
    if (s * t > 0) return false;
    
    return true;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    point a, b;
    cin >> a.x >> a.y >> b.x >> b.y;

    int n;
    cin >> n;
    point prev;
    cin >> prev.x >> prev.y;
    point fir = prev;
    int cross = 0;
    for(int i = 1; i < n; ++i){
        point curr;
        cin >> curr.x >> curr.y;

        if(check(a, b, prev, curr)) ++cross;

        prev = curr;
    }
    if(check(a, b, fir, prev)) ++cross;

    cout << cross/2 + 1  << endl;
    
    return 0;
}
