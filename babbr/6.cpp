#include<iostream>
#include<vector>
using namespace std;

vector<int> Intersection(vector<int> A , vector<int> B){
    vector<int> c;
    int i = 0;
    int j = 0;
    while(i<A.size() && j<B.size()){
        if(A[i] < B[j]){
            i++;
        }
        else if(B[j] > A[i]){
            j++;
        }
        else{
            c.push_back(A[i]);
            i++;
            j++;
        }
    }
    return c;
}

vector<int> Union(vector<int> A, vector<int> B){
    int i = 0;
    int j = 0;
    vector<int> v;
    while(i<A.size() && j<B.size()){
        if(A[i]< B[i]){
            v.push_back(A[i]);
            i++;
        }
        else if(A[i] > B[i]){
            v.push_back(B[j]);
            j++;
        }
        else{
            v.push_back(A[i]);
            i++;
            j++;
        }
    }
    while(i<A.size()){
        v.push_back(A[i]);
        i++;
    }
    while(j<B.size()){
        v.push_back(B[j]);
        j++;
    }
    return v;
}


int main(){
    vector<int> A= {1, 2, 3, 4, 5, 6};
    vector<int> B = {2, 4, 5, 7};
    vector<int> c = Intersection(A, B);
    for(int i = 0; i<c.size(); i++){
        cout<< c[i]<<" ";
    }
cout<<endl;


    vector<int> v = Union(A, B);
    for(int i = 0; i<v.size(); i++){
        cout<< v[i]<<" ";
    }

}