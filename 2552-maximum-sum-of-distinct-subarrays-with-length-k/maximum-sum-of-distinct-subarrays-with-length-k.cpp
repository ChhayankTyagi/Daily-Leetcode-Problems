class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
       long  long ans=0;
       int n=nums.size();
       unordered_map<int,int>mp;  //to track duplicacy of elements in window
       long long currSum=0;
       for(int i=0;i<n;i++){
        currSum=currSum+nums[i];
        mp[nums[i]]++;
        if(i==(k-1)){
            if(mp.size()==k){ans=max(ans,currSum);}
        }
        else if(i>=k){
            //agar window size s bahar hui 
            currSum-=nums[i-k];
            mp[nums[i-k]]--;
            if(mp[nums[i-k]]==0)mp.erase(nums[i-k]);
            if(mp.size()==k)ans=max(ans,currSum);
        }

       }
       return ans;
    }
};