class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        if(n==1)
            return 1;

        int left = 0;
        int ans = 1;
        int prev = 0;
        for(int right=1; right<n; right++){
            int curr = 0;
            if(arr[right] > arr[right-1])
                curr = 1;
            else if(arr[right] < arr[right-1])
                curr = -1;
            if(curr == 0){

                left = right;
                prev = 0;
            }
            else if(prev == 0 || curr != prev){

                ans = max(ans, right-left+1);
                prev = curr;
            }
            else{

                left = right-1;
                prev = curr;
            }
        }

        return ans;
    }
};