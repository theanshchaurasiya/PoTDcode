class Solution {
public:
    static int toggle(int x){return 1-x;}
    int matrixScore(vector<vector<int>>& A) {
        int rows = A.size();
        int cols = A[0].size();
        
        //toggle a row when its first element is 0
        for(int i = 0; i < rows; i++){
            if(A[i][0]!=1){
                //in-place map elements of v to the function toggle
                transform(A[i].begin(), A[i].end(), A[i].begin(), toggle);
            }
            // copy(A[i].begin(), A[i].end(), ostream_iterator<int>(cout, " "));
            // cout << endl;
        }
        
        int sum = 0;
        //toggle columns and calculate the sum simultaneously
        for(int j = 0; j < cols; j++){
            int colSum = 0;
            for(int i = 0; i < rows; i++){
                colSum += A[i][j];
            }
            //toggle a column if toggling makes its sum bigger
            //, i.e. the original sum <= A.size()/2
            // cout << j << "'th colSum: " << colSum << ", rows/2: " << rows/2 << ", rows: " << rows << endl;
            colSum = colSum <= rows/2 ? rows-colSum : colSum;
            // cout << j << "'th colSum: " << colSum << ",shift: " << (cols-1-j) << ",final col sum: " << (colSum<<(cols-1-j)) << endl;
            sum += colSum<<(cols-1-j);
        }
        return sum;
    }
};