class Solution {
public:
    vector<int> prefix;
    int total;
    Solution(vector<int>& w) {
        total = 0;
        for (int x : w) {
            total += x;
            prefix.push_back(total);
        }
    }
    int pickIndex() {
        int target = rand() % total + 1;
        int low = 0;
        int high = prefix.size() - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;

            if (prefix[mid] >= target) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};