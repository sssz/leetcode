struct node{
    node(int v, int p){
        this->value = v;
        this->pos = p;
    }
    int value;
    int pos;
};
bool mycmp(node n1, node n2) {
    return n1.value < n2.value;
}
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int nums_len = nums.size();
        vector<node> mn1, mn2;
        for(int i=0; i<nums_len; i++){
            struct node n1(nums[i], i);
            struct node n2(target-nums[i], i);
            mn1.push_back(n1);
            mn2.push_back(n2);
        }
        sort(mn1.begin(), mn1.end(), mycmp);
        sort(mn2.begin(), mn2.end(), mycmp);
        bool find = false;
        int i, j;
        for(i=0, j=0; i<nums_len && j < nums_len && !find; ){
            if(mn1[i].value ==  mn2[j].value && mn1[i].pos != mn2[j].pos) {
                find = true;
            }
            else if(mn1[i].value < mn2[j].value){
                i++;
            } else if(mn1[i].value > mn2[j].value) {
                j++;
            } else {
                if(i < nums_len-1 && mn1[i+1].value == mn1[i].value){
                    i++;
                } else if(j < nums_len-1 && mn1[j+1].value == mn2[j].value){
                    j++;
                }
            }
        }
        int i1 = mn1[i].pos;
        int i2 = mn2[j].pos;
        vector<int> re;
        re.push_back(min(i1, i2));
        re.push_back(max(i1, i2));        
        return re;
    }
};