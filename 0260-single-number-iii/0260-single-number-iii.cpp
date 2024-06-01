class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) 
    {
        // sc(n), tc(n) // map
        // sc(1), tc(n^2) // for loop
        // bitmanupulation
        int overall_xor = 0;
        for (int n : nums) {
            overall_xor ^= n;
        }

        int first_group_xor = 0;
        int second_group_xor = 0;

        int bit_pos_dif = 0;
        while (((overall_xor >> bit_pos_dif) & 1) != 1) {
            bit_pos_dif++;
        }
       

        for (int num : nums) {
            cout<<((num >> bit_pos_dif)& 1) <<" nums ";
            if (((num >> bit_pos_dif) & 1) == 1) {
                first_group_xor ^= num;
                cout<<first_group_xor<<" first_group_xor "<<endl;
            } else {
                second_group_xor ^= num;
                cout<<second_group_xor<<" second_group_xor "<<endl;
            }
        }

        return {first_group_xor, second_group_xor};
        
    }
};