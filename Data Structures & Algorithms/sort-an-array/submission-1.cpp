class Solution {
   public:
    int partition(int l, int h, vector<int>& nums) {
        int pivot = nums[l];
        int i = l, j = h;
        while (i < j) {
            while (nums[i] <= pivot && i <= h - 1) {
                i++;
            }
            while (nums[j] > pivot && j >= l + 1) j--;
            if (i < j) swap(nums[j], nums[i]);
        }
        swap(nums[l], nums[j]);
        return j;
    }
    void quicksort(int l, int h, vector<int>& nums) {
        if (l < h) {
            int p = partition(l, h, nums);

            quicksort(l, p - 1, nums);
            quicksort(p + 1, h, nums);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        // quicksort
        int n = nums.size();
        quicksort(0, n - 1, nums);
        return nums;
    }
};