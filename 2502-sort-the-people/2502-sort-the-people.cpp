class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) 
    {
        vector<pair<int, string>>pr;
        for( int i= 0 ;i<names.size() ; i++)
        {
            pr.push_back({heights[i], names[i]}) ;
        }

        sort(pr.begin(), pr.end() );

        vector<string>ans;
        for( int i= pr.size()-1 ; i>=0;i--)
        {
            ans.push_back(pr[i].second) ;
        }

        return ans;
        
    }
};