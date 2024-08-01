class Solution {
public:
    int countSeniors(vector<string>& v) {
      //  11,12
      int ans= 0;
      for( int i= 0 ; i<v.size();i++)
      {
        string s = v[i];
        int n = s.size()-1;
        cout<<s[11]-'a'<<" "<<s[12]<<endl;
       // cout<<(s[11])*10 + (s[12])<<endl;
        int num = ((s[11])-'0')*10 + ((s[12])-'0') ;

        if( num > 60) ans++;
      }

      return ans;
    }
};