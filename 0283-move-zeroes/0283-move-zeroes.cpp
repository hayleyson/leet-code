class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int cnt = 0; //[0,1,0]
        // for loop, if it is 0 then remove it
        for (int i =0; i<nums.size(); i++){
            if(nums[i]==0){
                nums.erase(nums.begin()+i);
                nums.push_back(0); //i=0 //[1,0,0]
                i--; //i=-1
                cnt++;
                if (cnt==nums.size()) break;
            }
        }
    }
};