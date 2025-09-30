/*
Problem: Merge 2 Sorted Arrays without using extra space
Platform: Leetcode (Problem #88)
Approach: Using 2 pointer and swap and sorting
Time Complexity: O(min(n,m)) + O(nlogn) + O(mlogm)
Space Complexity: O(1)
*/

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        int left = m-1;
        int right = 0;

        while(left>=0 && right<n){
            if(nums1[left]>nums2[right]){
                swap(nums1[left], nums2[right]);
                left--;
                right++;
            }else{
                break;
            }
        }

        sort(nums1.begin(), nums1.begin() + m);
        sort(nums2.begin(), nums2.begin() + n);

        for(int i=0; i<n; i++){
            nums1[m+i] = (nums2[i]);
        }

}

