#ifndef WINDOW_MAR_H
#define WINDOW_MAR_H
#pragma once
#include"Screen.h"
#include <vector>

class Screen;
class Window_mgr
{
public:
    using ScreenIndex = std::vector<Screen>::size_type;
    Window_mgr();
    void clear(ScreenIndex i);
    void clearAll();
    ScreenIndex AddScreen();
private:
    Screen* scr;
    std::vector<Screen>* screens;
    void clearScreen(const Screen& screen);
};
#endif
