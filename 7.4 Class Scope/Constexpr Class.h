#pragma once

class Debug
{
public:
    constexpr Debug(bool b = true) :hardware(b), io(b), other(b) {}
    constexpr Debug(bool HARDWARE, bool IO, bool OTHER) : hardware(HARDWARE), io(IO), other(OTHER) {}
    constexpr bool any()
    {
        return hardware || io || other;
    }
    void set_io(bool b) { io = b; }
    void set_hw(bool b) { hardware = b; }
    void set_other(bool b) { other = b; }

private:
    bool hardware;
    bool io;
    bool other;
};
