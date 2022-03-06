#include<iostream>
#include<stack>
#define MAX 10
using namespace std;


// int width(int a[], int m){
//     int rb[m];
//     rb[m-1] = m;
//     stack<int> s1;
//     s1.push(m-1);
//     for(int i = m-2; i>=0; i--){
//         while(s1.size()>0 && a[i] < a[s1.top()]){
//             s1.pop();
//         }
//         if(s1.size()==0){
//             rb[i] = m;
//         }
//         else{
//             rb[i] = s1.top();
//         }
//         s1.push(i);
//     }
//     int lb[m];
//     lb[0]=-1;
//     stack<int> s2;
//     s2.push(0);
//     for(int i = 1; i<m;i++){
//         while(s2.size()>0 && a[i]<a[s2.top()]){
//             s2.pop();
//         }
//         if(s2.size()==0){
//             lb[i]=-1;
//         }
//         else{
//             lb[i] = s2.top();
//         }
//         if(a[i]!=a[s2.top()]){
//             s2.push(i);
//         }
//     }
//     int maxArea = 0;
//     for(int i = 0; i< m; i++){
//         int width = rb[i]-lb[i]-1;
//         // cout<<rb[i]<<" "<<lb[i]<<endl;
//         int area = width*a[i];
//         if(area>maxArea){
//             maxArea = area;
//         }
        
//     }
//     return maxArea;
// }


// int maxSizeRect(int a[MAX][MAX], int n, int m){
//     // int x = 0;
//     int *curr = a[0];
//     int maxArea = width(curr, m);
//     for(int i = 1; i<n; i++){
//         for(int j = 0; j<m ; j++){
//             if(a[i][j]==1){
//                 curr[j-1] += a[i][j];
//             }
//         }
//         int area = width(curr, m);
    
//         if(maxArea < area){
//             area = maxArea;
            
//         }
//         cout<<maxArea<<endl;
//     }
//     return maxArea;
// }
int maxAreaHist(int M[MAX], int m){
        int rb[m];
        stack<int> s1;
        rb[m-1] = m;
        s1.push(m-1);
        for(int i = m-2; i>=0; i--){
            while(s1.size()>0 && M[i]<=M[s1.top()]){
                s1.pop();
            }
            if(s1.size()==0){
                rb[i] = m;
            }
            else{
                rb[i] = s1.top();
            }
            s1.push(i);
        }
        
        stack<int> s2;
        int lb[m];
        lb[0] = -1;
        s2.push(0);
        for(int i = 1; i<m; i++){
            while(s2.size()>0 && M[i]<=M[s2.top()]){
                s2.pop();
            }
            if(s2.size()==0){
                lb[i]=-1;
            }
            else{
                lb[i] = s2.top();
            }
            s2.push(i);
        }
        int maxArea =0;
        for(int i = 0; i<m ; i++){
            int width = rb[i]-lb[i]-1;
            int area = width*M[i];
            if(area>maxArea){
                maxArea = area;
            }
            
        } 
        return maxArea;
    }
  
  
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
        int *currRow = M[0];
        int maxArea = maxAreaHist(currRow, m);
        for(int i =1; i<n; i++){
            for(int j = 0; j<m; j++){
                if(M[i][j] == 1){
                    currRow[j] +=1;
                }
                else{
                    currRow[j] = 0;
                }
            }
            int area = maxAreaHist(currRow, m);
            maxArea = max(maxArea, area);
        }
    return maxArea;
        
    }



int main(){
    // int a[][MAX] =  {{0, 1, 1, 0},
    //      {1, 1, 1, 1},
    //      {1, 1, 1, 1},
    //      {1, 1, 0, 0}};

    int a[MAX][MAX] = {{0, 0, 1, 1, 0}, 
                    {1, 1, 1, 1, 1}};
    cout<<maxArea(a, 2, 5);

    // int a[] = {6, 2, 5, 4, 5, 1, 6};
    // int n = sizeof(a)/sizeof(int);
    // cout<<width(a, n);
}