class Solution {
   public:
    int scoreOfString(string s) {
        int sum = 0;
        for (int i = 0; i < s.size() - 1; i++) {
            int x = s[i];
            int y = s[i + 1];
            sum += abs(y - x);
        }
        return sum;
    }
};