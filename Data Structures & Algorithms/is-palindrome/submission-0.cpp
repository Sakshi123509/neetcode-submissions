class Solution {
   public:
    bool checkpalindrome(string s) {
        int n = s.size();
        int l = 0, r = n - 1;
        while (l < r) {
            if (s[l] != s[r])
                return false;
            else
                l++;
            r--;
        }
        return true;
    }
    bool isPalindrome(string s) {
        string ans = "";
        for (auto ch : s) {
            if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
                ans += ch;
        }
        for (int i = 0; i < ans.size(); i++) {
            char ch = ans[i];
            ans[i] = ((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9')) ? ch : ch + 32;
        }
        return checkpalindrome(ans);
    }
};
