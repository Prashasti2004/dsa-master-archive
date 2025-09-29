/*
Problem: Maximum Subarray - Given an integer array nums, find the subarray with the largest sum and return its sum.
Platform: Leetcode (Problem #53)
Approach: Kadane's Algorithm
Time Complexity: O(N)
Space Complexity: O(1)
*/


//Approach 1:
int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maxsum = INT_MIN;
        int n = nums.size();

        for(int i=0; i<n; i++){
            sum += nums[i];

            maxsum = max(sum, maxsum);

            if(sum<0){
                sum = 0;
            }
        }

        return maxsum;

}


//Approach 2:
int maxSubArray(vector<int>& nums){
  int minPrev = 0;
  int prefix = 0;
  int maxSum = INT_MIN;

  for(int i=0; i<nums.size(); i++){
    prefix += nums[i];
    maxSum = max(maxSum, prefix-minPrev);
    minPrev = min(minPrev, prefix);
  }

  return maxSum;
}
