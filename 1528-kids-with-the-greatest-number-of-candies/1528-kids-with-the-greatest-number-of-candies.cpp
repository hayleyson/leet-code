class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        
        vector<bool> result;
        int maxCandy = *std::max_element(candies.begin(), candies.end());
        int threshold = maxCandy - extraCandies;
        for (int i = 0; i < candies.size(); i++){
            if (candies[i] >= threshold)
                result.push_back(true);
            else
                result.push_back(false);
        }
        return result;

    }
};