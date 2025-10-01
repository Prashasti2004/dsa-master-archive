/*
Problem: Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
Assume - Each input would have exactly one solution
Platform: Leetcode (Problem #1)
Approach: Using hashmap
Time Complexity: O(n)
Space Complexity: O(n)
*/

vector<int> twoSum(vector<int>& nums, int target) {

        int n = nums.size();

        if(n==2){
            return {0,1};
        }
        unordered_map<int, int> mp;

        for(int i=0; i<n; i++){
            int rem = target - nums[i];
            if(mp.find(rem) != mp.end()){
                return {mp[rem], i};
            }

            mp[nums[i]] = i;
        }

        return {-1,-1};
}
