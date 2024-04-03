class Solution {
public:
    
    int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
    bool solve(int i, int j,int ind, string &word,vector<vector<char>> &board)
    {
        int n=board.size(),m=board[0].size();
        int siz=word.size();

        if(ind>=siz)
        return 1;
        //base condition
        if(i<0 || j<0 || i>=n || j>=m)
            return 0;

        if(board[i][j]!=word[ind])
        return 0;

        char c=board[i][j];
        board[i][j]='-';

        for(int k=0;k<4;k++)
        {
            int x=dir[k][0]+i;
            int y=dir[k][1]+j;

            if(solve(x,y,ind+1,word,board))
             return 1;
        }
        board[i][j]=c;
        return 0;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size(),m=board[0].size();
        int siz=word.size();

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]==word[0])
                {
                    if(solve(i,j,0,word,board))
                    return 1;
                }
            }
        }
        return 0;
    }
};