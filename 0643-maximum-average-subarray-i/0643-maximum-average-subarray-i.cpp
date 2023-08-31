class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int tmpSum = std::accumulate(nums.begin(), nums.begin()+k,0);
        int maxSum = tmpSum;
        for (int i = 0; i < nums.size()-k; i++){
            tmpSum = tmpSum - nums[i] + nums[i+k];
            maxSum = max(maxSum, tmpSum);
        }
        return (double)maxSum/k;
    }
};
