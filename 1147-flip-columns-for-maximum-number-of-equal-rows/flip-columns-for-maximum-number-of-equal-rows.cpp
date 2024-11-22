class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string, int>count;  // Map to store frequency of each pattern
        for(const auto& row: matrix){
           string key="";
           // Convert row to pattern relative to its first element
           for(int col=0;col<row.size();col++){
              // 'T' if current element matches first element, 'F' otherwise
              if(row[0]==row[col])key+="T";
              else key+="F";
           }
           // Convert pattern to string and update its frequency in map
           count[key]++;
        }
        int maxfrequency=0; // Find the pattern with maximum frequency
        for(auto& ele:count){
            maxfrequency=max(ele.second,maxfrequency);
        }
      return maxfrequency;

    }
};