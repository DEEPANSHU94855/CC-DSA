class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int temp = matrix[i][j];
                matrix[i][j]=matrix[j][i];
                matrix[j][i]=temp;
            }
        }
        for(int i=0;i<n;i++){
            int lt=0,rt=n-1;
            while(lt<rt){
                int temp=matrix[i][lt];
                matrix[i][lt]=matrix[i][rt];
                matrix[i][rt]=temp;

                lt++;
                rt--;
            }
        }
    } 
};