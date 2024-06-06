class Solution {
public:
    bool isNStraightHand(vector<int>&  nums, int k) 
    {
        if( nums.size()%k !=0) return false;

        sort(nums.begin(), nums.end() );
        int ans=0;
        unordered_map<int,int>mp;
        for( int i= 0 ;i<nums.size(); i++) mp[nums[i]]++;

        for( int i= 0 ; i<nums.size() ; i++)
        {
            if( mp.find(nums[i]) != mp.end() )
            {
                int j=1;
                for(  j = 1; j<k; j++)
                {
                   if( mp.find(nums[i]+j) != mp.end() )
                   {
                     mp[nums[i]+j]--;
                   }
                   else break;
                   if( mp[nums[i]+j] <=0 ) mp.erase(nums[i]+j) ;
                }
                if( j== k) ans++;
                mp[nums[i]]--;
                if( mp[nums[i]] <=0 ) mp.erase(nums[i]) ;
            }

        }
        cout<<ans;
        return ans==nums.size()/k ;
        
    }
};