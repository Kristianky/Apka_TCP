#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_
#include <string>
struct Node
{
    int data;
    Node *Next;
}*First;



class LinkedList
{
   private:
       Node *Last;
       int count;
   public:
       LinkedList ();
       ~LinkedList() = default;
       void SetData(wchar_t *Data);
       void Add(wchar_t *data);
       std::wstring Print();

      
};

#endif