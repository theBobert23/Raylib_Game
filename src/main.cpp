#include "games/menu/menu.hpp"

int main()
{
    Menu* menu = new Menu();
            
    menu->Init();
    menu->Run();

    delete menu;

    return 0;
}