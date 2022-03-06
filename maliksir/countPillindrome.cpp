#include<vector>
#include<iostream>

using namespace std;

// use copy before watching this
int countPillindrome(string s){
    int n = s.size();
    int **dp = new int*[n];
    for(int i = 0; i<n; i++){
        dp[i] = new int[n];
    }
    for(int g = 0; g<n; g++){
        for(int i = 0, j = g; j<n; i++, j++){
            if(g==0){
                dp[i][j] =1;
            }
            else if(g==1){
                if(s[i]==s[j]){
                    dp[i][j]=3;
                }else{
                    dp[i][j] = 2;
                }
            }
            else{
                if(s[i]==s[j]){
                    dp[i][j] = dp[i][j-1] + dp[i+1][j] + 1;
                }
                else{
                    dp[i][j] = dp[i][j-1] + dp[i+1][j] - dp[i+1][j-1];
                }
            }
        }
    }
    return dp[0][n-1];
}



int main(){
    string s = "abccbc";
    cout<<countPillindrome(s);

}