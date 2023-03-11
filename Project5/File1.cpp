#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <string>
#include <array>
#include <iostream>
#include <initializer_list>

bool vector_find(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end, const int target)
{
    for(;begin!=end;++begin)
    {
        if(*begin==target)
        {
            return true;
        }
    }
    return false;
}

std::vector<int>::const_iterator vector_find2(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end, const int target)
{
    for (; begin != end; ++begin)
    {
        if (*begin == target)
        {
            return begin;
        }
    }
    std::cerr << "Target Not Find!" << std::endl;
    return end;
}

void practice()
{
    std::list<int> l{ 1,2,3,4,5,6,7 };
    std::vector<double> v(l.begin(), l.end());
}

void practice2()
{
    std::list<const char*> l{ "hello","the damn","world" };
    std::vector<std::string> v;
    v.assign(l.begin(),l.end());
}
int main()
{

    std::deque<int> d(10);
    d.push_back(12);
    int s = 0;
    std::deque<int>::value_type f = 10;//value_type -->int
    std::deque<int>::reference x = s; //value_type&
    std::deque<int>::const_reference c = s; //const value_type&
    d.emplace(d.begin() + 2, 20);//use 20 to construct an element in d
    std::deque<int>::reverse_iterator ri = d.rend();// returns the last element of d
    std::deque<int>::reverse_iterator rii = d.rbegin();//returns the address in front of the first element
    //and of course there is a const version
    std::deque<int>::const_reverse_iterator cri;

    //9.1.2 Iterator
    //Programming Implication//含义 in Using Left-inclusive Interval//左闭合区间
    //if begin==end, the range is empty
    //if begin != end, there is at least one element in the range, and begin refers to the first element in that range
    //We can increment//递增 begin some number of times till begin==end
    //This makes the operation below safe
    for (auto it = d.cbegin(); it != d.cend(); ++it)
    {
        std::cout << *it << std::endl;
        //If end==begin, then the range is empty, and the will exit the loop
    }

    std::vector<int> v{ 1,2,3,4,5 };
    auto ggg = vector_find2(v.cbegin(), v.cend(), 6);

    //9.2.4. Containers Definitions and Initializations
    
    std::list<std::string> authors{ "Milton","Shakespear","Austen" };
    std::vector<const char*> articles{ "a","an","the" };
    std::vector<std::string> copy(authors.begin(), authors.end());
    std::vector<std::string> copy2(articles.begin()+1, articles.begin()+2);

    //Library array has fixed size
    std::array<int, 10> arr;
    std::array<int, 10>::size_type size = 10;

    //9.2.5 Assign and swap
    std::vector<int> c1{ 1,3,5,7,9 };
    std::vector<int> c2{ 2,4,6,8,10 };
    std::swap(c1, c2);//usually a lot faster than c1=c2;
    std::deque<int> d1;
    std::initializer_list<int> il{ 1,2,3,4,5 };
    d1.assign(il);
    d1.assign(c1.begin(), c1.end());
    d1.assign(10, 1); //{1*10}
    //Assignment related operations invalidate iterators, references, ans pointers into the left-hand container. Aside from string and array they remain valid after a swap and the containers to which they refer are swapped
                                                                                                                                                                                                                                                                                     //他们引用的容器被交换
    //Use assign
    //Sequential containers(except array) also define a member named assign that lets us assign from a different but compatible type, or assign from a subsequence of a container.
    //The assign operation replaces all the elements in the left-hand container with (copies of) the elements specified by its arguments
    std::list<std::string> names;
    std::vector<const char*> oldstyle;
    //names = oldstyle; //error
    names.assign(oldstyle.begin(), oldstyle.end());
    //Because the existing elements are replaced, the iterators passed to assign must not refer to the container on which assign is called.

    //Use swap
    std::vector<std::string> svec(10);
    auto ite = svec.begin() + 2; //points at svec[2]
    std::vector<std::string> svec2(10);
    std::swap(svec, svec2);
    //With the exception of arrays, swapping two containers is guaranteed to be fast ---- the elements themselves are not swapped; internal data structures are swapped
    //The fact that elements are not moved means that, with the exception of string, iterators, references, and the containers are not invalidated.
    //They refer to the same elements as they did before the swap, but those elements are in a different container.
    //After the swap, ite now points at svec2[2]
    //swapping two arrays does exchange the elements. As a result, swapping two arrays requires time proportional//正比 to the number of elements in the array
    //so pointers, references and iterators of array remain bound to the same element they denoted before the swap.
    //Use a non-member swap is a good habit.

    //9.2.6 Container Size Operations
    svec.size();
    svec.empty();
    svec.max_size();//returns a number that is greater than or equals to the number of elements a container of the type can contain
    //forward_list provides max_size and empty but not size

    //9.2.7 Container Relational Operations
    
}
