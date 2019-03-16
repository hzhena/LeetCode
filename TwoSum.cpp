/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/

class Solution {
public:
    /* 暴力法 */
    vector<int> twoSum(vector<int>& nums, int target) {
        unsigned int l_size = nums.size();
        vector<int> l_result;
        for (int i =  0; i < l_size; i ++)
        {
            for (int j = i + 1; j < l_size; j ++)
            {
                if (nums[i] + nums[j] == target)
                {
                    l_result.push_back(i);
                    l_result.push_back(j);
                    
                    break;
                }
            }
            
            if (l_result.size() != 0)
            {
                break;
            }
        }
        
        return l_result;
    }

    /* 排序，查找法 */
    vector<int> twoSum(vector<int>& nums, int target) {
        unsigned int l_size = nums.size();
        multimap<int, int> l_map;

        /* map只能保存不同的key，multimap查找性能相对hash算法低 */
        for (int i = 0; i < l_size; i ++)
        {
            l_map.insert(std::pair<int, int>(nums[i], i));
        }

        vector<int> l_result;
        for (int i =  0; i < l_size; i ++)
        {
            int l_remain = target - nums[i];
            multimap<int, int>::iterator l_pos = l_map.find(l_remain);
            if (l_map.end() != l_pos && i != l_pos->second)
            {
                l_result.push_back(i);
                l_result.push_back(l_pos->second);

                break;
            }
        }
        
        return l_result;
    }
};