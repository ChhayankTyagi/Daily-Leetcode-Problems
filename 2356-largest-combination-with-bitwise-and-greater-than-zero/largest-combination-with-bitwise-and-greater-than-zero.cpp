class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int maxfreq=0;
        for(int i=0;i<24;i++){
            int freq=0;
            for (int x: candidates){
                if((x&(1<<i))!=0)freq++;
            }
            maxfreq= max(maxfreq,freq);
        }
        return maxfreq;
    }
};