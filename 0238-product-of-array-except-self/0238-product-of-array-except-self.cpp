#include <vector>
#include <algorithm>
#include <functional> //std:multiplies

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        /* solution provided by its_vishal_7575 */
        int n = nums.size();
        vector<int> ans(n);
        vector<int> leftProduct(n);
        vector<int> rightProduct(n);
        leftProduct[0]=1;
        for(int i=1;i<n;i++){
            leftProduct[i]=leftProduct[i-1] *nums[i-1];
        }
        rightProduct[n-1]=1;
        for(int i=n-2;i>=0;i--){
            rightProduct[i] =rightProduct[i+1]*nums[i+1];
        }
        for(int i=0;i<n;i++){
            ans[i] = leftProduct[i] * rightProduct[i];
        }
        return ans;
    }
};