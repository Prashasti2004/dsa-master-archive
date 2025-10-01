/*
Problem: Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
Platform: Leetcode (Problem #128)
Approach: Use unordered_set for unique elements and then write algo
Time Complexity: O(n) [for worst case of set operations = O(nlogn)]
Space Complexity: O(n)
*/


int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0){
            return 0;
        }

        if(n==1){
            return 1;
        }

        unordered_set<int> st;

        for(int i=0; i<n; i++){
            st.insert(nums[i]);
        }

        int maxLen = 0;

        for(auto it:st){
            if(st.find(it-1) == st.end()){
                int cnt = 1;
                while(st.find(it+1) != st.end()){
                    cnt++;
                    it++;
                }

                maxLen = max(maxLen, cnt);
            }
        }

        return maxLen;
}
