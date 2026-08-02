class Solution {
public:
    bool checkBox(vector<vector<char>>& board, int sr, int sc) {
        unordered_set<char> st;

        for(int i = sr; i < sr + 3; i++) {
            for(int j = sc; j < sc + 3; j++) {
                if(board[i][j] == '.') continue;

                if(st.find(board[i][j]) != st.end())
                    return false;

                st.insert(board[i][j]);
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int row = 0; row < 9; row++) {
            unordered_set<char> st;

            for(int col = 0; col < 9; col++) {
                if(board[row][col] == '.') continue;

                if(st.find(board[row][col]) != st.end())
                    return false;

                st.insert(board[row][col]);
            }
        }
        for(int col = 0; col < 9; col++) {
            unordered_set<char> st;

            for(int row = 0; row < 9; row++) {
                if(board[row][col] == '.') continue;

                if(st.find(board[row][col]) != st.end())
                    return false;

                st.insert(board[row][col]);
            }
        }
        for(int sr = 0; sr < 9; sr += 3) {
            for(int sc = 0; sc < 9; sc += 3) {
                if(!checkBox(board, sr, sc))
                    return false;
            }
        }
        return true;
    }
};