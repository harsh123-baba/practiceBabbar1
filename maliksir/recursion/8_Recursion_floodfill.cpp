#include<vector>
#include<iostream>
using namespace std;

void floodFill(vector<vector<int>> maze, int row, int col, string asf, vector<vector<bool>> visited){
    if(row ==maze.size()-1 && col == maze[0].size()-1){
        cout<<asf<<endl;
        return;
    } 
    if(row<0 || col <0 || row > maze.size()-1||col > maze[0].size()-1 || maze[row][col]==1 || visited[row][col]==true ){
        return;
    }
    visited[row][col] = true;
    floodFill(maze, row-1, col, asf+"t", visited);
    floodFill(maze, row, col-1, asf+"l", visited);
    floodFill(maze, row+1, col, asf+"d", visited);
    floodFill(maze, row, col+1, asf+"r" ,visited);
    visited[row][col] = false;
}



int main(){ 
    int n = 3;
    int m = 3;
    vector<vector<int>> maze(n, vector<int>(m));
    vector<vector<bool>> visited(n, vector<bool>(m));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin>>maze[i][j];
        }
    }
    floodFill(maze, 0, 0, "", visited);

}









// #include<iostream>

// #include<vector>

// using namespace std;
// // asf -> answer so far
// void floodfill((vector<vector<int>> maze, int sr, int sc, string asf) {
// //write your code here
//     if(sr < 0 || sc <  0 || sr >= maze.size() || sc >= maze[0].size(), maze[sr][sc] ==1 || visited[sr][sc] == true){
//         return ;
//     }
//     if(sr==maze.size()-1 && sc == maze[0].size()-1){
//         cout<<asf<<endl;
//         return;
//     }
    

// }

// void floodfill((vector<vector<int>> maze, int sr, int sc, string asf) {
// //write your code here
//     vector<vector<bool>> visited(maze.size(), vector<bool> (maze[0].size(), false));

// }

// int main() {
//   int n, m;
//   cin >> n >> m;
//   vector < vector < int >> arr(n, vector < int > (m));

//   for (int i = 0; i < n; i++)
//     for (int j = 0; j < m; j++)
//       cin >> arr[i][j];

//   floodfill(arr, 0, 0, "");
// }



