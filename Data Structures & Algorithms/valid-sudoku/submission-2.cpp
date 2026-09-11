class Solution {
public:
    bool checkBox(int p, int q, vector<vector<char>>& vec){
        vector<int> f(10);
        for (int i=0; i<3; i++){
            for (int j=0; j<3; j++){
                if (vec[p+i][q+j] != '.') {
                    int num = vec[p+i][q+j] - '0';
                    f[num]++;

                    if (f[num] > 1) return false;
                }
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& vec){
        // check horizontal
        for (int i=0; i<9; i++){
            vector<int> f(10);
            for (int j=0; j<9; j++){
                if (vec[i][j] != '.') {
                    int num = vec[i][j] - '0';
                    f[num]++;

                    if (f[num] > 1) return false;
                }
            }
        }

        // check vertical
        for (int j=0; j<9; j++){
            vector<int> f(10);
            for (int i=0; i<9; i++){
                if (vec[i][j] != '.') {
                    int num = vec[i][j] - '0';
                    f[num]++;

                    if (f[num] > 1) return false;
                }
            }
        }

        // check boxes
        for (int i=0; i<9; i+=3){
            for (int j=0; j<9; j+=3){
                if (!checkBox(i, j, vec)) return false;
            }
        }

        return true;
    }
};
