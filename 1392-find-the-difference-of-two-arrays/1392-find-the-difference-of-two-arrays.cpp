// class Solution {
// public:
//     vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        
//         unordered_set<int> s1(nums1.begin(), nums1.end()), s2(nums2.begin(), nums2.end());
//         vector<int> v1, v2;

//         for(const int& n: s1){
//             if(s2.find(n)==s2.end()) v1.push_back(n);
//         }
//         for(const int& m: s2){
//             if(s1.find(m)==s1.end()) v2.push_back(m);
//         }

//         return vector<vector<int>>{v1, v2};

//     }
// };

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(),n2 = nums2.size();
        set<int> ans1, ans2;
        int i = 0 ,j = 0;
        vector<int>v1,v2;
        
        unordered_map<int, int> m;
        unordered_map<int, int> m1;
        
         while(i < n1 || j < n2) {
            if( i < n1 ) m[nums1[i++]]++;    
            if( j < n2 ) m1[nums2[j++]]++;
        }

        i  = 0 ,j = 0;
         while(i < n1 || j < n2) {
            if( i < n2  && m[nums2[i]] == 0) ans2.insert (nums2[i]);    
            if( j < n1 && m1[nums1[j]] == 0) ans1.insert(nums1[j]);
            i++;
            j++;
        }


        for(auto i : ans1) v1.push_back(i);
        for(auto i : ans2) v2.push_back(i);

        return {v1, v2};

    }
};