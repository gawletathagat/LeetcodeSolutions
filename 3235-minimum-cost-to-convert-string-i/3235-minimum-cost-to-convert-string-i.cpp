class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) 
    {
        //Floyd Warshall's algorithm 
        vector<vector<long long >>adjList(26, vector<long long>(26,INT_MAX)) ;

        for( int i= 0 ; i<original.size(); i++)
        {
            adjList[original[i]-'a'][changed[i]-'a'] =
             min(adjList[original[i]-'a'][changed[i]-'a'] ,(long long)cost[i] );
        }

        int n = source.size() ;
        for( int k=0; k<26; k++)
        {
            for( int i= 0; i<26; i++)
            {
                for( int j= 0; j<26; j++)
                {
                    adjList[i][j] = 
                    min(adjList[i][j], adjList[i][k] + adjList[k][j]);
                }
            }
        } 

         long long ans= 0;
        for( int i= 0 ;i<n; i++)
        {
             if( source[i] == target[i]) continue;
             
             else if( adjList[source[i]-'a'][target[i]-'a']== INT_MAX) return -1;

           else if( source[i] != target[i] )
           ans = ans + adjList[source[i]-'a'][target[i]-'a'] ;

        
        }

        return ans==INT_MAX ? -1 : ans ;
        
        
    }
};