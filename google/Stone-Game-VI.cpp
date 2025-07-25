class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        // for alice want : alice pt > bob pt and
        // bob wants bob pt > alice pt

        // So acc to ques, alice_pts = Sum of all stones of alice side - sum of stones for alice picked by bob 
        // So, alice want that : alice_total - alice pts of bob stones > bob pts of bob stones 
        // => alice total > alice pts of bob stones + bob ... => ..alice total > (total sum of values of stones)    
        // picked by bob
        // So bob will try to pick up the max possible sum and alice also will do so to make bobs sum minimum

        int stones_cnt = aliceValues.size();
        vector<int> values_sum;

        int alice_total_stones = 0;
        for(int i = 0; i < stones_cnt; i++){
            int sum = aliceValues[i] + bobValues[i];
            alice_total_stones += aliceValues[i];
            values_sum.push_back(sum);
        }
        sort(values_sum.begin(), values_sum.end());
        reverse(values_sum.begin(), values_sum.end());

        int bob_stones_sum = 0;
        for(int ind  = 0; ind < stones_cnt; ind++){
            if(ind & 1) bob_stones_sum += values_sum[ind];
        }


        int decider = alice_total_stones - bob_stones_sum;
        return decider ? decider/abs(decider) : 0;
    }
};


// Solved becz we just converted equation in 1 variable from 2 where 1 variable was dependent on other directly 
