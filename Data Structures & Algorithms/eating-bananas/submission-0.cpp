class Solution {
   public:
    bool iscan(int mid, vector<int>& piles, int h) {
        int total = 0;
        for (auto x : piles) {
            total += ceil(double(x) / mid);
        }
        return total <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size(), low = 1, high = *max_element(piles.begin(), piles.end());
        int ans = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (iscan(mid, piles, h)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
