//数组中重复的数字
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}
class Solution {
public:
    //原地哈希
    int findRepeatNumber(vector<int>& nums) {
        for(int i = 0;i < nums.size();i++){
            //索引等于索引的值，就索引后移，i++，继续遍历
            if(nums[i] == i){
                continue;
            }
            //索引的值等于它自己作为索引时的值时，说明出现重复，即返回值
            if(nums[i] == nums[nums[i]]){
                return nums[i];
            }
            //交换两值，为保证索引不变，i--
            swap(nums[i],nums[nums[i]]);
            i--;
        }
        return -1;
    }
    
    //哈希/set
    int findRepeatNumber_t(vector<int>& nums){
        unordered_map<int,bool> map;
        for(int num : nums){
            if(map[num])
                return num;
            map[num] = true;
        }
        return -1;
    }
};
