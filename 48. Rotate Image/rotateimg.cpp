class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if(matrix.size()==1){
            return;
        }
        int temp = 0;
        for(int i=0;i<matrix.size()/2;i++){
            for(int j=i;j<matrix.size()-1-i;j++){
                
                temp = matrix[matrix.size()-1-j][i];
                matrix[matrix.size()-1-j][i] = matrix[matrix.size()-1-i][matrix.size()-1-j];
                matrix[matrix.size()-1-i][matrix.size()-1-j] = matrix[j][matrix.size()-1-i];
                matrix[j][matrix.size()-1-i] = matrix[i][j];
                matrix[i][j] = temp;
            }
        }
        
    }
};

