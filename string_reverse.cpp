#include <iostream>
using namespace std;

template <typename T>

class stacks
{

    T *data;
    int capacity;
    int nextindex;

public:
    stacks()
    {
        capacity = 4;
        nextindex = 0;
        data = new T[capacity];
    }

    void push(T element)
    {

        if (nextindex == capacity)
        {
            capacity = capacity * 2;
            T *newdata = new T[capacity];
            for (int i = 0; i < nextindex; i++)
            {
                newdata[i] = data[i];
            }
            data = newdata;
        }

        data[nextindex] = element;
        nextindex++;
    }

    T top()
    {
        if (nextindex == 0)
        {
            return 0;
        }

        return data[nextindex - 1];
    }

    int getsize()
    {
        if (nextindex < 0)
        {
            return 0;
        }
        return nextindex;
    }

    T pop()
    {
        if (isEmpty())
        {
            return 0;
        }
        nextindex--;
        return data[nextindex];
    }

    bool isEmpty()
    {
        return nextindex == 0;
    }
};

int main()
{

    stacks<char> obj;
    int a = 0;
    string str;
getline(cin,str);
    int size = str.length();
    for (int i = 0; i < size; i++)
    {   
            obj.push(str[i]);
    
    }
    
    for(int i=0; i<size; i++){
    str[i] = obj.pop();
    }
    cout<<str;

    return 0;
}