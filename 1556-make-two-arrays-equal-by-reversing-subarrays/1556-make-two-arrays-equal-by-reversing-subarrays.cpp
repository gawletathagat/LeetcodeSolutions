class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr)
    {
        unordered_map<int,int>mp;
        for( auto x: arr) mp[x]++;
        for( auto x: target)
        {
          if( mp.find(x) ==mp.end()) return false;

          mp[x]--;

          if(mp[x]==0)
          {
             mp.erase(x);
          }

        }
        return mp.size()==0;
        
    }
};