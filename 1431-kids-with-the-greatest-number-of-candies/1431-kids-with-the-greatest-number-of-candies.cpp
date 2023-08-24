class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        
        vector<bool> result(candies.size(), false);
        int maxCandy = *std::max_element(candies.begin(), candies.end());
        for (int i = 0; i < candies.size(); i++){
            if ((maxCandy - candies[i]) <= extraCandies)
                result[i]=true;
        }
        return result;

    }
};