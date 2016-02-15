/*
***PROGRAM CAN SOMETIMES TAKE UP TO 10 MINUTES TO RANDOMLY GENERATE A MAGIC SQUARE!***
Programmer: Allen Owen
Date: 11/2015
Description: This program continuously generates a 3x3 square of random numbers from 1-9, until the sum of each row, column,
and diagonal are all equal. ***PROGRAM CAN SOMETIMES TAKE UP TO 10 MINUTES TO RANDOMLY GENERATE A MAGIC SQUARE!***
Algorithm: Declare 3x3 array, while no magic square loop 3x3 square generator and display, assign 3x3 array random numbers 1-9,
display 3x3 array, check if magicSquare, if not magic square continue while square generator loop.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

bool checkUnique(int[][3], int);//function to check if random number is unique number
bool magicSquare(int[][3]);//function to check if 2d array is a magic square
int numGen();

int main()
{
    srand(time(NULL));
    int square[3][3] = {{0,0,0},{0,0,0},{0,0,0}};
    int num;
    bool isUnique = 0;
    bool isMagic = 0;
    do
    {
        for(int i = 0; i < 3;i++)
        {
            for (int n = 0; n < 3; n++)
            {
                square[i][n] = 0;
            }
        }

        for (int i = 0; i < 3; i++)
        {
            for (int n = 0; n < 3; n++)
            {
                do
                {
                    num = numGen();
                    isUnique = checkUnique(square, num);
                }while (isUnique != 1);
                square[i][n] = num;
                isUnique = 0;
            }
        }

        for (int b = 0; b < 3; b++)
        {
            for (int c = 0; c < 3; c++)
            {
                cout << square[b][c] << ", ";
            }
            cout << endl;
        }

        isMagic = magicSquare(square);
        if (isMagic == 0)
        {
            cout << "Not a Magic Square!" << endl;
        }
        if (isMagic == 1)
        {
            cout << "Magic Square!" << endl;
        }
    }while(isMagic != 1);
    return 0;
}

int numGen()//generates random numbers 1-9
{
    int num = rand() % 9 + 1;
    return num;
}

bool checkUnique(int square[][3], int num)//checks if random number generated is already assigned in 3x3 square
{
    for (int i=0;i<3;i++)
    {
        for(int n=0;n<3;n++)
        {
            if (num == square[i][n])
            {
                return 0;
            }
        }
    }
    return 1;
}

bool magicSquare(int square[][3])//checks if sum of each row, column, and diagonal are equal
{
    int sum1=0,sum2=0,sum3=0,col1=0,col2=0,col3=0,diag1=0,diag2=0;

    for (int i=0;i<3;i++)
    {
        sum1 += square[0][i];
    }
    for (int i=0;i<3;i++)
    {
        sum2 += square[1][i];
    }
    for (int i=0;i<3;i++)
    {
        sum3 += square[2][i];
    }
    for (int i=0;i<3;i++)
    {
        col1 += square[i][0];
    }
    for (int i=0;i<3;i++)
    {
        col2 += square[i][1];
    }
    for (int i=0;i<3;i++)
    {
        col3 += square[i][2];
    }
    diag1 = (square[0][0] + square[1][1] + square[2][2]);
    diag2 = (square[0][2] + square[1][1] + square[2][0]);

    if (sum1 == sum2 && sum2 == sum3 && sum3 == col1 && col1 == col2 && col3 == diag1 && diag1 == diag2)
    {
        return 1;
    }
    else
    return 0;
}
