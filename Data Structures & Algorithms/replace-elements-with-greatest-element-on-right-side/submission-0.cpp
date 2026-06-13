class Solution {
   public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n, -1);
        int maxright = -1;
        for (int i = n - 1; i >= 0; i--) {
            ans[i] = maxright;
            maxright = max(maxright, arr[i]);
        }
        return ans;
    }
};