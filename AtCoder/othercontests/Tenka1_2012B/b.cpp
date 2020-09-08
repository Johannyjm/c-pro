#include <iostream>
#include <string>
using namespace std;

bool isLower(char c){
    return ('a'<=c && c<='z');
}

bool isUpper(char c){
    return ('A'<=c && c<='Z');
}

bool isAlpha(char c){
    return (isLower(c) || isUpper(c));
}

bool isNum(char c){
    return ('0'<=c && c<='9');
}

string isCamel(string s){
    string ret = "";
    int n = s.size();
    bool isprefix = true;
    bool issuffix = false;
    int pre_ = 0;
    int post_ = 0;
    string buf = "";
    for(int i = 0; i < n; ++i){
        if(isprefix && s[i]=='_') ++pre_;
        else if(isprefix && isAlpha(s[i])){
            isprefix = false;
            if(isUpper(s[i])) return "";
            buf += s[i];
        }
        else if(isprefix && isNum(s[i])) return "";
        else if(!isprefix && !isUpper(s[i])){
            if(!issuffix && s[i] == '_'){
                issuffix = true;
                if(ret != "") ret += '_';
                ret += buf;
                buf = "";
                ++post_;
            }
            else if(!issuffix && s[i] != '_'){
                buf += s[i];
            }
            else if(issuffix && s[i] != '_') return "";
            else if(issuffix && s[i] == '_') ++post_;
        }
        else if(!isprefix && isUpper(s[i])){
            if(ret != "") ret += '_';
            ret += buf;
            buf = 'a' + (s[i] - 'A');
        }
    }
    if(buf != ""){
        if(ret != "") ret += '_';
        ret += buf;
    }

    string prefix = "";
    for(int i = 0; i < pre_; ++i) prefix += '_';
    string suffix = "";
    for(int i = 0; i < post_; ++i) suffix += '_';

    return prefix + ret + suffix;
}

string is_snake(string s){
    string ret = "";
    int n = s.size();
    bool isprefix = true;
    int pre_ = 0;
    string buf = "";
    int cnt = 0;
    while(s[n-1-cnt]=='_') ++cnt;
    
    for(int i = 0; i < n; ++i){
        if(isUpper(s[i])) return "";
        if(isprefix && s[i]=='_') ++pre_;
        else if(isprefix && s[i]!='_'){
            if(isNum(s[i])) return "";
            isprefix = false;
            buf += s[i];
        }
        else if(!isprefix && s[i]=='_'){
            if(i < n-cnt+1 && buf=="") return "";
            if(buf!="" && isNum(buf[0])) return "";
            for(int j = 0; j < buf.size(); ++j){
                if(j==0 && ret!="") ret += 'A' + (buf[j]-'a');
                else ret += buf[j];
            }
            buf = "";
        }
        else if(!isprefix && s[i]!='_'){
            buf += s[i];
        }
    }
    if(buf!=""){
        for(int i = 0; i < buf.size(); ++i){
            if(i==0 && ret!="") ret += 'A' + (buf[i]-'a');
            else ret += buf[i];
        }
    }
    string prefix = "";
    for(int i = 0; i < pre_; ++i) prefix += '_';
    if(ret!=""){
        for(int i = 0; i < cnt; ++i){
            ret += '_';
        }
    }
    
    return prefix + ret;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    
    if(isCamel(s) != "") cout << isCamel(s) << endl;
    else if(is_snake(s) != "") cout << is_snake(s) << endl;
    else cout << s << endl;

    return 0;
}
