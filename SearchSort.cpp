/*
Programmer: Allen Owen
Date: 12/2015
Description: This program allows the user to choose between 4 different search and sorting methods. This user can also view the
execution time taken of each search/sort method.
Algorithm: display menu, if linear search obtain user input and call linearSearch function, if binary search obtain user input
and call binarySearch function, if bubbleSort call bubbleSort function and display unsorted and sorted arrays, if selectionSort
call selectionSort function and display unsorted and sorted arrays. display function execution times.
*/
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
using namespace std;

void display(int[],string[],double[]);//display parallel arrays
int linearSearch(int[],int,int);//function to linearly search through an array for a value
int binarySearch(int[],int,int);//function to search through a array for a value by starting in the middle
void bubbleSort(int[],int);//function to bubble sort an array
void selectionSort(int[],int);//function to selection sort an array
int randNum();//function to generate random numbers
void swapIntegers(int&, int&);//function to swap integers

int main()
{
    string bookTitle[] = {"Starting out with C++", "Java Programming","Software Structures", "Design and Analysis of Algorithms", "Computer Graphics", "Artificial Intelligence: A Modern Approach", "Probability and Statistics", "Cognitive Science", "Modern Information Retrieval","Speech and Language Processing"};
    int bookID[] = {1101, 1211, 1333, 1456, 1567, 1642, 1699, 1755, 1800,1999};
    double bookPrice[] = {112.32, 73.25, 54.00, 67.32, 135.00, 173.22,120.00, 42.25, 32.11, 123.75};
    bool quit = 0;
    int choice , value, num, index;
    int nums[1000];
    srand(time(NULL));
    clock_t t;

    while (quit == 0)//loop main menu
    {
        cout << "******** SEARCHING AND SORTING MENU ********" << endl;
        cout << "1. Linear Search" << endl;
        cout << "2. Binary Search" << endl;
        cout << "3. Bubble Sort" << endl;
        cout << "4. Selection Sort" << endl;
        cout << "5. Quit " << endl << endl;
        cout << "Please enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            cout << "******** LINEAR SEARCH ********" << endl << endl;
            display(bookID,bookTitle,bookPrice);
            cout << endl << "Please enter the book ID you wish to purchase: ";
            cin >> value;
            cout << "How many copies you wish to purchase: ";
            cin >> num;
            t = clock();
            index = linearSearch(bookID, 10, value);
            t = clock() - t;
            cout << "Function execution time: " << ((double)t)/CLOCKS_PER_SEC << " seconds" << endl;
            if (index == -1)
            {
                cout << "Book ID not found!!!" << endl;
                break;
            }
            cout << "Book ID: " << value << ", Book Title: " << bookTitle[index] << " , Number of books bought: " << num << " , Total Cost: " << num * bookPrice[index] << endl;
        }
        break;
        case 2:
        {
            cout << "******** BINARY SEARCH ********" << endl << endl;
            display(bookID,bookTitle,bookPrice);
            cout << endl << "Please enter the book ID you wish to purchase: ";
            cin >> value;
            cout << "How many copies you wish to purchase: ";
            cin >> num;
            t = clock();
            index = binarySearch(bookID, 10, value);
            t = clock() - t;
            cout << "Function execution time: " << ((double)t)/CLOCKS_PER_SEC << " seconds" << endl;
            if (index == -1)
            {
                cout << "Book ID not found!!!" << endl;
                break;
            }
            cout << "Book ID: " << value << ", Book Title: " << bookTitle[index] << " , Number of books bought: " << num << " , Total Cost: " << num * bookPrice[index] << endl;
        }
        break;
        case 3:
        {
            for (int i = 0; i < 1000; i++)
            {
                nums[i] = randNum();
            }
            cout << "******** BUBBLE SORT ********" << endl << endl;
            cout << "Unsorted Array:" << endl;
            for (int i=0; i < 1000; i++)
            {
                cout << nums[i] << ", ";
            }
            cout << endl << endl;
            t = clock();
            bubbleSort(nums,1000);
            t = clock() - t;
            cout << "Sorted Array:" << endl;
            for (int i=0; i < 1000; i++)
            {
                cout << nums[i] << ", ";
            }
            cout << endl << endl;
            cout << "Function Execution time: " << ((double)t)/CLOCKS_PER_SEC << " seconds" << endl;
        }
        break;
        case 4:
        {
            for (int i = 0; i < 1000; i++)
            {
                nums[i] = randNum();
            }
            cout << "******** SELECTION SORT ********" << endl << endl;
            cout << "Unsorted Array:" << endl;
            for (int i=0; i < 1000; i++)
            {
                cout << nums[i] << ", ";
            }
            cout << endl << endl;
            t = clock();
            selectionSort(nums,1000);
            t = clock() - t;
            cout << "Sorted Array:" << endl;
            for (int i=0; i < 1000; i++)
            {
                cout << nums[i] << ", ";
            }
            cout << endl << endl;
            cout << "Function Execution time: " << ((double)t)/CLOCKS_PER_SEC << " seconds" << endl;
        }
        break;
        case 5:
            return 0;
            break;
        }

    }

    return 0;
}

void display(int id[], string title[], double price[])//display parallel arrays
{
    cout << "Book ID   Cost    Title" << endl;
    for (int i=0; i<10; i++)
    {
        cout << id[i] << "      " << price[i] << "     " << title[i] << endl;
    }
}

int linearSearch(int bookID[], int size, int value)//function to linearly search through an array for a value
{
    int position = -1;
    int i = 0;
    bool flag = 0;
    while (i < size && !flag)
    {
        if (bookID[i] == value)
        {
            flag = 1;
            position = i;
        }
        i++;
    }
    return position;
}

int binarySearch(int bookID[], int size, int value)//function to search through a array for a value by starting in the middle
{
    int first = 0;
    int last = size - 1;
    int middle;
    int position = -1;
    bool flag = 0;

    while (!flag && first <= last)
    {
        middle = (first + last) /2;
        if (bookID[middle] == value)
        {
            flag = 1;
            position = middle;
        }
        else if (bookID[middle] > value)
        {
            last = middle - 1;
        }
        else
        {
            first = middle + 1;
        }

    }

    return position;
}

int randNum()//function to generate random numbers between 1-500
{
    int num;
    num = rand() % 500 +1;
    return num;
}

void swapIntegers(int &a, int &b)//function to swap integers
{
    int temp = a;
    a = b;
    b = temp;
}
void bubbleSort(int num[], int numSize)//****** FUNCTION CODE FROM CLASS MOODLE PAGE *******
{
      bool flag = true;    // set flag to true to start first pass
      for(int i = 0; (i < numSize) && flag; i++)
     {
          flag = false;
          for (int j=0; j < (numSize -1); j++)
         {
               if (num[j+1] < num[j])
              {
                    swapIntegers(num[j], num[j+1]);             // swap elements
                    flag = true;               // indicates that a swap occurred.
               }
          }
     }
    //arrays are passed to functions by address; nothing is returned
}

void selectionSort(int values[], int size)//****** FUNCTION CODE FROM CLASS MOODLE PAGE *******
{
	int startScan;
	int minIndex;
	int minValue;

	for (startScan = 0; startScan < (size - 1); startScan++)
	{
		minIndex = startScan;
		minValue = values[minIndex];

		for(int index = startScan + 1; index < size; index++)
		{
			if (values[index] < minValue)
			{
				minValue = values[index];
				minIndex = index;
			}
		}

		values[minIndex] = values[startScan];
		values[startScan] = minValue;
	}
}
