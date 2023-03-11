#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <string>
#include <array>
#include <initializer_list>
#include "D:\C++Primer\7.1 Defining Abstract Data Types\Sales_data.h"

void practice1()
{
    //Write a program to read a sequence of strings from the
    //standard input into a deque.Use iterators to write a loop to print the elements in the deque
    std::deque<std::string> StringDeq;
    std::string inputTemp;
    while (std::cin >> inputTemp)
    {
        StringDeq.emplace_back(inputTemp);
    }
    for (auto it = StringDeq.cbegin(); it != StringDeq.cend(); ++it)
    {
        std::cout << *it << std::endl;
    }
}

void practice2()
{
    /*
     * Rewrite the program from the previous exercise to use a
     *  list. List the changes you needed to make
     */
    std::list<std::string> StringList;
    std::string temp;
    while (std::cin >> temp)
    {
        StringList.emplace_back(temp);
    }
    for (auto it = StringList.cbegin(); it != StringList.cend(); ++it)
    {
        std::cout << *it << std::endl;
    }
}

void practice3()
{
    /*Write a program to copy elements from a list<int> into
two deques. The even-valued elements should go into one deque and the
odd ones into the other*/
    std::list<int> nums;
    std::deque<int> evenNums;
    std::deque<int> oddNums;
    for (int i = 0; i < 100; ++i)
    {
        nums.emplace_back(i);
    }
    for (int num : nums)
    {
        if (num % 2 == 0)
        {
            evenNums.emplace_back(num);
        }
        else
            oddNums.emplace_back(num);
    }
}

void practice4()
{
    /* Using the following definition of ia, copy ia into a vector
and into a list. Use the single-iterator form of erase to remove the
elements with odd values from your list and the even values from your
vector*/
    std::array<int, 11> arr = { 0,1,1,2,3,5,8,13,21,55,89 };
    std::vector<int> v(arr.begin(), arr.end());
    std::deque<int> d(arr.begin(), arr.end());
    auto vit = v.begin();
    auto dit = d.begin();
    while (vit != v.end(), dit != d.end());
    {
        if (*vit % 2 == 0)
            vit = v.erase(vit);
        if (*dit % 2 != 0)
            dit = d.erase(dit);
    }
}

void practice5(std::forward_list<std::string>& flst, std::string& str1, std::string& str2)
{
    /*Write a function that takes a forward_list<string> and
two additional string arguments. The function should find the first string
and insert the second immediately following the first. If the first string is
not found, then insert the second string at the end of the list*/
    auto curr = flst.begin();
    auto pred = flst.before_begin();
    while (curr != flst.end())
    {
        if(*curr==str1)
        {
            flst.emplace_after(pred, str2);
            return;
        }
        else
        {
            pred = curr;
            ++curr;
        }
    }
    flst.emplace_after(curr, str2);
}

