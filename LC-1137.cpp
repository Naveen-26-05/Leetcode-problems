class Solution {
public:
    int tribonacci(int n) {
        int x=0,y=1,z=1;
        int res=0;
        if(n==0){
            return 0;
        }
        else if(n==1 || n==2){
            return 1;
        }
       
       for(int i=0;i<n-2;i++){
          res=x+y+z;
          x=y;
           y=z;
           z=res;
       } 
        return res;
    }
};
