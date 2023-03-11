#include "Screen.h"
#include "Window_mgr.h"
#include <iostream>
#include <string>

class Screen;
//Should be used in a header
//This is a forward declaration
//This introduces a class but we don't know the members it includes
//It can define a pointer or a reference and can declare(not define) functions that use an incomplete type as a parameter or return type

int main()
{
    Screen screen(1080, 1920, ' ');
    screen.set(120, 240, 'c').set('m').move(1, 2);
}  