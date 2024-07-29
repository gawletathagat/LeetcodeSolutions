class Solution {
public:
    int numTeams(vector<int>& rating) 
    {
        int n = rating.size() ;
        int total = 0;
        for( int j = 0; j<n ; j++)
        {
            int less = 0;
            for( int i= 0; i<j; i++)
            {
                if( rating[i] < rating[j] ) less++;
            }
             int more=0;
            for( int k = j+1; k<n ; k++)
            {
                if( rating[j] < rating[k] ) more++;
            }

            total = total + less*more ;
        }

         for( int j = 0; j<n ; j++)
        {
            int less = 0;
             int more=0;
            for( int i= 0; i<j; i++)
            {
                if( rating[i] > rating[j] ) more++;
            }
            
            for( int k = j+1; k<n ; k++)
            {
                if( rating[j] > rating[k] ) less++;
            }

            total = total + less*more ;
        }

         return total;
        
    }
};