#include "Pages.h"

Pages::Pages()
{
    Windows_CLASS = new wchar_t *[6] { {L"BUTTON"},
                                       {L"EDIT"},
                                       {L"STATIC"},
                                       {L"LISTBOX"},
                                       {L"COMBOBOX"},
                                       {L"SCROLLBAR"}};
}

Pages::~Pages()
{
    delete[] Windows;
    delete[] Windows_Names;
    delete[] Windows_PositionsX;
    delete[] Windows_PositionsY;
    delete[] Page_Name;
    delete[] Windows_CLASS;
}
