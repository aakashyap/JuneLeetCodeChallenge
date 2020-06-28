/*

Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies:

Si % Sj = 0 or Sj % Si = 0.

If there are multiple solutions, return any subset is fine.

Example 1:

Input: [1,2,3]
Output: [1,2] (of course, [1,3] will also be ok)
Example 2:

Input: [1,2,4,8]
Output: [1,2,4,8]

*/

class Solution {
public:
    /*vector<int> util(const vector<int> &nums,int mult,int i,vector<int> &curr) {
        if (i>=nums.size()) return curr;
        if (nums[i]%mult == 0) {
            vector<int> vec1(curr);
            int multt = mult;
            vec1.push_back(nums[i]);
            if (multt < nums[i]) multt = nums[i];
            vec1 = util(nums,multt,i+1,vec1);
            curr = util(nums,mult,i+1,curr);
            return vec1.size() > curr.size()? vec1:curr;
        }
        return util(nums,mult,i+1,curr);
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> curr;
        sort(nums.begin(),nums.end());
        return util(nums,1,0,curr);
    }*/
    
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int size = nums.size();
        sort(nums.begin(),nums.end());
        vector<int> result;
        vector<int> count(size,1);
        vector<int> next(size,-1);
        int max_idx = size-1;
        for(int i = size-1;i >= 0;--i) {
            for (int j = i+1;j < size;++j) {
                if (nums[j]%nums[i] == 0 && count[i] < count[j] + 1) {
                    count[i] = count[j] + 1;
                    next[i] = j;
                }
            }
            if (count[max_idx] < count[i]) {
                max_idx = i;
            }
        }
        int i = max_idx;
        while (i >= 0) {
            result.push_back(nums[i]);
            i = next[i];
        }
        return result;
    }
};