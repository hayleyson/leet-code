class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {

        // added after solution by deepankyadav
        if (nums.size() == 1){
            return (double) nums[0];
        }
        // my solution
        int tmpSum = std::accumulate(nums.begin(), nums.begin()+k,0);
        int maxSum = tmpSum;
        for (int i = 0; i < nums.size()-k; i++){
            tmpSum = tmpSum - nums[i] + nums[i+k];
            maxSum = max(maxSum, tmpSum);
        }
        return (double)maxSum/k;
    }
};
