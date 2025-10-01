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
vector<int> findTwoElement(vector<int>& arr){
        int xr = 0;
        int n = arr.size();

        for(int i=0; i<n; i++){
            xr = xr ^ arr[i];
            xr = xr ^ (i+1);
        }

        int number = xr & (~(xr-1));

        int zero = 0;
        int one = 0;

        //Groupism
        for(int i=0; i<n; i++){
            if((arr[i] & number) != 0){
                one = one ^ arr[i];
            }else{
                zero = zero ^ arr[i];
            }


            if(((i+1) & number) != 0){
                one = one ^ (i+1);
            }else{
                zero = zero ^ (i+1);
            }

        }

        //see which is repeater
        int cnt = 0;

        for(int i=0; i<n; i++){
            if(arr[i] == zero){
                cnt++;
            }
        }

        if(cnt == 2){
            return {zero, one};
        }


        return {one, zero};
}


