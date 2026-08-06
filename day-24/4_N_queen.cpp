#include <bits/stdc++.h>
using namespace std;
void print_arr(vector<vector<char>> board, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << "---------------------------\n";
} // mistake happened here iwas calling print_arr ,before defining it
bool is_safe(vector<vector<char>> board, int row, int col)
{
    // horizontal case
    int n = board.size();
    for (int j = 0; j < n; j++)
    {
        if (board[row][j] == 'Q')
        {
            return false;
        }
    }
    // vertical
    for (int i = 0; i < n; i++)
    { // for optimzing it little bit you use (i<row) so that it will check upto row
        if (board[i][col] == 'Q')
        {
            return false;
        }
    }
    // diagonal left case (omly upper)
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }
    }
    // diagonal right case
    for (int i = row, j = col; i >= 0 && j < n; i--, j++)
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }
    }
    return true;
}
void n_queen(vector<vector<char>> board, int row)
{
    int n = board.size();
    if (n == row)
    {
        print_arr(board, n);
        return;
    }
    for (int j = 0; j < n; j++)
    {
        if (is_safe(board, row, j))
        {
            board[row][j] = 'Q';
            n_queen(board, row + 1);
            board[row][j] = '.'; // backtracking starts here
        }
    }
}
int main()
{
    vector<vector<char>> board;
    int n = 4;
    for (int i = 0; i < n; i++)
    {
        vector<char> new_row;
        for (int j = 0; j < n; j++)
        {
            new_row.push_back('.');
        }
        board.push_back(new_row);
    }
    print_arr(board, n);
    n_queen(board, 0);
    return 0;
}