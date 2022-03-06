#include <iostream>
#include <vector>
using namespace std;
int minCost(vector<int> &startPos, vector<int> &homePos, vector<int> &rowCosts, vector<int> &colCosts){
    
    int sr = startPos[0];
    int sc = startPos[1];
    int er = homePos[0];
    int ec = homePos[1];

    int cost = 0;
    if (sr < er)
    {
        while (sr < er)
        {
            sr++;
            cost += rowCosts[sr];
            
        }
    }
    else if (sr > er)
    {
        while (sr > er)
        {
            sr--;
            cost += rowCosts[sr];
        }
    }
    if (sc < ec)
    {
        while (sc < ec)
        {
            sc++;
            cost += colCosts[sc];
        }
    }
    else if (sc > ec)
    {
        while (sc > ec)
        {
            sc--;
            cost += colCosts[sc];
        }
    }
    return cost;
}
int main()
{

    vector<int> row = {5, 4, 3};
    vector<int> col = {8, 2, 6, 7};
    vector<int> startPos = {1, 0};
    vector<int> endPos = {2, 3};
    
    // vector<vector<bool>> visited(row.size(), vector<bool>(col.size(), false));
    cout << minCost(startPos, endPos , row, col);
}