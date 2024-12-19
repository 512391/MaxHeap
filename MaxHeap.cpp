#include<iostream>
#include<cmath>
#include"MaxHeap.h"

using namespace std;
using namespace Heaps;

//makes the heap
Heap::Heap(int size)
{
  Heap::size = size;
  Heap::heap = new int[Heap::size];
  Heap::bottomIndex = 1;
  //clears the heap by inputting negative 1s
  for(int i = 0; i < Heap::size; i++)
    {
      Heap::heap[i] = -1;
    }
}

//adds something to the heap
void Heap::add(int i)
{
  //adds it to the bottom
  Heap::heap[Heap::bottomIndex] = i;

  if(Heap::bottomIndex == 1)
    {
      Heap::bottomIndex++;
      
      return;
    }
  else
    {
      //tries moving up the heap until it cannot
      Heap::checkParentToSwap(Heap::bottomIndex);
    }

  Heap::bottomIndex++;
}

//gets the parent at a certain index
int Heap::getParent(int index)
{
  //makes sure it has a parent
  if(index == 1)
    {
      return -1;
    }

  return ceil(double (index-1)/2);
}

//gets the greatest child of a node
int Heap::getGreatestChild(int index)
{
  //gets both children
  int childOneIndex = (2*index);
  int childTwoIndex = (2*index)+1;

  //goes through checks to find greatest
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

//checks if it can swap with parent and swaps if can
void Heap::checkParentToSwap(int index)
{
  int parent = Heap::getParent(index);
 
  if(parent == -1)
    {
      return;
    }

  //checks parent size and if bigger
  if(Heap::heap[parent] < Heap::heap[index])
    {
      //switches the parent and child
      int temp = Heap::heap[index];
      Heap::heap[index] = Heap::heap[parent];
      Heap::heap[parent] = temp;

      //calls again
      Heap::checkParentToSwap(parent);
    }
}

//checks the children to swap
void Heap::checkChildToSwap(int index)
{
  //finds the biggest child
  int child = Heap::getGreatestChild(index);
  
  if(Heap::heap[child] == -1)
    {
      return;
    }

  //checks if the child is bigger
  if(Heap::heap[child] > Heap::heap[index])
    {
      //swap parent and child
      int temp = Heap::heap[index];
      Heap::heap[index] = Heap::heap[child];
      Heap::heap[child] = temp;

      //call again
      Heap::checkChildToSwap(child);
    }
}

//gets the root and removes it
int Heap::getRoot()
{
  if(Heap::heap[1] == -1)
    {
      return -1;
    }

  //gets the output to return
  int output = Heap::heap[1];

  //removes the top
  Heap::heap[1] = Heap::heap[Heap::bottomIndex-1];
  Heap::heap[Heap::bottomIndex-1] = -1;

  //moves the top down
  checkChildToSwap(1);

  Heap::bottomIndex--;
  
  return output;
}

//displays the node
void Heap::display()
{
  //checks if there is nothing to display
  if(Heap::heap[1] == -1)
    {
      return;
    }

  //starts printing the nodes
  printNode(1, 0);
}

//recursivly prints the nodes
void Heap::printNode(int index, int depth)
{
  //checks if it has a child
  if(index*2+1 < Heap::bottomIndex)
    {
      //if it does print node there
      printNode(index*2+1, depth+1);
    }

  //prints it far in to make sure it looks like a tree
  for(int i = 0; i < depth; i++)
    {
      cout << '\t';
    }

  //checks if it is at the end
  if(heap[index] == -1)
    {
      cout << "__" << endl;
    }
  else
    {
      //if it is not at the end print the node
      cout << heap[index] << endl;
    }

  //checks the other child
  if(index*2 < Heap::bottomIndex)
    {
      //print more if there is another child on the other side
      printNode(index*2, depth+1);
    }
}
