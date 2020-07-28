#include <iostream>

using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;

    int h = ty - sy;
    int w = tx - sx;

    for(int i = 0; i < h; ++i) cout << 'U';
    for(int i = 0; i < w; ++i) cout << 'R';
    for(int i = 0; i < h; ++i) cout << 'D';
    for(int i = 0; i < w; ++i) cout << 'L';

    cout << 'L';

    for(int i = 0; i < h+1; ++i) cout << 'U';
    for(int i = 0; i < w+1; ++i) cout << 'R';

    cout << 'D' << 'R';

    for(int i = 0; i < h+1; ++i) cout << 'D';
    for(int i = 0; i < w+1; ++i) cout << 'L';

    cout << 'U' << endl;

    return 0;
}
