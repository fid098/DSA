class Solution {
private:
    int days_taken(int& max_weight, vector<int>& weights){
        int days = 1;
        int curr_weight {};
        for (int i {}; i < weights.size(); i++){
            if (curr_weight + weights[i] > max_weight){
                days++;
                curr_weight = 0;
            }

            curr_weight += weights[i];
        }
        return days;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        /*
            packages must be shipped from one port to another withing days days 
            - the ith package on the belt has a weight of weights[i]. Each day we load the ship with packages on the conveyor belt in the order given by weights
            - we may not load more weight than the max weight capacity of the ship 

            return the least weight capacity of the ship that will result in all the pacakages being shipped within days days

            we want to find out the minimum total weight the ship can take in a day so that the whole thing can be shipped within days days

        */

        int low = *std::max_element(weights.begin(), weights.end());
        int high = std::accumulate(weights.begin(), weights.end(), 0);

        while (high > low){
            int midpoint = low + (high - low) / 2;
            if (days_taken(midpoint, weights) <= days){
                high = midpoint;
            }
            else{
                low = midpoint + 1;
            }
            
        }
        
        return low;
    }
};