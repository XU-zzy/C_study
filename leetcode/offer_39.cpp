//利用 hashmap 储存数组中值的出现次数
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> match;
        int len = nums.size(), res = 10086;
        if(len == 1 || len == 2){
            return nums[0];
        }

        for(int i = 0; i < len; ++i){
            match[nums[i]] ++;
            if(match[nums[i]] > (len / 2)){
                res = nums[i];
                break;
            }
        }
        return res;
    }
};

//摩尔投票法（本题最佳解法）。
//其实就是诸侯乱战，你作为东方大国，拥有超过总数 1/2 的兵力，且规定一个兵打一个兵必定同归于尽，
//那么即使全部诸侯打你一个，最后剩下的兵肯定也是你的兵，也就是你赢了。
//所以我们的策略就是，先让 res = nums[0]，mole_vote = 1，然后往后迭代。
//但凡遇到下一个不等于 res，就让 mole_vote --（相当于和一个敌人同归于尽）；
//如果下一个等于 res，则mole_vote ++。如果 mole_vote == 0 了，就让 res 等于当前 numes[i]。
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int moleVote = 0, res = 0;
        for(int i : nums){
            if(moleVote == 0){
                res = i;
            }
            moleVote += res == i ? 1 : -1;
        }
        return res;
    }
};

