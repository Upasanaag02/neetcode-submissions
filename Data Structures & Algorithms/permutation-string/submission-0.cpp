class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        if(s1.size() > s2.size())
            return false;

        unordered_map<char,int> freq;
        unordered_map<char,int> need;

        for(char c : s1)
            freq[c]++;

        int k = s1.size();

        for(int i = 0; i < k; i++)
            need[s2[i]]++;

        if(freq == need)
            return true;

        for(int i = k; i < s2.size(); i++) {

            need[s2[i]]++;

            need[s2[i-k]]--;

            if(need[s2[i-k]] == 0)
                need.erase(s2[i-k]);

            if(freq == need)
                return true;
        }

        return false;
    }
};