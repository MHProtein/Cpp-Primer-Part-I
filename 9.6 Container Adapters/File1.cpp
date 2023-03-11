#include <stack>
#include <queue>
#include <deque>
#include <string>
#include <iostream>
#include <vector>

void practice(const std::string& expr)
{
    std::stack<char, std::string> sta(expr);
    std::string temp;
    while (!sta.empty())
    {
        if (sta.top() != '(' && sta.top() != ')')
        {
            temp.push_back(sta.top());
        }
        sta.pop();
    }
    std::string expression(temp.rbegin(), temp.rend());

    std::cout << expression << std::endl;
    

}

int main()
{
    //An adaptor is a mechanism for making one thing act like another.
    //e.g. the stack adaptor takes a sequential container (other than array or forward_list) and makes it operate as if it were a stack.
    std::deque<int> deq{ 1,2,3,4,5 };
    std::stack<int> stk(deq);

    //By default, both stack and queue are implemented in terms of deque, and a priority_queue is implemented on a vector
    //We can override the default container type by naming a sequential container as a second type argument when we create the adaptor
    std::stack<std::string, std::vector<std::string>> str_stk;
    std::vector<std::string> svec{"hi", "ni hao", "konnichiwa"};
    std::stack<std::string, std::vector<std::string>> str_stk2(svec);

    //Stack Adaptor
    //Stack requires push_back, pop_back, and back operations, so we can use any container type (except array and forward_list) for a stack
    for (size_t ix = 0; ix != 10; ++ix)
        stk.push(ix);
    while(!stk.empty())
    {
        std::cout << stk.top() << std::endl;
        stk.pop();
    }
    for (size_t ix = 0; ix != 10; ++ix)
        stk.push(ix);
    stk.emplace(2);

    //The Queue Adaptors
    //The queue adaptor requires back, push_back, front, and push_front, so it can be built on a list or deque but not on a vector.
    //The priority_queue requires random access in addition to the front, push_back, and pop_back operations; it can be built on a vector or a deque but not on a list

    std::queue<int> q(deq);
    q.pop();//Removes but does not return, the front element or highest-priority element from the queue or priority_queue, respectively //分别
    q.push(2); //Create an element with value item or constructed from args at the end of queue or in its appropriate position in priority_queue
    q.front(); 
    q.back();
    q.emplace(3);

    std::priority_queue<int, std::deque<int>> pq;
    //pq.top(); //return the highest-priority element

    //The library queue uses a first-in, first-out(FIFO) storage and retrieval policy. Object entering the queue are placed in the back and objects leaving the queue are removed from the front.
    
    practice("hello (world)");
}
