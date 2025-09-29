/*
Problem: Pascal's Triangle
Platform: Leetcode (Problem #118)
Approach: Simple Human Approach

T.C = O(N*N)
S.C = O(N)
*/

vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        vector<int> ansrow;

       
        ansrow.push_back(1);
        ans.push_back(ansrow);
        ansrow.clear();


        for(int i=1; i<numRows; i++){
            ansrow.push_back(1);
            for(int j=1; j<i; j++){
                ansrow.push_back(ans[i-1][j-1] + ans[i-1][j]);
            }
            ansrow.push_back(1);
            ans.push_back(ansrow);
            ansrow.clear();
        }

        return ans;
}
