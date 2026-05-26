class TrieNode{
    public:
    unordered_map<char, TrieNode*> children;
};

class Trie{
    public:
    TrieNode* root;
    Trie(){
        root = new TrieNode(); //creates empty trie
    }

    void insert(const string& word){
        TrieNode* node = root;
        for(char c : word){
            if(node->children.find(c) == node ->children.end()){
                node->children[c] = new TrieNode(); //creates new node
            }
            node = node->children[c];
        }
    }

    int lcp(const string& word, int prefixlen){
        TrieNode* node = root;
        int i=0;
        while(i<min((int)word.length(), prefixlen)){
            if(node->children.find(word[i]) == node->children.end()) return i;
            node = node->children[word[i]];
            i++;
        }
        return min((int)word.length(), prefixlen);
    }
};

class Solution{
    public:
    string longestCommonPrefix(vector<string>& strs){
        if(strs.size() == 1) return strs[0];
        int mini =0;
        for(int i=0; i< strs.size(); i++){
            if(strs[mini].size() > strs[i].size()) mini = i;
        }

        Trie trie;
        trie.insert(strs[mini]);
        int prefixlen = strs[mini].length();
        for(int i=0; i< strs.size(); i++) prefixlen = trie.lcp(strs[i], prefixlen);
        return strs[0].substr(0, prefixlen);
    }
};