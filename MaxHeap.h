#include<iostream>

namespace Heaps
{
  class Heap
    {
      private:
      int *heap;
      int size;
      int bottomIndex;
      int getParent(int index);
      int getGreatestChild(int index);
      void checkParentToSwap(int index);
      void checkChildToSwap(int index);
      public:
      Heap(int size);
      void add(int i);
      int getRoot();
      void display();
  };
}
