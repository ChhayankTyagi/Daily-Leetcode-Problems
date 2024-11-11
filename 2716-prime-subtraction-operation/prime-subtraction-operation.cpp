class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        int largest= *max_element(nums.begin(),nums.end());
        // find max of array to pre-calculate the prime numbers
        vector<bool> primeSieve(largest+1,false);
        primeSieve[0]=primeSieve[1]=true;
        for(int i=2;i*i<=largest;++i){
            if(!primeSieve[i]){
                for(int j=2*i;j<=largest;j+=i){
                    primeSieve[j]=true;
                }
            }
        }
        // Calculate Prime Numbers
        vector<int>prime;
        for(int i=2;i<primeSieve.size();++i){
            if(!primeSieve[i]){
                prime.push_back(i);
            }
        }

        int n=nums.size();
        for(int i=n-2;i>=0;i--){
            if(nums[i]>=nums[i+1]){
                auto it = upper_bound(prime.begin(),prime.end(),nums[i]-nums[i+1]);
                if(it==prime.end())return false;
                nums[i]-=*it;
            }
            if(nums[i]<=0)return false;
        }
// binary approach;
    //     int index=findMaxSub(prime,0,nums[0]);
    //     if(index!=-1){
    //         nums[0]-=prime[index];
    //     }
    //     for(int i=1;i<nums.size();++i){
    //         index=findMaxSub(prime,nums[i-1],nums[i]);
    //     if(index == -1 && nums[i]<=nums[i-1]){
    //         return false;
    //     }
    //     else if(index!=-1){
    //         nums[i]-=prime[index];
    //     }
    //     }
    //     return true;
    // }

    // private:
    // int findMaxSub(const vector<int>&primes,int prev,int cur){
    //     if(primes.empty()){
    //         return -1;
    //     }
    //     int left=0;
    //     int right=primes.size()-1;
    //     while(left <= right){
    //         int mid=left+(right-left)/2;
    //         if(cur-primes[mid]<=prev){
    //             right=mid-1;
    //         }
    //         else{
    //             if(mid==primes.size()-1 || cur-primes[mid+1]<=prev){
    //                 return mid;
    //             }
    //             else{
    //                 left =mid+1;
    //             }
    //         }
    //     }
    //     int mid=right;
    //     return (mid >=0 && cur-primes[mid]<=prev)? -1:mid;
    return true;
    }
};