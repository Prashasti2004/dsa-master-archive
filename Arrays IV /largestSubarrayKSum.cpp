/*
Problem: Given an array arr[] containing integers and an integer k, your task is to find the length of the longest subarray where the sum of its elements is equal to the given value k. 
If there is no subarray with sum equal to k, return 0.
Platform: GfG (Problem #Longest Subrray with Sum K)
Approach: Using Map which contains PreSum of the Array and using logic of remaining sum
Time Complexity: O(n)
Space Complexity: O(n)
*/

int longestSubarray(vector<int>& arr, int k) {
        // code here
         int n=arr.size();
        //Declaring Map Data structure to store
        map<int,int> PreSumMap;
        //Initializing Variables
        int Sum=0;
        int MaxLen=0;
        //Running loop for sum counting
        for(int i=0;i<n;i++){
            Sum+=arr[i];
            //Here updating MaxLen
            if(Sum==k){
                MaxLen=max(MaxLen,i+1);
            }
            //Calculating sum of remaining Part
            int rem=Sum-k;
            //Calculate The Length and update maxlen
            if(PreSumMap.find(rem)!=PreSumMap.end()){
                int len=i-PreSumMap[rem];
                MaxLen=max(MaxLen,len);
            }
            //UPdating the map checking the condition
            if(PreSumMap.find(Sum)==PreSumMap.end()){
                PreSumMap[Sum]=i;
            }
        }
        return MaxLen;
}

