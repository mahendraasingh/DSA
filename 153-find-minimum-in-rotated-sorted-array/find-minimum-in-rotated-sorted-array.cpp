class Solution {
public:
    int findMin(vector<int>& nums) {
        int min = INT_MAX;
        unordered_set<int>st;
        for(int i=0; i<nums.size(); i++){
            st.insert(nums[i]);
        }
        for(auto x:st){
            if(x < min){
                min = x;
            }
        }
        return min;
    }
};