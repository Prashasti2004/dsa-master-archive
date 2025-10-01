/*
Problem: Majority Element (>n/2 times)
Platform: Leetcode (Problem #169)
Approach: Moore's Voting Algorithm
Time Complexity: O(N)
Space Complexity: O(1)
*/

int majorityElement(vector<int>& nums) {
        
        int n = nums.size();
        int el = nums[0];
        int cnt = 0;

        for(int i=0; i<n; i++){
            if(cnt == 0){
                cnt = 1;
                el = nums[i];
            }else if(nums[i] == el){
                cnt++;
            }else{
                cnt --;
            }
        }
        return el;
}
