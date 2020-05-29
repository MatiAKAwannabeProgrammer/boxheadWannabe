#include "game.hpp"

int main()
{
    Game game; 
    while (game.running()){

        game.pollEvents();

        game.update();

        game.render();
    }
   return 0;
}