int main()
{
    //9.3.1 Add Elements to a Sequential Container
    std::deque<int> Demo{ 1,2,3,4,5,6,7 };
    std::vector<int> v{ 123,123,34,546,7657,342 };
    std::initializer_list<int> iniList{ 123,325,5464,73,365,534,6 };

    Demo.push_back(8);   //Creates an element with the value
    Demo.emplace_back(9);    //at the end of the container

    Demo.push_front(0);                                            //Creates an element with the value
    Demo.emplace_front(-1); //emplace==>安置就位         //at the beginning of the container

    Demo.insert(Demo.begin() + 3, 20);  //Creates an element with the value before the element denoted//表示 by the iterator
    Demo.emplace(Demo.begin() + 4, 30);

    Demo.insert(Demo.begin() + 6, 10, 1); //Inserts 10 elements with 1 before the element denoted by the iterator
    Demo.insert(Demo.begin() + 15, v.begin(), v.end());
    Demo.insert(Demo.begin(), iniList);
    //forward_list has special versions of insert and emplace
    //push_back and emplace_back not valid for forward_list
    //push_front and emplace_front not valid for vector or string

    //WARNING:
    //Insert elements to a vector, string or deque will invalidates all existing iterators, pointers and references into the container

    //Containers use different strategies for allocating elements and that these strategies affect performance.
    //Adding elements anywhere but at the end of string and vector, or anywhere but at the front or the end of deque requires elements to be moved.
    //Moreover, adding elements to string or vector could cause the entire object to be reallocated.

    for (const int elem : Demo)
    {
        std::cout << elem << std::endl;
    }

    //Use push_back
    std::string AlphaBet;
    for (char c = 'a'; c != 'z'; ++c)
    {
        AlphaBet.push_back(c);
    }
    //When we an object to initialize a container, or insert an object into a container, a copy of that object's value is placed in the container, not the object itself.
    //so subsequent operations will not affect the original object

    //Use push_front
    std::list<int> l;
    for (int i = 0; i < 10; ++i)
    {
        l.push_front(i);
    }

    //Add Elements at Specified Position in Containers
    //Use the Return Value of insert
    std::vector<std::string> vec;
    auto it = vec.begin();
    std::string word;
    while (std::cin >> word)
    {
        it = vec.insert(it, word);
        //insert returns the iterator denoting the added element
    }

    //Use emplace Operation
    std::deque<std::string> lllllll;
    lllllll.emplace_back("motherfucker");
    lllllll.emplace_front("hey");
    lllllll.emplace(lllllll.begin() + 1, "you");
    //In the call to emplace-series-operations, the object is created directly in space managed by the container
    //The call to push_back creates a local temporary object that is pushed onto the container
    std::deque<Sales_data> salesDeq(10);
    salesDeq.emplace_back("C++Primer", 12, 29.99);
    //When we call an emplace member, we can also pass arguments to a constructor for the element type
    //So the parameters of emplace vary depending on element types
    //The emplace construct the object in the container, so we gotta make sure that the arguments match a constructor for the element type

    //9.3.2 Accessing the Elements
    if (!Demo.empty())
    {
        std::cout << Demo.front() << std::endl;//Returns a reference to the first element. Undefined if empty()==true
        std::cout << Demo.back() << std::endl;//Returns a reference to the last element. Undefined if empty()==true
        std::cout << Demo[10] << std::endl;  //Undefined if n>=size();
        std::cout << Demo.at(9) << std::endl;//if the index is out of range, throws an out_of_range exception
    }

    //The access members return references
    std::vector<int> vvv{ 1,2,3,4,5,6 };
    auto& ref = vvv.back();//a reference
    auto value = vvv.back();//a value

    //Subscripting and Safe Elements Access
    //If you want the subscripts to be valid, you can use at(), when the subscript is invalid, at() will throw out_of_range exception

    //9.3.3 Erasing Elements
    Demo.pop_back();//Remove last element. Undefined if empty.
    Demo.pop_front();//Remove first element. Undefined if empty
    Demo.erase(Demo.begin()); //Remove the element that denoted by the iterator and returns an iterator to the element after the one deleted or end(),Undefined if end()
    Demo.erase(Demo.begin() + 1, Demo.begin() + 11); //Removes the range of elements denoted by the iterators, returns an iterator to the element after the last one that was deleted of an end()
    Demo.clear();//Remove all
    //remove elements do not check their arguments. Make sure the element exist before removing them

    auto iter = vvv.begin();
    while (iter != vvv.end())
    {
        if (*iter % 2 != 0)
            iter = vvv.erase(iter);
    }

    //9.3.4 Specialized forward_list Operations
    //in a forward_list, when we add or remove an element, the element before the one we added or removed has a different successor//继任者
    //To add or remove an element, we need access to its predecessor//前驱 in order to update that element's links.
    //Since forward_list is a singly linked list, and wo don't have a easy way to get wo an element's preprocessor,
    //we need the operations to add or remove elements in a forward_list operate by changing the element after the given element.
    //That way we always have to access the elements that are affected by the change.

    std::forward_list<int> lst{ 1,2,3,4,5,6,7,8,9,10 };
    auto it1 = lst.before_begin(); //denoting a nonexistent element right before the first element of the list
    auto cit1 = lst.cbefore_begin();
    lst.insert_after(it1, 122);
    lst.insert_after(lst.begin(), { 233,23,232323,23,2,3232,3 });
    lst.insert_after(it1, 10, 1);
    lst.insert_after(lst.begin(), vvv.begin(), vvv.end());
    lst.emplace_after(it1, 122222);
    lst.emplace_front(lst.end(), 133333);
    lst.erase_after(lst.before_begin()); //returns a iterator denoting the element after the erased one
    lst.erase_after(lst.before_begin(), lst.begin());

    //we need two iterators, one denotes a element, another one denotes at its predecessor
    std::forward_list<int> flst{ 1,2,3,4,5,6,7,8,9,10 };
    auto cur = flst.begin();
    auto pre = flst.before_begin();
    while (cur != flst.end())
    {
        if (*cur % 2)
        {
            cur = flst.erase_after(pre);
        }
        else
        {
            pre = cur;
            ++cur;
        }
    }

    //9.3.5 Resizing a Container
    std::list<int> ilist(10, 42);
    ilist.resize(15);//adds five elements of value 0 to the back of the list
    ilist.resize(-25, -1);//adds ten elements of value -1 to the back of the list
    ilist.resize(5);//erases 20 elements from the back of list
    //If the list holds a class type and resize adds elements, we must supply an initializer or the element type must have a default constructor
    //Use resize member operation in vector, string or deque may cause invalidation of iterators, pointers or references

    //9.3.6 Container Operations May Invalidate Iterators
    //An invalidated pointer, reference, or iterator is one that no longer denotes an elements.

    //After an operation that adds elements to a container
    //    Iterators, pointers, and references to a vector or string are invalid if the container was reallocated.
    //If no reallocation happens, indirect references to elements before the insertion remain valid; those to elements after the insertion are valid
    //    Iterators, pointers, and references to a deque are invalid if we add elements anywhere but at the front or back.
    //If we add at the front or back, iterators are invalidated, but references and pointers to existing elements remain valid
    //    Iterators, pointers, and references(including the off-the-end and the before-the-beginning iterators) to a list or forward_list remain valid

    //After an operation that erases elements from a container
    //    All other iterators, references, or pointers(including the off-the-end and the before-the-beginning iterators) to a list or forward_list remain valid
    //    All other iterators, references, or pointers to a deque are invalidated if the removed elements are anywhere but the front or back.
    //If we remove elements at the back of the deque, the off-the-end iterator is invalidated but other iterators, references, and pointers are unaffected; they are also unaffected if we remove from the front
    //    All other iterators, pointers, references to a vector or string remain valid for elements before the removal point.
    ////NOTE: The off-the-end iterator is always invalidated when we remove elements.

    std::vector<int> v2{ 0,1,2,3,4,5,6,7,8,9,10 };
    auto it3 = v2.begin();
    while (it3 != v2.end())
    {
        if (*it3 % 2)
        {
            it3 = v2.insert(it3, *it3);
            it3+=2;
        }
        else
        {
            it3 = v2.erase(it3);
        }
    }

    //Avoid Storing the Iterator Returned from end
    //When we add or remove elements in a vector or string, or add elements or remove any but the first element in a deque, the iterator returned by end is always invalidated
    //calling end() is a very fast operation

    //auto begin = v.begin(), end = v.end();
    //while(begin!=end)
    //{
    //    ++begin;
    //    begin = v.insert(begin, 42);
    //    ++begin;
    //}
    //Undefined. We stored the value returned by the end operation in a local variable named end.
    //Adding an element invalidates the iterator stored in end.
    //That iterator either refers to an element in v nor any longer refers to one past the last element in v

    //Don't cache the iterator returned from end() in loops that inserts or delete elements in a deque, string or vector

}