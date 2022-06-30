class Solution {
public:
    int maxProfit(vector<int>& prices) {
      
        int max_Profit=0;
        int i=0; int j=1;
        while(j<prices.size()){
            if(prices[i]<prices[j]){
                int profit=prices[j]-prices[i];
                max_Profit=max(profit,max_Profit);
            }
            else
            {
                i=j;
            } 
            j++;
            
                 
        }
        return max_Profit;
    }
};