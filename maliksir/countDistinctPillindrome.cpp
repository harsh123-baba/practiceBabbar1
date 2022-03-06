#include<unordered_map>
#include<string>
#include<iostream>
using namespace std;



int DistinctCount(string s){
    long long l = 1e9+7;
    int n = s.size();
    int **dp = new int*[n];
    for(int i = 0; i<n; i++){
        dp[i] = new int[n];
    }
    int prev[n];
    unordered_map<char, int> m;
    for(int i = 0; i<n; i++){
        // if(!m[s[i]]){
        //     prev[i] = -1;
        // }
        // else{
        //     prev[i] = m[s[i]];
        // }
        if(m.find(s[i])!= m.end()){
            prev[i] = m[s[i]];
        }
        else{
            prev[i] =-1;
        }
        m[s[i]]=i;

    }
    m.clear();
    int next[n];
    // unordered_map<char, int> m1;
    for(int i = n-1; i>=0; i--){
        if(m.find(s[i])!= m.end()){
            next[i] = m[s[i]];
        }
        else{
            next[i] = -1;
        }
        m[s[i]] = i;
    }
    //chlo ab bnate hai kaam ki cheej 
    for(int g = 0; g<n; g++){
        for(int i =0, j= g; j<n; j++, i++){
            if(g==0){
                dp[i][j] =1;

            }
            else if(g==1){
                dp[i][j] =2;
            }
            else{
                if(s[i]!=s[j]){
                    dp[i][j] = dp[i+1][j] + dp[i][j+1] - dp[i+1][j-1];
                }
                else{
                    int ne = next[i];
                    int pr = prev[j];
                    if(ne >pr){
                        dp[i][j] = 2*dp[i+1][j-1] +2;
                    }
                    else if(ne==pr){
                        dp[i][j] = 2*dp[i+1][j-1] +1;
                    }else{
                        dp[i][j] = 2* dp[i+1][j-1] - dp[ne+1][pr-1];
                    }
                }
            }
        }
        
    }
    return ((dp[0][n-1]%(l))+l)%l;


}

int main(){
    string s = "bccb";
    cout<<DistinctCount(s);
}