#include "Screen.h"


Screen::~Screen()
{
    delete contents;
    delete cursor;
    delete height;
    delete width;
}

char Screen::get(pos ht, pos wd) const
{
    pos row = ht * *width;
    return *(contents->begin() + (row + wd));
}

Screen& Screen::move(pos r, pos c)
{
    pos row = r * *width;
    *cursor = c + row;
    return *this;
}

Screen& Screen::set(char chara)
{
    *(contents->begin() + *cursor) = chara;
    return *this;
}

Screen& Screen::set(pos r, pos c, char chara)
{
    pos row = r * *width;
    *(contents->begin() + (row + c)) = chara;
    return *this;
}

Screen& Screen::display(std::ostream& out)
{
    do_display(out);
    return *this;
}

const Screen& Screen::display(std::ostream& out) const
{
    do_display(out);
    return *this;
}

inline void Screen::do_display(std::ostream& out) const
{
    out << *contents;
}
