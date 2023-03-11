#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <array>
#include <string>
#include <iostream>

int main()
{

    std::vector<int> v; //Flexible-size array. Supports fast random access.
                                 //Inserting or deleting elements other than at the back may be slow.
    std::deque<int> d; //双队列//Double-ended queue//队列. Supports fast random access.
                                  //Fast insert/delete as front or back.
    std::list<int> l;//Doubly linked list. Supports only bidirectional sequential access.  //双向顺序访问
                         //Fast insert/delete at any point in the list.
    std::forward_list<int> forl;//Singly linked list. Supports only sequential access in one direction.
                                             //Fast inset/delete at any point in the list
    std::array<int, 10> arr;//Fixed-size array. Supports fast random access.
                                         //Cannot add or remove elements
    std::string s;// A specialized container, similar to vector, that contains characters.
                       //Fast random access. Fast inset/delete at the back

    //You can insert/delete at any point in the list or forward_list, but as the price, these types don't support random access
    //to access an element, you can only iterate through the container

    //Decide which Sequential Container to Use
    //Use a vector, unless you've got a better option
    //If the program has lots of small elements and space overhead matters, don't use list/forward_list
    //If the program requires random access to elements to elements, use a vector or deque
    //If the program needs to insert or delete elements in the middle of the container, use a list or forward_list
    //If the program needs to insert or delete elements at the front and the back, but not in the middle, use a deque
    //    If the program needs to inset elements in the middle of the container only while reading input,
    //and subsequently needs random access to the elements:
    //   First, decide whether you actually need to add elements in the middle of a container.
    //   If you must inset into the middle, consider using a list for the input phase.
    //Once the input is complete, copy the list into a vector.

    //If you really ain't sure which container to use, use common operations to both list and vector:
    //use iterators rather than subscripts//下标 to avoid random access

    l.push_back(12);

    for(auto elem:l)
    {
        std::cout << elem << std::endl;
    }
}