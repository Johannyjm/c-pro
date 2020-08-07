#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int h, w;
    cin >> h >> w;
    
    vector<int> cnt(26, 0);
    for(int i = 0; i < h; ++i){
        string s;
        cin >> s;
        for(int j = 0; j < s.size(); ++j) ++cnt[s[j] - 'a'];
    }

    sort(cnt.begin(), cnt.end(), greater<int>());

    if(h*w < 4){
        if(h*w == 1) cout << "Yes" << endl;
        else{
            if(cnt[0] == 2) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
        return 0;
    }

    if(h%2==0 && w%2==0){
        for(int i = 0; i < 26; ++i){
            if(cnt[i] > 0 && cnt[i]%4 != 0){
                cout << "No" << endl;
                return 0;
            }
        }
        cout << "Yes" << endl;

        return 0;
    }

    else{
        int need4, need2, any;
        if(h%2==1 && w%2==1){
            need4 = (h/2*2) * (w/2*2) / 4;
            need2 = h/2 + w/2;
            any = 1;
        }
        else{
            need4 = (h/2*2) * (w/2*2) / 4;
            if(h%2 == 1) need2 = w/2;
            else need2 = h/2;
            any = 0;
        }
        
        int cnt4 = 0;
        int cnt2 = 0;
        int cnta = 0;
        for(int i = 0; i < 26; ++i){
            int tmp = cnt[i];
            if(tmp % 4 == 0) cnt4 += tmp/4;
            else if(tmp % 2 == 0){
                ++cnt2;
                cnt4 += (tmp-2) / 4;
            }
            else{
                ++cnta;
                --tmp;
                cnt4 += tmp/4;
                cnt2 += tmp%4;
            }
        }


        if(cnta != any){
            cout << "No" << endl;
            return 0;
        }
        if(need4 == cnt4){
            if(need2 == cnt2) cout << "Yes" << endl;
            else cout << "No" << endl;
            return 0;
        }
        else{
            if(need4 > cnt4) cout << "No" << endl;
            else if(cnt2 + (cnt4-need4)*2 == need2) cout << "Yes" << endl;
            return 0;
        }

    }
    
    return 0;

}
