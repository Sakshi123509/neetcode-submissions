class Solution {
   public:
    vector<int> singleNumber(vector<int>& nums) {
        int xr = 0;
        for (auto x : nums) {
            xr ^= x;
        }

        int mask = (xr & (-xr));
        int a = 0, b = 0;
        for (auto x : nums) {
            if (mask & x)
                a ^= x;
            else
                b ^= x;
        }
        return {a, b};
    }
};