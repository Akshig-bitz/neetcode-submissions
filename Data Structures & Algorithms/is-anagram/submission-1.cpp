class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        int n = s.size();
        unordered_map<char,int> setofs;
        unordered_map<char,int> setoft;
        for(int i=0;i<n;i++) {
            setofs[s[i]]++;
            setoft[t[i]]++;
        }
        if(setoft == setofs) return true;
        else return false;
    }
};
