#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        return false;
    }
};


int main()
{
    
    vector<vector<char>> b = {{'A','B','C','E'},
                              {'S','F','C','S'},
                              {'A','D','E','E'}};
    string w("ABCCED");

    Solution s;

    if(s.exist(b,s)){
        cout << "yes" << endl;
    }else{
        cout << "no" << endl;
    }
    
    
    std::cout << "Hello world" << std::endl;
    return 0;
}

