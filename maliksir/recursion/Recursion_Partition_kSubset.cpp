#include<vector>
#include<iostream>
using namespace std;

void Partition(int i, int k ,vector<bool> used, string asf){
    if(used.size()<k){
        return;
    }
    if(i>used.size()){
    
        cout<<asf<<endl;

        
        return;
    }
    if(used[i]==true){
        Partition(i+1, k, used, asf);
    }
    else{
        used[i] = true;
        Partition(i+1, k, used, asf+to_string(i)+"  | ");
        for(int j  = i+1; j<=used.size(); j++){
            if(used[j]==false){
                used[j] = true;
                Partition(i+1, k, used, asf+to_string(i)+to_string(j));
                used[j]= false;
            }
        }
    }


}

int main(){
    int n = 3;
    vector<bool> used(n+1, false);
    Partition(1, 2, used, "");
}