#include <vector>
#include <algorithm>
#include <functional> //std:multiplies

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        /* solution provided by its_vishal_7575 */
        
        /* approach 3 */
        int n = nums.size();
        vector<int> output(n);

        //cumulative product of numbers left to nums[i] 
        output[0] = 1;
        for(int i=1; i<n; i++){
            output[i]=output[i-1]*nums[i-1];
        }

        //multiply numbers right to nums[i]
        int right=1;
        for(int i=n-1;i>=0;i--){
            output[i]*=right;
            right*=nums[i];
        }
        return output;
        
        /* approach 2 
        int n = nums.size();
        vector<int> ans(n);
        vector<int> leftProduct(n);
        vector<int> rightProduct(n);
        leftProduct[0]=1;
        for(int i=1;i<n;i++){
            leftProduct[i]=leftProduct[i-1] *nums[i-1];
        } // leftProduct: [1, nums[0], nums[0]*nums[1], ..., nums[0]*nums[1]*...*nums[n-3]*nums[n-2]]
        rightProduct[n-1]=1;
        for(int i=n-2;i>=0;i--){
            rightProduct[i] =rightProduct[i+1]*nums[i+1];
        } // rightProduct: [nums[1]*nums[2]*...*nums[n-2]*nums[n-1], ..., nums[n-1]*nums[n-2],nums[n-1],1]
        for(int i=0;i<n;i++){
            ans[i] = leftProduct[i] * rightProduct[i];
        } // ans: [nums[1]*nums[2]*...*nums[n-1], nums[0]*nums[2]*nums[3]*...*nums[n-1], nums[0]*nums[1]*nums[3]*nums[4]*...*nums[n-1], ..., nums[0]*nums[1]*...*nums[n-3]*nums[n-2]]
        return ans; */
    }
};