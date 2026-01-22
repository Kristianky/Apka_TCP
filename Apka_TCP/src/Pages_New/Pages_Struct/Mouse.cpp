#include "Mouse.h"

// získanie X a Y z LPARAM
void Mouse::UpdatePosition(LPARAM lp) {
    X = static_cast<short>(lp & 0xFFFF);   //Manulany zapis pre HIWORD a LOWORD je to maska ktora vytahuje podla F na 2 bitov
    Y = static_cast<short>((lp >> 16) & 0xFFFF);  //tu je to iste len musime sa o 16 bitov posunut do prava aby s,e vytiahli spodne bity cize Y
}

bool Mouse::Inside(RECT &rect)
{
    return X > rect.left && X < rect.right && Y > rect.bottom && Y < rect.top;
}