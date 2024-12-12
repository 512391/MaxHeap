#include<iostream>
#include<cmath>
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

  return ceil(double (index-1)/2);
}

int Heap::getGreatestChild(int index)
{
  int childOneIndex = (2*index);
  int childTwoIndex = (2*index)+1;
  
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
  
  if(Heap::heap[child] == -1)
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
  if(Heap::heap[1] == -1)
    {
      return -1;
    }
  
  int output = Heap::heap[1];

  Heap::heap[1] = Heap::heap[Heap::bottomIndex-1];
  Heap::heap[Heap::bottomIndex-1] = -1;

  checkChildToSwap(1);

  Heap::bottomIndex--;
  
  return output;
}

void Heap::display()
{
  if(Heap::heap[1] == -1)
    {
      return;
    }
  
  printNode(1, 0);
}

void Heap::printNode(int index, int depth)
{
  if(index*2+1 < Heap::bottomIndex)
    {
      printNode(index*2+1, depth+1);
    }

  for(int i = 0; i < depth; i++)
    {
      cout << '\t';
    }

  if(heap[index] == -1)
    {
      cout << "__" << endl;
    }
  else
    {
      cout << heap[index] << endl;
    }

  if(index*2 < Heap::bottomIndex)
    {
      printNode(index*2, depth+1);
    }
}
