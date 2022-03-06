#include<vector>
#include<iostream>
using namespace std;
int maxDistance(vector<int>& colors) {
        int i = 0;
        int j = colors.size()-1;
        
        int lr = 0;
        int rl = 0;
        while(i<j){
            if(colors[i]==colors[j]){
                i++;
            }
            else{
                lr = max(lr, j-i);
                // j--;
                // i++;
                break;
            }
        }
        i=0;
        j=colors.size()-1;
        while(i<j){
            if(colors[i]==colors[j]){
                j--;
            }
            else{
                rl = max(rl, j-i);
                // j--;
                break;
                // i++;
            }
        }
        return max(lr, rl);
        
    }

int main(){
    vector<int> v = {6,6,6,6,6,6,6,6,6,19,19,6,6};
    cout<<maxDistance(v);
}