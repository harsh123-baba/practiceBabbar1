#include<iostream>
using namespace std;

void Abbreviation(int pos, string s, string ans, int count){
    if(pos == s.size()){
        if(count == 0){
            cout<<ans;
        }
        else{
            cout<<ans+ to_string(count);
        }
        cout<<endl;
        return;
    }
    if(count > 0){
        Abbreviation(pos+1, s, ans+to_string(count)+s[pos], 0);
    }
    else{
        Abbreviation(pos+1, s, ans+s[pos], 0);
    }
    Abbreviation(pos+1, s, ans, count+1);
}



int main(){
    Abbreviation(0, "pep", "",0);
}