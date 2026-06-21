class Solution {
public:

    string encode(vector<string>& strs) {
         string encoded="";
         for(string str:strs){
               encoded+=str;
               encoded+='-';
         }
         return encoded;
    }

    vector<string> decode(string s) {
          vector<string>output;
          string decoded="";
          for(int i=0;i<s.size();i++){
             if(s[i]!='-'){
                   decoded+=s[i];
             }
             else{
             output.push_back(decoded);
             decoded="";}
                       }
     return output;
    }
};
