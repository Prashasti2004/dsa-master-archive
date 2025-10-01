/*
Problem: Majority Elements (>n/3 times)
Platform: Leetcode (Problem #229)
Approach: Extended Boyer Moore's Voting Algorithm
Time Complexity: O(N)
Space Complexity: O(1)
*/

vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size(); //size of the array

        int cnt1 = 0, cnt2 = 0; // counts
        int el1 = INT_MIN; // element 1
        int el2 = INT_MIN; // element 2

        // applying the Extended Boyer Moore's Voting Algorithm:
        for (int i = 0; i < n; i++) {
            if (cnt1 == 0 && el2 != nums[i]) {
                cnt1 = 1;
                el1 = nums[i];
            }
            else if (cnt2 == 0 && el1 != nums[i]) {
                cnt2 = 1;
                el2 = nums[i];
            }
            else if (nums[i] == el1) cnt1++;
            else if (nums[i] == el2) cnt2++;
            else {
                cnt1--, cnt2--;
            }
        }

        vector<int> ls; // list of answers

        // Manually check if the stored elements in
        // el1 and el2 are the majority elements:
        cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == el1) cnt1++;
            if (nums[i] == el2) cnt2++;
        }

        int mini = int(n / 3) + 1;
        if (cnt1 >= mini) ls.push_back(el1);
        if (cnt2 >= mini) ls.push_back(el2);

        return ls;
}
