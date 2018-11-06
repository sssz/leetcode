// S1: Fix Two num O(n^3)
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int len = nums.size();
        vector<vector<int>> re;
        sort(nums.begin(), nums.end());
        set<vector<int>> st;
        for(int i=0; i<len-2; i++){
            for(int j=i+1; j<len-1; j++){
                int p = j+1;
                int q = len-1;
                while(p<q){
                    int sum = nums[i] + nums[j] + nums[p] + nums[q];
                    if(sum < target) {
                        p++;
                    } else if(sum > target){
                        q--;
                    } else {
                        vector<int> tmp(4);
                        tmp[0]=nums[i];tmp[1]=nums[j];tmp[2]=nums[p];tmp[3]=nums[q];
                        if(st.find(tmp) == st.end()){
                            re.push_back(tmp);
                            st.insert(tmp);                        
                        }
                        p++;
                    }
                }
            }
        }
        return re;
    }
};


// S2: Hash Map O(n^2) ~ O(n^4)
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int len = nums.size();
        vector<vector<int>> re;
        sort(nums.begin(), nums.end());
        set<vector<int>> st;
        map<int, vector<pair<int, int>>> mp;
        for(int i=0; i<=len-2; i++){
            for(int j=i+1; j<=len-1; j++){
                int sum = nums[i] + nums[j];
                if(mp.find(sum) == mp.end()){
                    mp[sum] = vector<pair<int,int>>();
                }
                mp[sum].push_back(make_pair(i, j));
            }
        }
        for(int i=0; i<=len-2; i++){
            for(int j=i+1; j<=len-1; j++){
                int diff = target - nums[i] - nums[j];
                if(mp.find(diff) != mp.end()){
                    vector<pair<int, int>> v = mp[diff];
                    for(int k=0; k<v.size(); k++){
                        if(i == v[k].first || i == v[k].second || j == v[k].first || j==v[k].second){
                            continue;                            
                        }
                        vector<int> tmp(4);
                        tmp[0] = nums[i];
                        tmp[1] = nums[j];
                        tmp[2] = nums[v[k].first];
                        tmp[3] = nums[v[k].second];
                        sort(tmp.begin(), tmp.end());
                        if(st.find(tmp) == st.end()){
                            re.push_back(tmp);
                            st.insert(tmp);
                        }
                    }
                }
            }
        }
        return re;
    }
};
