#include <iostream>
#include <vector>
#include "game.hpp"
extern bool valid;
int main()
{
    printboard();
    std::cout << "GAME BEGINS\n player 1 : X\n player 2 : O\n";
    while (valid == true && is_winner() == false && filled() == false)
    {
        turn();
    }
    return 0;
}