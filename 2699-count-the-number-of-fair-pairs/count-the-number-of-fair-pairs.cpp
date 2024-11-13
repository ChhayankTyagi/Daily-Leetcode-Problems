class Solution {
public:
long long lower_bound(vector<int>&nums,int low,int high,int ele){
    while(low<=high){
        int mid=low+((high-low)/2);
        if(nums[mid]>=ele)high=mid-1;
        else low=mid+1;
       
    } return low;
}
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        // sort the array
        sort(nums.begin(),nums.end());
        long long ans=0;
        for(int  i=0;i<nums.size();i++){
            // assume nums[i] as first element of pair
            // low indicates number of possible pair with sum<lower element
            int low=lower_bound(nums,i+1,nums.size()-1,lower-nums[i]);
      // high indicates number of possible pair with sum<higher element
          int high=lower_bound(nums,i+1,nums.size()-1,upper-nums[i]+1);
        //   logic is high-low=number of elements in the given range
        ans+=1LL*(high-low);
        }
        return ans;
    }
};