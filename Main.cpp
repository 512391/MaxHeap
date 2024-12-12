#include<iostream>
#include"MaxHeap.h"

using namespace std;
using namespace Heaps;

int main()
{
  ifstream firstNamesFile("Input.txt");

  int *nums = new int[1000];

  char 
  
  while()
    {
      
    }
  
  int number = 0;

  Heap* heap = new Heap(1000);
  
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
  
  return 0;
}
