#include<vector>
#include<iostream>
using namespace std;

bool ispossible(vector<int> v, int mid, int student){
    int sumOfpages=0;
    int s=1;
    for(int i = 0; i<v.size();i++){
        sumOfpages+=v[i];
        if(sumOfpages >mid){
            s+=1;
            sumOfpages = v[i];
        }
    }
    if(s <= student){
        return true;
    }else{
        return false;
    }
}


int minPagesAllocation(vector<int> v, int s){
    //get to know the min no of pages in 
    int minPages = 0;
    int maxPages = 0;
    for(int i =0;i<v.size();i++){
        if(v[i]>minPages){
            minPages=v[i];
        }
        maxPages +=v[i];
    }
    int ans = 0;
    while(minPages<maxPages){
        int mid = (minPages+(maxPages-minPages)/2);
        if(ispossible(v,mid ,s)){
            ans = mid;
            maxPages = mid-1;
        }
        else{
            minPages = mid+1;
        }
    }
    return ans;
}


int main(){
    vector<int> v = {12, 34, 67, 90};
    cout<<minPagesAllocation(v, 2);

}