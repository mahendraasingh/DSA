class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {

        int low = 0;
        int high = 0;
        for (int weight : weights) {
            low = max(low, weight);
            high += weight;
        }
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int currentWeight = 0;
            int requiredDays = 1;
            for (int weight : weights) {
                if (currentWeight + weight <= mid) {
                    currentWeight += weight;
                }
                else {
                    requiredDays++;
                    currentWeight = weight;
                }
            }
            if (requiredDays <= days) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return low;
    }
};