class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int i,j,k;
        int len = nums.size();
        sort(nums.begin(), nums.end());
        int md=(1<<31) - 1, ii, jj,kk,s;
        for(i=0; i<len && md > 0; i++){
            if(i >0 && nums[i] == nums[i-1]){continue;}
            j=i+1; k=len-1;
            while(j < k && md > 0){
                s = nums[k] + nums[j];
                if(abs(s+nums[i]-target) < md){
                    md = abs(s+nums[i]-target);
                    ii=nums[i];
                    jj=nums[j];
                    kk=nums[k];
                }
                if(s + nums[i] < target) j++;
                else if(s + nums[i] > target) k--;
            }
        }
        return ii+jj+kk;
    }
};