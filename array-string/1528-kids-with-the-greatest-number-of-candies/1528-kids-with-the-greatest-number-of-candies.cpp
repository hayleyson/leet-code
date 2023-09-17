class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        
        vector<bool> result;
        for (int n: candies){
            if (n >= (*std::max_element(candies.begin(), candies.end()) - extraCandies))
                result.push_back(true);
            else
                result.push_back(false);
        }
        return result;

    }
};