class Solution {
public:
    string addBinary(string a, string b) {
        string result;
        int addone=0;
        int n=a.size()>b.size()?a.size():b.size();
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        for(int i=0;i<n;i++){
            int ai=i<a.size()?a[i]-'0':0;
            int bi=i<b.size()?b[i]-'0':0;
            int val=(ai+bi+addone)%2;
            addone=(ai+bi+addone)/2;
            result.insert(result.begin(),val+'0'); 
        }
        if(addone==1)
            result.insert(result.begin(),'1');
        return result;    
        }
};