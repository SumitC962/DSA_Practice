class Solution {
public:
    int countTriples(int n) {
        int cnt =0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                int sumSq = i*i + j*j;
                int k = sqrt(sumSq);
                if(k <= n && k*k == sumSq){
                    cnt++;
                }
            }
        }
        return cnt*2 ;
    }
};