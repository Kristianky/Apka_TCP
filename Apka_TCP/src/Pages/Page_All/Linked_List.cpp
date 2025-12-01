#include "Linked_List.h"

LinkedList::LinkedList()
{
    First = new Node;
    First->data = 0;
    First->Next = nullptr;
    Last = First;
}

void LinkedList::Add(wchar_t *data)
{
    Node *Temp;
    std::wstring Change = data;
    Temp = new Node;
    Temp->Next = nullptr;
    Temp->data = std::stoi(Change);
    Last->Next = Temp;
    Last = Temp;
}

std::wstring LinkedList::Print()
{
    Node *Temp = First;
    std::wstring Cout;
    while (Temp->Next != nullptr)
    {
        Cout += std::to_wstring(Temp->data);
        Cout += ',';
        Temp = Temp->Next;
    }
    return Cout;
}
void LinkedList::SetData(wchar_t *data)
{
    std::wstring Change = data;
    Last->data = std::stoi(Change);
}