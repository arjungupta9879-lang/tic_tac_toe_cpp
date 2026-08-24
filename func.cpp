#include <iostream>
#include <vector>
std::vector<char> board = {'0', '1', '2', '3', '4', '5', '6', '7', '8'};
int x;
int o;
bool valid = true;
void printboard()
{
    std::cout << " " << board[0] << " | " << board[1] << " | " << board[2] << "\n";
    std::cout << "---|---|---\n";
    std::cout << " " << board[3] << " | " << board[4] << " | " << board[5] << "\n";
    std::cout << "---|---|---\n";
    std::cout << " " << board[6] << " | " << board[7] << " | " << board[8] << "\n";
}
bool is_winner()
{
    if (board[0] == 'X' && board[1] == 'X' && board[2] == 'X')
    {
        return true;
    }
    else if (board[0] == 'O' && board[1] == 'O' && board[2] == 'O')
    {
        return true;
    }
    else if (board[3] == 'X' && board[4] == 'X' && board[5] == 'X')
    {
        return true;
    }
    else if (board[3] == 'O' && board[4] == 'O' && board[5] == 'O')
    {
        return true;
    }
    else if (board[6] == 'X' && board[7] == 'X' && board[8] == 'X')
    {
        return true;
    }
    else if (board[6] == 'O' && board[7] == 'O' && board[8] == 'O')
    {
        return true;
    }
    else if (board[0] == 'X' && board[4] == 'X' && board[8] == 'X')
    {
        return true;
    }
    else if (board[0] == 'O' && board[4] == 'O' && board[8] == 'O')
    {
        return true;
    }
    else if (board[2] == 'X' && board[4] == 'X' && board[6] == 'X')
    {
        return true;
    }
    else if (board[2] == 'O' && board[4] == 'O' && board[6] == 'O')
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool filled()
{
    bool check = true;
    int j = 0;
    while (check && j < 9)
    {
        if (board[j] == 'X' || board[j] == 'O')
        {
            check = true;
        }
        else if (board[j] != 'X' || board[j] != 'O')
        {
            check = false;
        }
        j++;
    }
    return check;
}
void invalid(int i)
{
    for (int p = 0; p < 10; p++)
    {
        if (board[i] == 'X' || board[i] == 'O')
        {
            std::cout << "INVALID ENTRY\n";
            std::cin >> i;
            x = i;
            o = i;
            valid = false;
        }
        else
        {
            valid = true;
            return;
        }
    }
    std::cout << "Try again\n";
    return;
}
void turn()
{
    std::cout << "player1 choose where to play:";
    std::cin >> x;
    invalid(x);
    if (valid)
    {
        board[x] = 'X';
        printboard();
    }
    else
    {
        return;
    }
    if (is_winner() == true)
    {
        std::cout << "player 1 wins the game\n";
        return;
    }
    if (filled() == true)
    {
        std::cout << "the game ended in a draw\n";
        return;
    }
    std::cout << "player2 choose where to play:";
    std::cin >> o;
    invalid(o);
    if (valid)
    {
        board[o] = 'O';
        printboard();
    }
    else
    {
        return;
    }
    if (is_winner() == true)
    {
        std::cout << "player 2 wins the game\n";
        return;
    }
}