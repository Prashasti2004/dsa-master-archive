/*
Problem: Sort an Array of 0's, 1's and 2's
Platform: Leetcode (Problem #75)
Approach: sort in-place using mid low high pointers (3 pointers)
Space Complexity: O(1)
*/


//Approach 1: Using 3 pointer
//T.C = O(N)
void sortColors(vector<int>& nums) {
        int mid = 0, low = 0, high = nums.size()-1;

        while(mid<=high){
            if(nums[mid] == 0){
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }else if(nums[mid] == 1){
                mid++;
            }else{
                swap(nums[mid], nums[high]);
                high--;
            }
        }
}
  

//Approach 2: Using 2 pointers 2 times
// T.C = O(2N)
void sortColors(vector<int>& nums) {
        int i=0; 
        int j = nums.size()-1;

        while(i<=j){
            if(nums[i]!=0 && nums[j]==0){
                swap(nums[i],nums[j]);
                i++;
                j--;
            }else if(nums[i] == 0){
                i++;
            }else{
                j--;
            }
        }

        j=nums.size()-1;
        while(i<=j){
            if(nums[i]!=1 && nums[j]==1){
                swap(nums[i], nums[j]);
                i++;
                j--;
            }else if(nums[i] == 1){
                i++;
            }else{
                j--;
            }
        }
}
