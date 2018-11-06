class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //s = "tmmzuxt";
        if(s == "") {
            return 0;
        }
        int len = s.length();
        //cout << "len=" << len<< endl;
        map<char, int> char_index;
        int re=1;
        char_index[s[0]] = 0;
        for(int i=0, j=1; j<len; j++){
            if(char_index.find(s[j]) != char_index.end()){
                i = max(i, char_index[s[j]]+1);
            }
            re = max(re, 1+j-i);
            char_index[s[j]] = j;
            //cout <<i<<" "<<j<<" "<<re<<endl;
        }        
        return re;
    }
};