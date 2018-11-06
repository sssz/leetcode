// S1 Fix One Num, Two Sum


// S2 HashMap O(n^2)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> re;
        map<int, int> mp;
        set<vector<int>> st;
        for(int i=0; i<nums.size(); i++){
            if(mp.find(nums[i]) != mp.end()){
                mp[nums[i]] = mp[nums[i]] + 1;
            } else{
                mp[nums[i]] = 1;
            }
        }
        vector<int> nn;
        for(auto it = mp.begin(); it != mp.end(); it++){
            for(int i=0; i<min(3, it->second); i++){
                nn.push_back(it->first);
            }
        }
        nums = nn;
        sort(nums.begin(), nums.end());

        for(int i=0; i<nums.size(); i++){
            for(int j=i+1; j<nums.size(); j++){
                int left = -1*(nums[i] + nums[j]);
                if(mp.find(left) != mp.end()){
                    if(mp[left] > ((left == nums[i]) + (left == nums[j]))) {
                        vector<int> tmp;
                        tmp.push_back(nums[i]);
                        tmp.push_back(nums[j]);
                        tmp.push_back(-1*(nums[i] + nums[j]));
                        sort(tmp.begin(), tmp.end());
                        if(st.find(tmp) == st.end()){
                            st.insert(tmp);                            
                            re.push_back(tmp);                        
                        }
                    }
                }
            }            
        }
        return re;
    }
};