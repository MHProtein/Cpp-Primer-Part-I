#include <iostream>
#include <istream>
#include <ostream>
#include <fstream>
#include <string>

//ifstream and istringstream inherit//¼Ì³Ð from istream


int main(std::string argv[])
{
    //8.1.2 Condition States
    std::cout << std::istream::iostate() << std::endl;//iostate is a machine-dependent integral type that represents the condition state of a stream
    std::cout << std::istream::badbit << std::endl;  //iostate value used to indicate that a stream is corrupted//±ÀÀ£  //0x4
    std::cout << std::ostream::failbit << std::endl;//iostate value used to indicate that an IO operation failed    //0x2
    std::cout << std::ostream::eofbit << std::endl;//iostate value used to indicate that a stream hit end-of-file   //0x1
    std::cout << std::fstream::goodbit << std::endl;//iostate value used to indicate that a stream is not an error state.The value is guaranteed to be 0  //0x0
    std::cout << std::cin.eof() << std::endl;//true if eofbit in the stream is set
    std::cout << std::cin.fail() << std::endl;//true if failbit or badbit in the stream is set
    std::cout << std::cerr.bad() << std::endl;//true if badbit in the stream is set
    std::cout << std::cerr.good() << std::endl;//true if goodbit in the stream is set
    std::cout.clear();//Reset all condition values in the stream to valid//ÓÐÐ§µÄ state. return void
    std::cout.clear(std::ostream::failbit);//Reset the condition of the stream to flag
    std::cout << "test1" << std::endl;
    std::cout.setstate(std::ostream::goodbit);
    std::cout << "test2" << std::endl; //Adds specified condition to stream.
    std::cout << std::cout.rdstate() << std::endl;//Return current condition of the stream

    int a = 0, b = 0;
   // std::cin >> a;// if cin reads a type except int, cin will be put in an error state
    //only when a stream is in non-error state, we can write to or read from it
    //code ordinarily should check whether a stream is in error state before attempting to use it.
    //The easiest way to determine the state of a stream object is to use that object as a condition
    while (std::cin >> b);//==>while (!std::cin.fail());
    //badbit indicates a system level error such as an unrecoverable read or write error. It's usually not possible to use a stream once badbit has been set.
    //When a recoverable error occurs, the failbit is set, such as reading a character when numeric data is expected, you can correct such problems and continue to use the stream
    //Reaching eof sets both eofbit and failbit
    //If any of badbit, failbit,eofbit are set, then a condition that evaluates that stream will fail
    std::cin.clear(std::cin.rdstate() & ~std::ostream::failbit & ~std::ostream::badbit); //This turns off failbit and badbit but leaves eofbit untouched you can use setstate as well
                          //          1110                                ~0100                              ~1000
                          //          1110                                  1011                                 0111
                          //                           1010                                                          0111
                          //                                                           0010
                          //actually is 0110 since when eofbit is set, failbit is also set
    std::cerr << std::cout.rdstate() << std::endl;
    std::cout.clear();

    //8.1.3 Managing the Output Buffer
    //When will the buffer be flushed?//flush -> Á³ºì¡¢³å×ß£¨Wa¡®e£©¡¢³å²ÞËù
    //The program completes normally All output buffers are flushed as part of the return from main
    //When the buffer is full
    //You can flush it explicitly by using manipulator such as endl
    //You can use the unitbuf manipulator to set the stream's internal//neibu state to empty the buffer after each output operation. By default, unitbuf is set for cerr
    //An output stream might be tied to another stream. In this case, The buffer of the tied stream is flushed whenever the tied stream is read or written.
    std::cout << "hi";
    std::cin >> a;//buffer flushed
    std::cout << "you a-hole";
    /*buffer flushed*/ std::cerr << "Swear word detected. Get the fuck out of this game you motherfucker.";

    //except for endl, you can also use manipulators below to flush the buffer
    std::cout << "yooo" << std::flush; //this flushes the buffer and add no data
    std::cout << "byeeeeee" << std::ends; //this flushes the buffer and add a space

    std::cout << std::unitbuf;
    //unitbuf tells the stream to flush the buffer after every subsequent write
    //any output is flushed immediately, no buffer
    std::cout << std::nounitbuf;
    //This restore the state of the stream to normal buffering

    //Tying Input and Output Streams Together
    //This makes sure buffer will be flushed before attempting to read the input
    //You can not only tie a ostream to another ostream but also tie a istream to a ostream.
    std::cin.tie(&std::cout);
    //each stream can be tied to at most one stream at a time.
    //However, multiple streams can tie themselves to the same ostream
    std::cout << std::cin.tie() << std::endl;//this returns the pointer of the stream that is tied to cin
}
