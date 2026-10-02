class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) {
        stack<pair<int,int>> st;
        int n = nums.size();
        vector<int> keep(n, 0);
        for(int i = n-1; i >= 0; i--){
            if(st.empty()){
                st.push({nums[i], i});
                continue;
            }

            while(!st.empty() && st.top().first <= nums[i]){
                st.pop();
            }

            if(!st.empty()){
                keep[i] = st.top().second;
            }

            st.push({nums[i], i});
        }

        for(int i = 0; i < n; i++){
            if(keep[i] != 0){
                keep[i] = keep[i]-i;
            }
        }

        return keep;
    }
};
