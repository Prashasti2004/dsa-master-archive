/*
Problem: Merge Overlapping SubIntervals
Platform: Leetcode (Problem #56)
Approach: Sort Intervals and then traverse the vector to merge the intervals
Time Complexity: O(NlogN)[sort] + O(N) [loop] ~ O(NlogN)
Space Complexity: O(N) [ans]
*/

vector<vector<int>> merge(vector<vector<int>>& intervals) {
  
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        for (int i = 0; i < intervals.size(); i++) {
            if (ans.empty() || ans.back()[1] < intervals[i][0]) {
                ans.push_back(intervals[i]);
            } else {
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
        }
        return ans;

}
