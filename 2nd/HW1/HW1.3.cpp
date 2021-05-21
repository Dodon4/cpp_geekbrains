#include <iostream>
#include <cassert>

using namespace std;


class Stack 
{
private:
    int *m_array;
    int m_length = 10;
    int _stack_length = 0;
public:
    Stack ()
    {
        m_array = new int[m_length];
    }
    
    ~Stack ()
    {
        delete[] m_array ;
    }
    
    void reset() 
    { 
        for(int i = 0; i < _stack_length; i++)
        m_array[i] = 0;
        
    }
    bool push(int a)
    {
        if(_stack_length == m_length)
        {
            return false;
        } 
        m_array[_stack_length] = a;
        _stack_length++;
        return true;
    }
    void print() 
    {
        cout << "( ";
        for(int i = 0; i < _stack_length; i++)
        {
            cout << m_array[i] << " ";
        }
        cout << ")" << endl;
    }
    int pop()
    {
        assert(_stack_length > 0);
        _stack_length--;
        return m_array[_stack_length];
    }
};
int main()
{
    Stack stack;
    stack.reset();
    stack.print();
    
    stack.push(3);
    stack.push(7);
    stack.push(5);
    stack.print();
    
    stack.pop();
    stack.print();
    
    stack.pop();
    stack.pop();
    stack.print();
    return 0;
}
