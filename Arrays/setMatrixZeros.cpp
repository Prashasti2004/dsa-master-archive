/*
Problem: Set Matrix zeros - If an element is 0; set it's entire row and column to 0's.
Platform: Leetcode (Problem #73)
Approach: 
1. Make 2 vectors rows and cols and store wherever we find 0's.
T.C = O(2*m*n)   S.C = O(m+n)

2. Make the first row and col of the given matrix our required vectors. 
T.C = O(2*m*n)   S.C = O(1)
*/



//Approach 1
void setZeroes(vector<vector<int>>& matrix){
  int row = matrix.size();
  int col = matrix[0].size();

  vector<int> rows(row, 0);
  vector<int> cols(col, 0);

  // set the rows and cols vectors
  for(int i=0; i<row; i++){
    for(int j=0; j<col; j++){
      if(matrix[i][j] == 0){
        rows[i] = 1;
        cols[j] = 1;
      }
    }
  }


  for(int i=0; i<row; i++){
    for(int j=0; j<col; j++){
      if(rows[i] || cols[j]){
        matrix[i][j] = 0;
      }
    }
  }

}


//Approach 2
void setZeroes(vector<vector<int>>& matrix){
  int row = matrix.size();
  int col = matrix[0].size();

  bool firstRowHasZeros = false;
  bool firstColHasZeros = false;

  //first row
  for(int i=0; i<col; i++){
    if(matrix[0][i] == 0){
      firstRowHasZeros = true;
      break;
    }
  }

  //first col
  for(int i=0; i<row; i++){
    if(matrix[i][0] == 0){
      firstColHasZeros = true;
      break;
    }
  }

  //set the first row and first col
  for(int i=1; i<row; i++){
    for(int j=1; j<col; j++){
      if(matrix[i][j] == 0){
        matrix[0][j] = 0;
        matrix[i][0] = 0;
      }
    }
  }

  for(int i=1; i<row; i++){
    for(int j=1; j<col; j++){
      if(matrix[0][j] == 0 || matrix[i][0] == 0){
        matrix[i][j] = 0;
      }
    }
  }

  if(firstRowHasZeros){
    for(int i=0; i<col; i++){
      matrix[0][i] = 0;
    }
  }

  if(firstColHasZeros){
    for(int i=0; i<row; i++){
      matrix[i][0] = 0;
    }
  }

  
}

