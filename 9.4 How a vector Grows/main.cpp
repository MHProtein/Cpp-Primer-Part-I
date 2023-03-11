#include <vector>
#include <string>

int main()
{
    //When string and string have to get new memory, their implementations typically allocate capacity beyond what is immediately needed.
    //The container holds this storage in reserve and uses it to allocate new elements as they are added. Thus, there is no need to reallocate the container for each new element.
    //The reallocating strategy of vector makes its growing efficiency even higher than a list or a deque

    //Members to Manage Capacity
    std::vector<int> Demo;
    Demo.shrink_to_fit(); //Request to reduce capacity() to equal size()      
    Demo.capacity(); //Number of elements a vector can have before reallocation is necessary
    Demo.reserve(100); //Allocate space for at least n elements
    //shrink_to_fit valid only for vector, string, and deque
    //capacity and reserve valid only for vector and string

    //reserve does not change the number of elements in the container; it affects only how much memory the vector preallocates
    //If the space we request is less than or equal to the existing capacity, reserve does nothing, else, it will allocate at least as much as and may allocate more than the requested amount
    //You can call shrink_to_fit to ask a deque, vector, or string to return unneeded memory. This function indicates that we no longer need any excess//∂‡”‡ capacity.
    //However, the implementation is free to ignore this request. There is no guarantee a call to shrink_to_fit will return memory

    //capacity and size
    //vector implementation appears to follow a strategy of doubling the current capacity each time it has to allocate new storage


}