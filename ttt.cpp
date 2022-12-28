#include <iostream>
#include <vector>
#include "head.hpp"

using namespace std;

int main() {
    greet();

    choose_game_mode();
    play();
    check_mode();

    show_credits();
    return 0;
}