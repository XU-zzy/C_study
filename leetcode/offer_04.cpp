//二维数组中的查找
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        int i = matrix.size() - 1, j = 0;
        while(i >= 0 && j < matrix[0].size())
        {
            if(matrix[i][j] > target) i--;
            else if(matrix[i][j] < target) j++;
            else return true;
        }
        return false;
    }
};


int main(){
    int a[5][5] = {{1,4,7, 11, 15},
                   {2,5,  8, 12, 19},
                    {3,   6,  9, 16, 22},
                    {10, 13, 14, 17, 24},
                    {18, 21, 23, 26, 30}};
    vector<vector<int>> mat(5,vector<int>(5));

    for(int i = 0;i < 5;i++){
        for(int j = 0;j < 5;j++){
            mat[i][j] = a[i][j];
        }
    }

    for(int i = 0; i < 5;i++){
        for(int j = 0;j < 5;j++){
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    Solution sol;

    if(sol.findNumberIn2DArray(mat,5)){
        cout << "true" << endl;
    }else{
        cout << "false" << endl;
    }

    return 0;

}

