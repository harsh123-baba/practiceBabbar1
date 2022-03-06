#include<bits/stdc++.h>
using namespace std;

long long maxProduct(vector<int> arr, int n) {
	    // code here
	    long long maxprodhere = arr[0];
	    long long maxProd = arr[0];
	    for(int i = 1; i<n; i++){
	        long long curr = 1;
	        if(arr[i]==0){
	           curr = 0;
	        }
	        if(arr[i-1]==0){
	            curr = arr[i-1];
	        }
	        else{
	            long long x = arr[i];
	            long long y = arr[i-1];
	            curr = max(x, max(x*y, x*maxprodhere));
	            arr[i] = min(x , min(x*y, maxprodhere*x));
	            
	        }
	        maxprodhere = curr;
	        maxProd = max(maxprodhere, maxProd);
	    }
	    return maxProd;
	}

int main(){
    vector<int> v = {2, 3, 4, 5, -1, 0};
    cout<<maxProduct(v, 6);
}