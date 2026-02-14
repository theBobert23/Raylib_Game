#include "core/menu.hpp"

int main()
{
    Menu* menu = new Menu();
            
    menu->Init();

    delete menu;

    return 0;
}