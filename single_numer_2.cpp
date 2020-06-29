/*

Given a non-empty array of integers, every element appears three times except for one, which appears exactly once. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:

Input: [2,2,3,2]
Output: 3
Example 2:

Input: [0,1,0,1,0,1,99]
Output: 99

*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        /*unordered_map<int,int> cache;
        for(int i=0;i<nums.size();++i) {
            ++cache[nums[i]];
        }
        for(auto it=cache.begin();it != cache.end();++it) {
            if (it->second == 1) return it->first;
        }
        return 0; */
        
        //solution 2
        int result = 0;
        for (int i =0;i<32;++i) {
            int sum = 0,mask = 1<<i;
            for (int j = 0;j<nums.size();++j) {
                if ((nums[j] & mask) != 0) {
                    ++sum;
                }
            }
            if (sum%3==1) {
                result = (result | mask);
            }
        }
        return result;
    }
};