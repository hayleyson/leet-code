class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count=0, consec=1, div;
        for(const int& i:flowerbed){
            if (i==0) consec++;
            else{
                div=((consec-1 >0)?consec-1:0)/2;
                count+=div;
                consec=0;
            }
        }
        consec++;
        div=((consec-1 >0)?consec-1:0)/2;
        count+=div;
        if (n<=count) return true;
        return false;
    }
};