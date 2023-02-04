//===========================================================
//                                                           
//              #####    #####     ###    #####    ####    
//              ##  ##  ##   ##   ## ##   ##  ##   ##  ##  
//              #####   ##   ##  ##   ##  #####    ##  ##  
//              ##  ##  ##   ##  #######  ##  ##   ##  ##  
//              #####    #####   ##   ##  ##   ##  ####    
//                                                           
//===========================================================

#include <iostream>
#include <ctime>
using namespace std;
class board
{
public:
    int **array;
    int rows;
    int columns;

public:
    board();
    ~board();
    board(int r, int c);
    void load_data();
    void set( int destination);
    void display_board();
};

board::board()
{
    array = NULL;
    rows = 0;
    columns = 0;
}

board::~board()
{
    if (array != NULL)
    {
        for (int i = 0; i < rows; i++)
            delete[] array[i];
        delete[] array;
        rows = 0;
        columns = 0;
    }
}

board::board(int r, int c)
{
    rows = r;
    columns = c;
    array = new int *[rows];
    for (int i = 0; i < rows; i++)
    {
        array[i] = new int[columns];
        for (int j = 0; j < columns; j++)
        {
            array[i][j] = 1;
        }
    }
}

void board::load_data()
{
    srand(time(NULL));
    int total_hurdles = rows * columns / 4;
    while (total_hurdles != 0)
    {
        int random_rows = 0 + rand() % rows;
        int random_columns = 0 + rand() % columns;
        if (array[random_rows][random_columns] == -1)
            ;
        else
        {
            array[random_rows][random_columns] = -1;
            total_hurdles--;
        }
    }
}

void board::set( int destination)
{
    if (destination == 1)
        array[0][0] = 3;
    else if (destination == 3)
        array[rows - 1][0] = 3;
    else if (destination == 2)
        array[0][columns - 1] = 3;
    else if (destination == 4)
        array[rows - 1][columns - 1] = 3;
}

void board::display_board()
{
    for (int i = 0; i < this->rows; i++)
    {
        for (int j = 0; j < this->rows; j++)
        {
            cout << this->array[i][j] << "  ";
        }
        cout << endl;
    }
}