#include<iostream>
using namespace std;

void Encoding(string s, string ans){
    if(s.size()==0){
        cout<<ans<<endl;
        return;
    }
    else if(s.size()==1){
        if(s[0]=='0'){
            return;
        }else{
            int charval = s[0]-'0';
            char code = (char) ('a'+charval-1);
            ans = ans+code;
            cout<<ans<<endl;
        }
    }
    else{
        if(s[0]=='0'){
            return;
        }
        else{
            int charval = s[0]-'0';
            char code = (char)('a'+charval-1);
            string rest = s.substr(1);
            Encoding(rest, ans + code);
        }
        string s12 = s.substr(0, 2);
        string rest12 = s.substr(2);
        int charval = stoi(s12);
        if(charval <=26){
            char code = char('a'+charval-1);
            Encoding(rest12, ans+code);
        }
    }
}


int main(){
    string s = "123";
    Encoding(s,"");

}