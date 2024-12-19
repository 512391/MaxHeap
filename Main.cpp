#include<iostream>
#include<cmath>
#include<fstream>
#include"MaxHeap.h"

using namespace std;
using namespace Heaps;

int main() 
{
    int number = 0;
    Heap* heap = new Heap(1000);

    cout << "1 for input file 2 for input nums \n";
    int choice;
    cin >> choice;

    if (choice == 2)
    {
      bool firstThrough = true;
      
        while (number != -1) 
        {
	  if(!firstThrough)
	    {
                if (number != -2 && number != -3) 
                {
                    heap->add(number);
                    heap->display();
                } 
                else if(number == -2)
                {
                    cout << heap->getRoot() << endl;
                }
		else if(number == -3)
		{
		  heap->display();
		}
	    }
	  firstThrough = false;
            cout << "What do you want to add or press -3 or press -2 to get root or press -1 to exit\n";
            cin >> number;
        }

	return 0;
    }
    else 
    {
        char* input = new char[20];

        cout << "What file name \n";

	cin.ignore();
        cin.getline(input, 20);

        ifstream inputFile(input);

        int* nums = new int[1000];
        int currentIndex = 0;
        int currentNumberIndex = 0;
        int currentNumber[4];
        int finalNumber = 0;
        int amountOfPlaces = 0;
        char currentChar;

        while (inputFile.get(currentChar)) 
        {
            if (currentChar == ' ') 
            {
                for (int i = 0; i < amountOfPlaces; i++) 
                {
                    finalNumber += currentNumber[i] * pow(10, amountOfPlaces - 1 - i);
                    currentNumber[i] = -1;
                }
                amountOfPlaces = 0;
                nums[currentIndex] = finalNumber;
                finalNumber = 0;
                currentIndex++;
                currentNumberIndex = 0;
            } 
            else if (currentChar != '\n') 
            {
                currentNumber[currentNumberIndex] = (int)currentChar - 48;
                amountOfPlaces++;
                currentNumberIndex++;
            }
        }

        for (int i = 0; i < currentIndex; i++) 
        {
            heap->add(nums[i]);
        }
        heap->display();

        while (number != -1)
        {
            if (number == -3)
            {
                heap->display();
            }
            else if(number == -2)
            {

	      cout << "got root" << endl;
                cout << heap->getRoot() << endl;
            }

            cout << "Press -3 to see the tree or -2 to get the root or -1 to exit\n";
            cin >> number;
        }
    }

    return 0;
}

