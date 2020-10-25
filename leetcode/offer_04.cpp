#include <iostream>

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        int col = matrix[0].size() - 1;
        for(int row = 0;row < matrix.size();row++){
            if(col < 0){
                return false;
            }
            if(matrix[row][col] == target){
                return true;
            }
            if(matrix[row][col] > target){
                col--;
            }
        }
        return false;
    }
};
