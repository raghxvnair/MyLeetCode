class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans=0,firstRow1s=0,secRow1s=0,flag=0;
        for(auto& str : bank){
            for(auto& ch : str){
                if(ch=='1') {
                    if(flag==0) firstRow1s++;
                    else secRow1s++;
                }  
            }
            if(secRow1s){
                ans=ans+firstRow1s*secRow1s;
                firstRow1s=secRow1s;
                secRow1s=0;
            }
            if(firstRow1s) flag=1;
        }
        return ans;
    }
};