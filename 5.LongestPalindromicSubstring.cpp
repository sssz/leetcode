//S1 dynamic programming O(n^2)
class Solution {
public:
    string longestPalindrome(string s) {
        int slen = s.size();
        if(slen == 0){
            return "";
        }
        int sublen[1010][1010];
        memset(sublen, -1, sizeof sublen);
        int ans = 0;
        int index;
        for(int i=0; i<slen; i++){
            for(int j=0; j<2 && i+j < slen; j++){
                if(s[i] == s[i+j]) {
                    sublen[i][i+j] = j+1;
                } else{
                    sublen[i][i+j] = -1;
                }
                if(sublen[i][i+j] >= ans){
                    ans = sublen[i][i+j];
                    index = i;
                }
            }
        }
        //cout << index << ans<<endl;
        for(int k=2; k<slen; k++){
            for(int i=0; i<slen && i+k < slen; i++) {
                int j = i+k;
                sublen[i][j] = (sublen[i+1][j-1] == -1 || s[i] != s[j]) ? -1 : sublen[i+1][j-1] + 2;
                if(sublen[i][j] >= ans){
                    ans = sublen[i][j];
                    index = i;
                }
                //cout << "i=" << i << "j=" << j << ":" << sublen[i][j]<<endl;
            }
        }
        return s.substr(index, ans);
    }
};

