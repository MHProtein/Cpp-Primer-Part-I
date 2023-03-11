#include "Window_mgr.h"

Window_mgr::Window_mgr()
{
    screens = new std::vector<Screen>{ Screen(24,80,' ') };
    scr = new Screen;
}

void Window_mgr::clear(ScreenIndex i)
{
    const Screen& s = *(screens->begin() + i);
    clearScreen(s);
}

void Window_mgr::clearAll()
{
    
    for (const Screen& screen : *screens)
    {
        clearScreen(screen);
    }
}

Window_mgr::ScreenIndex Window_mgr::AddScreen()
{
    return 1;
}

void Window_mgr::clearScreen(const Screen& screen)
{
    screen.contents->clear();
}
