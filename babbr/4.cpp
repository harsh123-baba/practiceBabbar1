#include<vector>
#include<iostream>
using namespace std;

void swap(int a, int b){
    int temp;
    temp = a;
    a = b;
    b = temp;

}

vector<int> Sort012(vector<int> v){
    int low = 0;
    int mid = 0;
    int high = v.size()-1;
    while(mid<=high){
        if(v[mid] == 0){
            swap(v[low], v[mid]);
            low++;
            mid++;
        }
        else if(v[mid] == 2){
            swap(v[high], v[mid]);
            high--;
        }
        else{
            mid++;
        }
    }
    return v;
}


int main(){


}