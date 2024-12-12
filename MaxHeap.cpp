#include<iostream>
#include"MaxHeap.h"

using namespace std;
using namespace Heaps;

Heap::Heap(int size)
{
  Heap::size = size;
  Heap::heap = new int[Heap::size];
  Heap::bottomIndex = 1;
  
  for(int i = 0; i < Heap::size; i++)
    {
      Heap::heap[i] = -1;
    }
}

void Heap::add(int i)
{
  Heap::heap[Heap::bottomIndex] = i;

  if(Heap::bottomIndex == 1)
    {
      Heap::bottomIndex++;
      
      return;
    }
  else
    {
      Heap::checkParentToSwap(Heap::bottomIndex);
    }

  Heap::bottomIndex++;
}

int Heap::getParent(int index)
{
  if(index == 1)
    {
      return -1;
    }

  return (index-1)/2;
}

int Heap::getGreatestChild(int index)
{
  int childOneIndex = (2*index)+1;
  int childTwoIndex = (2*index)+2;
  
  if(Heap::heap[childOneIndex] == -1 && Heap::heap[childTwoIndex] != -1)
    {
      return childTwoIndex;
    }
  if(Heap::heap[childOneIndex] != -1 && Heap::heap[childTwoIndex] == -1)
    {
      return childOneIndex;
    }
if(Heap::heap[childOneIndex] == -1 && Heap::heap[childTwoIndex] == -1)
    {
      return -1;
    }
 if(Heap::heap[childOneIndex] > Heap::heap[childTwoIndex])
    {
      return childOneIndex;
    }

 return childTwoIndex;
}

void Heap::checkParentToSwap(int index)
{
  int parent = Heap::getParent(index);

  if(parent == -1)
    {
      return;
    }
  
  if(Heap::heap[parent] < Heap::heap[index])
    {
      int temp = Heap::heap[index];
      Heap::heap[index] = Heap::heap[parent];
      Heap::heap[parent] = temp;
      
      Heap::checkParentToSwap(parent);
    }
}

void Heap::checkChildToSwap(int index)
{
  int child = Heap::getGreatestChild(index);

  if(child == -1)
    {
      return;
    }

  if(Heap::heap[child] > Heap::heap[index])
    {
      int temp = Heap::heap[index];
      Heap::heap[index] = Heap::heap[child];
      Heap::heap[child] = temp;

      Heap::checkChildToSwap(child);
    }
}

int Heap::getRoot()
{
  int output = Heap::heap[1];

  Heap::heap[1] = Heap::heap[bottomIndex-1];
  Heap::heap[bottomIndex-1] = -1;

  checkChildToSwap(1);
  
  return output;
}

void Heap::display()
{
  if(Heap::heap[1] == -1)
    {
      return;
    }

  for(int i = 1; i < Heap::bottomIndex; i++)
   {
     cout << Heap::heap[i] << ", ";
   }
  
  cout << endl;
  
  int amount = Heap::bottomIndex;
  int currentIndex = 1;
  int rowAmount = 1;
  
  bool atEnd = false;

  while(!atEnd)
    {
      for(int i = 0; i < rowAmount; i++)
	{
	  if(Heap::heap[currentIndex] == -1)
	    {
	      atEnd = true;
	    }
	  else
	    {
	      cout << Heap::heap[currentIndex];
	    }
	  
	  cout << " ";
	  currentIndex++;
	}
      cout << endl;
      rowAmount *= 2;
    }
}
