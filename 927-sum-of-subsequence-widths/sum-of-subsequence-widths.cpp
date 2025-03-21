class Solution {
public:
    int sumSubseqWidths(vector<int>& nums) {
        long long ans=0; long long MOD=1000000007;
        long long n=nums.size();
        long long c=1;
        sort(nums.begin(), nums.end());
        for(int i=0;i<n;i++,c=c*2%MOD){
            ans=(ans+nums[i]*c-nums[n-i-1]*c)%MOD;
        }
        return (ans+MOD)%MOD;
    }
};