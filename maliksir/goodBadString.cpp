#include<iostream>
using namespace std;
int isGoodorBad(string s) {
        // code here
        int con = 0;
        int v = 0;
        
        for(int i = 0; i<s.size(); i++){
            if(v > 5 || con>3){
                return 0;
            }
            if(s[i]=='a' || s[i] =='e'||s[i] =='i'||s[i] =='o'||s[i] =='u'){
                con=0;
                v++;
            }
            else if(s[i] == '?'){
                v++;
                con++;
            }
            else{
                v = 0;
                con ++;
            }
            
        
        }
        return 1;
    }
int main(){
    string s = "c?zaicq";
    cout<<isGoodorBad(s);
}