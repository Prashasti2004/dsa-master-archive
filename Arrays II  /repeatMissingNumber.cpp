/*
Problem: Find the repeating and missing numbers
Platform: GfG (Problem #Missing And Repeating)
Approach: 
1. Using Pure Maths
2. Using XOR
Time Complexity: O(N)
Space Complexity: O(1)
*/


//Approach 1
vector<int> findTwoElement(vector<int>& arr) {
        // code here
        long long sumArr = 0;
        long long sumSqrArr = 0;
        int n = arr.size();
    
        for(int i = 0; i < n; i++){
            sumArr += arr[i];
            sumSqrArr += (long long)arr[i] * arr[i];  
        }
    
        long long actualSumN = (1LL * n * (n+1)) / 2;
        long long actualSqrN = (1LL * n * (n+1) * (2LL*n + 1)) / 6;
    
        long long diff = sumArr - actualSumN;                        
        long long sum  = (sumSqrArr - actualSqrN) / diff;
    
        long long r = (diff + sum) / 2;   // repeating number
        long long m = r - diff;           // missing number
    
        return {(int)r, (int)m}; 
}


//Approach 2



