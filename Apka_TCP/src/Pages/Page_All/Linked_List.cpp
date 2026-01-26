#include "Linked_List.h"

LinkedList::LinkedList()
{
    First = new Node;
    First->data = 0;
    First->Next = nullptr;
    Last = First;
    count = 1;
}

void LinkedList::Add(const wchar_t *data)
{
    Node *Temp;
    std::wstring Change = data;
    Temp = new Node;
    Temp->Next = nullptr;
    Temp->data = std::stoi(Change);
    Last->Next = Temp;
    Last = Temp;
    count++;
}

const wchar_t *LinkedList::Print()
{
    Node *Temp = First;
    Return_Value = L"";
    int i = 1;
    while (Temp->Next)
    {
        Return_Value += std::to_wstring(Temp->data);
        Return_Value += ',';
        Temp = Temp->Next;
    }
    Return_Value += std::to_wstring(Temp->data);
    return Return_Value.c_str();
}
void LinkedList::SetData(const wchar_t *data)
{
    std::wstring Change = data;
    Last->data = std::stoi(Change);
}

int LinkedList::sum()
{
    Node *Temp = First;
    int sum{};
    while (Temp != nullptr)
    {
        sum += Temp->data;
        Temp = Temp->Next;
    }
    return sum;
}

const wchar_t *LinkedList::Max()
{
    Node *Temp = First;
    int Max = 0;
    Return_Value = L"";
    while (Temp)
    {
        if (Max < Temp->data)
        {
            Max = Temp->data;
        }
        Temp = Temp->Next;
    }
    Return_Value = std::to_wstring(Max);
    return Return_Value.c_str();
}

const wchar_t *LinkedList::Min()
{
    Node *Temp = First;
    int Min = INT_MAX;
    Return_Value = L"";
    while (Temp)
    {
        if (Min > Temp->data)
        {
            Min = Temp->data;
        }
        Temp = Temp->Next;
    }
    Return_Value = std::to_wstring(Min);
    return Return_Value.c_str();
}

Node* LinkedList::Search(wchar_t *key)
{
    Node *Temp = First;
    Return_Value = key;
    while (Temp)
    {
        if(std::stoi(Return_Value)==Temp->data)
        {
            return Temp;
        }
        Temp = Temp->Next;
    }
    return NULL;
}

/*Move to head traspostion - Prehadzuje najdeny element na prvu poziciu
Node* LinkedList::Search(wchar_t *key)
{
   Node *temp = first;
   Node *temp_2 = NULL;
   while (Temp)
   { 
      if (std::stoi(Return_Value)==Temp->data)
      {
         temp_2->Next = temp->Next;
         temp_Next = First;
         first = temp;
         return temp;
      }
      else
      {
         temp_2 = temp;
         temp = temp->Next;
    }
   }
    return NULL;
}*/

//vkladanie 
void LinkedList::Insert(wchar_t *Place,wchar_t *data)
{
    std::wstring Place_Temp = Place, Data_Tamp = data;
    int temp_Place_int = std::stoi(Place_Temp),tamp_Data_int = std::stoi(Data_Tamp);
    //Ak je to na zaciatku musi byt logika takato pretoze presuvame first node
    if (temp_Place_int == 0)
    {
        Node *Temp = new Node;
        Temp->data = tamp_Data_int;
        Temp->Next = First;
        First = Temp;
    }
    else
    {
        Node *Temp = First;
        Node *NewNode = new Node;
        NewNode->data = tamp_Data_int;
        for (int i{};i < temp_Place_int - 1;i++)
        {
            if (!Temp->Next){break;}
            Temp = Temp->Next;
        }
        NewNode->Next = Temp->Next;
        Temp->Next = NewNode;
        

    }
}