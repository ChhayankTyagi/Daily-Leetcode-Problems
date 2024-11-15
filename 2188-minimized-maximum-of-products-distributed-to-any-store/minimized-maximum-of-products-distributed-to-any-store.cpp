class Solution {
public:
    bool possible(int x,vector<int>& quantities,int shops){
        for(int &products : quantities){
            shops -= (products+x-1)/x;
            // ciel(products/x)
            if(shops<0)return false;
            // agar store khatam ho gaye pehle hi

        }return  true;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int left=1;
        int  right=*max_element(quantities.begin(),quantities.end());
             int  res=0;
        while(left<=right){
            int mid=left+(right-left)/2;
       
            if(possible(mid,quantities,n)){
                res=mid;
                right=mid-1;
            }
            else left=mid+1;
        }return res;
    }
};