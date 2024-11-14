class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        // brute-force approach (linear-traversal)
        // int maxquant=*max_element(quantities.begin(),quantities.end());
        // for(int i=1;i<maxquant;i++){
        //     int x=i;
        //     int stores=0;
            
        // for (int q : quantities) {
        //     stores += (q + x - 1) / x; // Equivalent to ceil(q / x)
        // }

        // if(stores<=n)  
        // return x;
        
        // }
        // return 1;
           int left = 1;
    int right = *max_element(quantities.begin(), quantities.end());

    while (left < right) {
        int mid = left + (right - left) / 2;
        int storesNeeded = 0;
        
        // Calculate the total number of stores needed for this mid value
        for (int q : quantities) {
            storesNeeded += (q + mid - 1) / mid; // Equivalent to ceil(q / mid)
        }
        
        if (storesNeeded <= n) {
            // If stores needed is within our limit, try a smaller max limit
            right = mid;
        } else {
            // If more stores are needed, increase the max limit
            left = mid + 1;
        }
    }
    
    return left; // `left` is now the minimized maximum x

    }
};