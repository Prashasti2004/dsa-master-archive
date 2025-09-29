/*
Problem: Next Permutation
Platform: Leetcode (Problem #31)
Approach: 
step 1: Take i pointer from right such that nums[i+1] > nums[i]
step 2: Take j pointer from right such that nums[j] > nums[i] i.e the number which is just greater than nums[i]
step 3: swap nums[i] and nums[j]
step 4: reverse(nums.begin() + i + 1, nums.end())
T.C = O(2N)
S.C = O(1)
*/


void nextPermutation(vector<int>& nums) {
        int i=nums.size()-2;

        while(i>=0 && nums[i+1]<=nums[i]){
            i--;
        }

        if(i>=0){
            int j=nums.size()-1;
            while(nums[j]<=nums[i]){
                j--;
            }
            swap(nums[i], nums[j]);
        }

        reverse(nums.begin()+i+1, nums.end());

}
