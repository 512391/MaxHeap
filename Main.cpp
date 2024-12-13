#include<iostream>
#include<cmath>
#include"MaxHeap.h"

using namespace std;
using namespace Heaps;

int main()
{
  ifstream inputFile("Input.txt");

  int *nums = new int[1000];
	
int currentIndex = 0;
	int currentNumberIndex = 0;
  int currentNumber[4];
	int finalNumber = 0;
	int amountOfPlaces = 0;
  char currentChar;
  while(inputFile.get(currentChar))
    {
      if(currentChar == ´,´)
      {      
	for(int i = 0; i < amountOfPlaces; i++)
		{
			finalNumber += currentNumber[i] * pow(10, amountOfPlaces);
			currentNumber[i] = -1;
		}
	      amountOfPlaces = 0;
	      nums[currentIndex] = finalNumber;
	      finalNUmber = 0;
	      currentIndex++;
	      currentNumberIndex = 0;
      }
	else if(currentChar != ´\n´)
      {
	currentNumber[currentNumberIndex] = (int)currentChar-30;
      }
    }
  
  int number = 0;

  Heap* heap = new Heap(1000);

	cout << ¨1 for input file 2 for input nums \n¨; 
	int choice; 
  cin >> choice;
	if(choice == 2)
	{
  while(number != -1)
    {
      if(number != 0)
	{
	  heap->add(number);
	  heap->display();
	}
      else
	{
      	  cout << heap->getRoot() << endl;
	}
      
      cout<< "what do you want to add \n";
      cin >> number;
    }
	}
	else
	{
		for(int i = 0; i < currentIndex; i++)
			{
				heap->add(nums[i]);
			}
		heap->display();
	}
  return 0;
}
