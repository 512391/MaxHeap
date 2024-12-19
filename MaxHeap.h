#include<iostream>

/*
Author: Jay Williamson
Date: 12/19/24
This class contains the information about the heap
*/

namespace Heaps
{
  class Heap
    {
      private:
      //The pointer to the heap array
      int *heap;
      //the current size of the heap
      int size;
      //the next index to add to
      int bottomIndex;
      //gets the parent of a specified node
      int getParent(int index);
      //gets the largest child of a specified node
      int getGreatestChild(int index);
      //this is a recursive function to move from the bottom to the top of the tree based on size
      void checkParentToSwap(int index);
      //this is a recursive function to move from the top to the bottom of the tree based on size
      void checkChildToSwap(int index);
      //This is a recursive function the prints out the tree horizontally
      void printNode(int index, int depth);
      
      public:
      //this is the constructor that takes a max size
      Heap(int size);
      //this is the function that adds something to the heap
      void add(int i);
      //this get the root and removes it and reorganizes the tree
      int getRoot();
      //this displays the tree
      void display();
  };
}
