/*
Problem: Find Unique paths in the grid from [0,0] to [m-1][n-1]
Platform: Leetcode (Problem #62)
Approach: Using DP and recursion
Time Complexity: O(n*m)
Space Complexity: O(n*m)
*/

    int solve(int r, int c, int row, int col, vector<vector<int>>& dp){
            if(r == row-1 && c == col-1){
                return 1;
            }
            if(r>=row || c >=col){
                return 0;
            }
    
            if(dp[r][c] != -1){
                return dp[r][c];
            }
            //going down
            int down = solve(r+1, c, row, col, dp);
    
            //going right
            int right = solve(r, c+1, row, col, dp);
            return dp[r][c]=down+right;
            
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));

        int num = solve(0, 0, m, n, dp);

        if(m==1 && n==1){
            return num;
        }
        
        return dp[0][0];
    }
