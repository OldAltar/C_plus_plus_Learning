class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int tmp = 0, ans = 0;
        for(int i = 0; i < s.size(); ++i)
        {
            int j = mp.count(s[i]) ? mp[s[i]] : -1;
            mp[s[i]] = i;
            if(tmp < i - j)
            {
                ++tmp;
            }
            else
            {
                tmp = i - j;
            }
            ans = max(ans, tmp);
        }
        return ans;
    }
};
