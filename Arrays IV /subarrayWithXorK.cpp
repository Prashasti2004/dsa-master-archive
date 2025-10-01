/*
Problem: Given an array of integers arr[] and a number k, count the number of subarrays having XOR of their elements as k.
Platform: GfG (Problem #Count Subarrays with given XOR)
Approach: Use unordered_map
Time Complexity: O(n)
Space Complexity: O(n)
*/

long subarrayXor(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        int cnt = 0;
        unordered_map<int, int> mpp;
        int xr = 0;
        mpp[xr]++;
        
        for(int i=0; i<n; i++){
            xr = arr[i] ^ xr;
            int x = xr  ^ k;
            
            cnt += mpp[x];
            
            mpp[xr]++;
        }
        
        return cnt;
}
