/*
Problem: Search a 2D Matrix
Platform: Leetcode (Problem #74)
Approach: Using Binary Search Algorithm with some modification using mathematical formulae for row and column indices
Time Complexity: O(log(row*col))
Space Complexity: O(1)
*/

bool searchMatrix(vector<vector<int>>& matrix, int target) {
          int s = 0;
          int row = matrix.size();
          int col = matrix[0].size();
          int e = (row*col)-1;
          int mid = s + (e-s)/2;

          while(s<=e){
            if(matrix[mid/col][mid%col] == target){
                return true;
            }else if(matrix[mid/col][mid%col] > target){
                e = mid-1;
            }else{
                s = mid+1;
            }
            mid = s + (e-s)/2;
          }

          return false;
}
