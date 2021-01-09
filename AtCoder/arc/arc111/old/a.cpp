#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint;


int s, t;
void junkan2(int n)
{
    int m = 1; // カメ。剰余を保持する変数（初期値1）
    int p = 1; // ウサギ。剰余を保持する変数（初期値1）
    s = 0; // 循環節の開始位置
    t = 0; // 循環節の終了位置
  
    if (n > 0)
    {
        // ウサギとカメが出合う地点を探す
        while (true)
        {
            m = (m * 10) % n;
            p = (p * 10) % n;
            p = (p * 10) % n;
            if (m == p)break;
        }
  
        // pが非ゼロ。割り切れない場合
        if (p != 0)
        {
            // ウサギをスタート地点に戻し、再びカメと出合うまでループを回す
            p = 1;
            s = 1;
            while (m != p)
            {
                s++;
                m = (m * 10) % n;
                p = (p * 10) % n;
            }
            // カメを止めて、ウサギだけ1ずつ進める
            p = (p * 10) % n;
            t = s;
            while (m != p)
            {
                t++;
                p = (p * 10) % n;
            }
        }
    }
    // printf("n = %d, s = %d, t = %d\n", n, s, t); // 結果を出力
}



int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, m;
    cin >> n >> m;

    junkan2(m);

    cout << s << " " << t << endl;

    return 0;
}