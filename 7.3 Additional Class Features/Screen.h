#ifndef SCREEN_H
#define SCREEN_H
#pragma once
#include <string>
#include <istream>
#include "Window_mgr.h"

class Window_mgr;

class Screen
{
public:
    friend class Window_mgr; //You can make a class as a friend to another class
    //friend void Window_mgr::clearScreen(const Screen& screen); //so does a member function
    using pos = std::string::size_type;
    //friend void Window_mgr::clear(Window_mgr::ScreenIndex i);
    //friend void Window_mgr::clearAll();
    //friend class Window_mgr;
    Screen() = default;

    Screen(pos Height, pos Width, char c) :height(nullptr), width(nullptr)
    {
        this->contents = new std::string(Height * Width, c);
        this->cursor = new pos(0);
        this->height = new pos(Height);
        this->width = new pos(Width);
        access_ctr = 0;
    }
    ~Screen();

    char get() const
    {
        return *(contents->begin() + *cursor);
    }

    char get(pos ht, pos wd) const;

    Screen& move(pos r, pos c);

    void some_member() const
    {
        ++access_ctr;
    }

    //functions below returns *this, and this allow us to continue to call member functions , see in main
    Screen& set(char chara);
    Screen& set(pos r, pos c, char chara);

    //Overloading based on const
    Screen& display(std::ostream& out);
    const Screen& display(std::ostream& out) const;

private:
    void do_display(std::ostream& out) const;

private:
    pos* cursor;//光标
    pos* height;
    pos* width;
    std::string* contents;
    mutable int access_ctr;
    //mutable means the member will never be a const, even in a const member function, and even the object is declared as a const
};
#endif
