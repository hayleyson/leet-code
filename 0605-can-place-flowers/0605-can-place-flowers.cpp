class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count=0, consec=1;
        for(const int& i:flowerbed){
            if (i==0) consec++;
            else{
                count+=(consec-1)/2;
                consec=0;
            }
        }
        consec++;
        count+=(consec-1)/2;
        if (n<=count) return true;
        return false;
    }
};