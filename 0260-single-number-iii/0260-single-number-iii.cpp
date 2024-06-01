class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) 
    {
        // sc(n), tc(n) // map
        // sc(1), tc(n^2) // for loop
        // bitmanupulation //  //striver
        long overall_xor = 0;
        for (int n : nums) {
            overall_xor ^= n;
        }

        int first_group_xor = 0;
        int second_group_xor = 0;
        
        //striver
        int bit_pos_dif = (overall_xor & (overall_xor-1)) ^ overall_xor;
        
       

        for (int i= 0 ; i<nums.size() ; i++) {
            // cout<<((num >> bit_pos_dif)& 1) <<" nums ";
            // if (((num >> bit_pos_dif) & 1) == 1) {
            //     first_group_xor ^= num;
            //     cout<<first_group_xor<<" first_group_xor "<<endl;
            // } else {
            //     second_group_xor ^= num;
            //     cout<<second_group_xor<<" second_group_xor "<<endl;
            // }
            if( nums[i] & bit_pos_dif )  first_group_xor ^= nums[i];
            else second_group_xor ^= nums[i];

        }

        return {first_group_xor, second_group_xor};
        
    }
};