class Solution {
public:
    int longestPalindrome(string s) 
    {
       unordered_map<int,int>mp;
       for( int i= 0 ; i<s.size() ; i++ )mp[s[i]]++;

       int odd= 0, ans = 0;
       for( auto x: mp)
       {
        
        if( x.second >1 ) 
        ans= ans+ x.second/2*(2) ;

        if( x.second %2 ==1) odd=1;
       } 

      return ans + odd ;
        
    }
};