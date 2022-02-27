#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    
    unordered_map<int, int> cnt;
    for(int i = 0; i < n; ++i){
        int a;
        cin >> a;

        ++cnt[a];
    }

    for(int i = 0; i < m; ++i){
        int b;
        cin >> b;

        if(cnt[b] == 0){
            puts("No");
            return 0;
        }

        --cnt[b];
    }

    puts("Yes");

    return 0;
}
