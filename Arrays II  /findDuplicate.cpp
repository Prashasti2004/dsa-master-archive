/*
Problem: Find the duplicates in an Array of N+1 integers
Platform: Leetcode (Problem #287)
Approach: Using slow fast mechanism i.e linked list cycle method
Time Complexity: O(N)
Space Complexity: O(1)
*/

int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];
        int n = nums.size();

        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow != fast);
        
        slow = nums[0];

        while(slow!=fast){
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;

}
