#include<iostream>
#include<cmath>
#include<fstream>
#include"MaxHeap.h"
/*
Author Jay Williamson
date 12/19/2024
this class creates a heap and allows you to add display and take from it
it also allows u to give it a file to add to the heap
	*/
using namespace std;
using namespace Heaps;

int main() 
{
//this is the input number
    int number = 0;
//this creates a new heap which is used as the main data structure
    Heap* heap = new Heap(1000);
//this gets input for whether to ask for a file or just numbers
    cout << "1 for input file 2 for input nums \n";
    int choice;
    cin >> choice;

    if (choice == 2)
    {
      bool firstThrough = true;
      //goes through getting numbers and doing special input
        while (number != -1) 
        {
	  if(!firstThrough)
	    {
		//if it is not a number which requires special action it just adds it to the heap
                if (number != -2 && number != -3) 
                {
                    heap->add(number);
                    heap->display();
                } //if you input negative 2 it gets the root and displays it
                else if(number == -2)
                {
                    cout << heap->getRoot() << endl;
                }//if you input negative 3 it just displays the heap
		else if(number == -3)
		{
		  heap->display();
		}
	    }
	//this keeps it from running it with the random character on top of the new heap
	  firstThrough = false;
            cout << "What do you want to add or to see the tree press -3 or press -2 to get root or press -1 to exit\n";
            cin >> number;
        }

	return 0;
    }
    else 
    {
        char* input = new char[20];

        cout << "What file name \n";

	//gets a file name
	cin.ignore();
        cin.getline(input, 20);

	//gets the file you asked for
        ifstream inputFile(input);

	//this is a holder for the numbers being taken out of the file to be added after
        int* nums = new int[1000];
	//gets the current index nums
        int currentIndex = 0;
	//gets the current index in the current number array
        int currentNumberIndex = 0;
	//the numbers in the current number it is reading
        int currentNumber[4];
	//this is a holder for the final number read out
        int finalNumber = 0;
	//this is the amount of places in the number
        int amountOfPlaces = 0;
	//place holder for the char being read
        char currentChar;

        while (inputFile.get(currentChar)) 
        {
	//checks if it should start calculating the number it just read
            if (currentChar == ' ') 
            {
		//this starts adding up the current number
                for (int i = 0; i < amountOfPlaces; i++) 
                {
		//adds it by multiplying it by the place it is in and the number
                    finalNumber += currentNumber[i] * pow(10, amountOfPlaces - 1 - i);
		//resets the number
                    currentNumber[i] = -1;
                }

		//resets all the variables
                amountOfPlaces = 0;
                nums[currentIndex] = finalNumber;
                finalNumber = 0;
                currentIndex++;
                currentNumberIndex = 0;
            } //skips end line characters in case there is one
            else if (currentChar != '\n') 
            {
		//adds the current number to the array and goes to the next
                currentNumber[currentNumberIndex] = (int)currentChar - 48;
                amountOfPlaces++;
                currentNumberIndex++;
            }
        }

	//adds all the numbers to the heap
        for (int i = 0; i < currentIndex; i++) 
        {
            heap->add(nums[i]);
        }
        heap->display();

	//gets input to do stuff to the heap
        while (number != -1)
        {
	    //displays
            if (number == -3)
            {
                heap->display();
            }//gets the root and displays it as well as removing it
            else if(number == -2)
            {
                cout << heap->getRoot() << endl;
            }

	//gets the next input
            cout << "Press -3 to see the tree or -2 to get the root or -1 to exit\n";
            cin >> number;
        }
    }

    return 0;
}

