//==============================================================
//
//               ####  ######    ###     ####  ##  ##   ####
//              ##       ##     ## ##   ##     ## ##   ##
//               ###     ##    ##   ##  ##     ####     ###
//                 ##    ##    #######  ##     ## ##      ##
//              ####     ##    ##   ##   ####  ##  ##  ####
//
//==============================================================

#include <iostream>
using namespace std;
class stacks
{
    int *i_array;
    int *j_array;
    int size;
    int current_size;

public:
    stacks(int size);
    ~stacks();
    bool isFull();
    void push(int i, int j);
    void pop(int &i, int &j);
    void display_stack();
};

stacks::stacks(int size)
{
    this->size = size;
    i_array = new int[size];
    j_array = new int[size];
    current_size = 0;
}

stacks::~stacks()
{
    delete[] i_array;
    delete[] j_array;
    i_array = NULL;
    j_array = NULL;
}

bool stacks::isFull()
{
    if (current_size == size)
        return true;
    return false;
}

void stacks::push(int i, int j)
{
    if (!isFull())
    {
        i_array[current_size] = i;
        j_array[current_size] = j;
        current_size++;
    }
    else
        cout << "Stack is Full!\n";
}

void stacks::pop(int &i, int &j)
{

    i = i_array[current_size - 1];
    j = j_array[current_size - 1];
    current_size--;
}

void stacks::display_stack()
{
    for (int i = 0; i < current_size; i++)
    {
        cout << i_array[i] << ',' << j_array[i] << endl;
    }
}