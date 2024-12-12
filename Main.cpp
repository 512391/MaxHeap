#include<iostream>
#include"MaxHeap.h"

using namespace std;
using namespace Heaps;

int main()
{
  int number = 0;

  Heap* heap = new Heap(100);
  
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
