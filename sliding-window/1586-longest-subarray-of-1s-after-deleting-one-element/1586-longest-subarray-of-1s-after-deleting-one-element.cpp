class Solution {
public:
    int longestSubarray(vector<int>& nums) {    
        // int maxCnt=0, cnt=0;
        // int delIndex=-1;
        // for(int i=0; i<nums.size(); i++){
        //     if(nums[i]==1) cnt++;
        //     else if(delIndex==-1) delIndex=i;
        //     else{
        //         cnt=i-delIndex-1;
        //         delIndex=i;
        //     }
        //     maxCnt=max(maxCnt, cnt);
        // }
        // if (delIndex==-1) maxCnt--;
        // return maxCnt;

        /* solution by shivam-727 */
        int i=0, j=0;
        int c0=0;
        int mx=0;
        int n=nums.size();
        while(j < n){
            if (nums[j]==0) c0++;
            while (i < n && c0 == 2){
                if (nums[i] == 0) c0--;
                i++;
            }
            mx = max(mx, j-i);
            j++;
        }
        return mx;

    }
};
        