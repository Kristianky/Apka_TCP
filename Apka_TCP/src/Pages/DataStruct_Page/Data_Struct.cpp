#include "Data_Struct.h"
const wchar_t *Data_Struct_Page::Windows_Names[5] = {
    L"Paint",
    L"Reset Table",
    L"Set Length",
    L"Add Data",
    L"Add Sparse Matrix"};

const wchar_t *Data_Struct_Page::Windows_CLASS[2] = {
    L"BUTTON",
    L"EDIT"};
Data_Struct_Page::Data_Struct_Page(HWND hwnd) : Pages(hwnd)

{
     Number_Of_Buttons = 5;
     Number_Of_Edit = 9;
     Buttons_PositionsX = new int[5]{0, 200, 600, 400, 800};
     Buttons_PositionsY = new int[5]{Main_Rect.top,
                                     Main_Rect.top,
                                     Main_Rect.top,
                                     Main_Rect.top,
                                     Main_Rect.top};
     Edit_Postion_X = new int[9]{Main_Rect.left,
                                 Main_Rect.left,
                                 Main_Rect.left,
                                 Main_Rect.left,
                                 Main_Rect.left,
                                 Main_Rect.left,
                                 Main_Rect.right - 203,
                                 Main_Rect.right - 203,
                                 Main_Rect.right - 203};
     Edit_Postion_Y = new int[9]{200, 215, 230, 245, 260, 275, 200, 245, 290};
     EditSize.Size_X = {200, 200, 200, 200, 200, 200, 200, 200, 200};
     EditSize.Size_Y = {15, 15, 15, 15, 15, 15, 20, 20, 20};
     Size_Of_Buffers = new int[8];
     Buffer_Edit = new wchar_t *[6];
     for (int i{}; i < 6; i++)
     {
          Buffer_Edit[i] = new wchar_t[1];
          Buffer_Edit[i] = nullptr;
     }
     Indexes = new int[5]{0};
     Buffer_Message_Box = new std::wstring[1];
     Bools = new bool[5];
     for (int i{}; i < 5; i++)
     {
          Bools[i] = false;
     }
}

Data_Struct_Page::~Data_Struct_Page()
{
}

void Data_Struct_Page::Create_ButtonsW(HWND *Buttons)
{

     for (int i{}; i < Number_Of_Buttons; i++)
     {

          Buttons[i] = CreateWindowW(Windows_CLASS[0], Windows_Names[i], WS_CHILD | WS_VISIBLE, Buttons_PositionsX[i], Buttons_PositionsY[i], 200, 100, Main_hwnd, (HMENU)(ID_BUTTONS + i), NULL, NULL);
     }
}

void Data_Struct_Page::Create_EditW(HWND *Edit_Boxes)
{

     for (int i{}; i < Number_Of_Edit; i++)
     {

          Edit_Boxes[i] = CreateWindowW(Windows_CLASS[1], L"", WS_CHILD | WS_VISIBLE | WS_BORDER, Edit_Postion_X[i], Edit_Postion_Y[i], EditSize.Size_X.at(i), EditSize.Size_Y.at(i), Main_hwnd, (HMENU)(ID_EDIT + i), NULL, NULL);
     }
}

void Data_Struct_Page::Cout_Button_1(HDC hdc)
{

     std::wstring Size_Temp = Buffer_Edit[0];
     Size_Of_Buffers[6] = std::stoi(Size_Temp);
     Size_Temp = Buffer_Edit[1];
     Size_Of_Buffers[7] = std::stoi(Size_Temp);
     SetTextColor(hdc, RGB(255, 255, 255)); // biely text
     SetBkMode(hdc, TRANSPARENT);
     HFONT hFont = CreateFontW(30, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE,
                               DEFAULT_CHARSET, OUT_OUTLINE_PRECIS, CLIP_DEFAULT_PRECIS,
                               CLEARTYPE_QUALITY, VARIABLE_PITCH, L"Segoe UI");

     HFONT hOldFont = (HFONT)SelectObject(hdc, hFont);
     RECT rect;
     rect.left = 350;
     rect.top = 230;
     rect.right = 600;
     rect.bottom = 300;
     int Position_Y{300};
     std::wstring Right_Temp = Buffer_Edit[1];
     std::wstring Bottom_Temp = Buffer_Edit[0];
     int size_right = (std::stoi(Right_Temp) + 1) * 30 + 720;
     int size_Bttom = (std::stoi(Bottom_Temp) + 1) * 30 + 320;
     HPEN hpen = CreatePen(PS_SOLID, 3, RGB(0, 17, 255));
     HPEN holdpen = (HPEN)SelectObject(hdc, hpen);
     HBRUSH hOldBrush = (HBRUSH)SelectObject(hdc, GetStockObject(NULL_BRUSH));
     Rectangle(hdc, 690, 290, size_right, size_Bttom);

     for (int x{-1}; x < Size_Of_Buffers[6]; x++)
     {
          Sparse_matrix.Print(Buffer_Data, x);
          TextOutW(hdc, 700, Position_Y, Buffer_Data.c_str(), Buffer_Data.length());
          if (wcscmp(Buffer_Data.c_str(), L"Data is not full") == 0)
               break;
          Position_Y += 30;
     }

     SelectObject(hdc, hOldFont);
     SelectObject(hdc, hOldBrush);
     SelectObject(hdc, holdpen);
     DeleteObject(hFont);
}
void Data_Struct_Page::Cout_Button_2(HDC hdc)
{

     std::wstring Data_Text, Size_Temp;
     int Size_Int_Temp;
     if (Buffer_Edit[2] != nullptr)
     {
          Size_Temp = Buffer_Edit[2];
          Size_Int_Temp = std::stoi(Size_Temp);
     }
     Data_Text = L"Number of data to set: ";
     if (Indexes[0] < 0)
     {
          Data_Text += std::to_wstring(Size_Int_Temp - Indexes[0]);
     }
     SetTextColor(hdc, RGB(255, 255, 255)); // biely text
     SetBkMode(hdc, TRANSPARENT);
     if (Buffer_Edit[0] != nullptr)
     {
          if (wcscmp(Buffer_Edit[0], L"0") <= 0)
          {
               TextOutW(hdc, 350, 200, L"Nastav dlzku pola X", 20);
          }
     }
     else
     {
          TextOutW(hdc, 350, 200, L"Pole X nastavene", 17);
     }
     if (Buffer_Edit[1] != nullptr)
     {
          if (wcscmp(Buffer_Edit[1], L"0") <= 0)
          {
               TextOutW(hdc, 350, 215, L"Nastav dlzku pola Y", 20);
          }
     }
     else
     {
          TextOutW(hdc, 350, 215, L"Pole Y nastavene", 17);
     }
     if (Buffer_Edit[2] != nullptr)
     {
          if (wcscmp(Buffer_Edit[2], L"0") <= 0)
          {
               TextOutW(hdc, 350, 230, L"Nastav velkost dat", 20);
          }
     }
     else
     {
          TextOutW(hdc, 350, 230, L"Velkost dat OK", 15);
     }
     if (Buffer_Edit[3] != nullptr)
     {
          if (wcscmp(Buffer_Edit[3], L"0") <= 0)
          {
               TextOutW(hdc, 350, 245, Data_Text.c_str(), Data_Text.length());
          }
     }
     else
     {
          TextOutW(hdc, 350, 245, L"Pole X nastavene", 17);
     }
     if (Buffer_Edit[4] != nullptr)
     {
          if (wcscmp(Buffer_Edit[4], L"0") <= 0)
          {
               TextOutW(hdc, 350, 260, L"Vloz X", 7);
          }
     }
     else
     {
          TextOutW(hdc, 350, 260, L"Data X nastavene", 17);
     }
     if (Buffer_Edit[5] != nullptr)
     {
          if (wcscmp(Buffer_Edit[5], L"0") <= 0)
          {
               TextOutW(hdc, 350, 275, L"Vloz Y", 7);
          }
     }
     else
     {
          TextOutW(hdc, 350, 275, L"Data Y nastavene", 17);
     }
}

void Data_Struct_Page::Cout_Create(HDC hdc)
{
     SetTextColor(hdc, RGB(255, 255, 255)); // biely text
     SetBkMode(hdc, TRANSPARENT);
     TextOutW(hdc, 200, 200, L"Lenght of X", 12);
     TextOutW(hdc, 200, 215, L"Lenght of Y", 12);
     TextOutW(hdc, 200, 230, L"Lenght of data", 15);
     TextOutW(hdc, 200, 245, L"Data", 5);
     TextOutW(hdc, 200, 260, L"Data X", 7);
     TextOutW(hdc, 200, 275, L"Data Y", 7);
     Edit_Box_Paint(hdc);
}

void Data_Struct_Page::Buttons_Function(int &page_num, HWND *Buttons, HWND *Edit_Boxes, bool *Buttons_state, WPARAM wparam, LPARAM lparam)
{
     enum BUTTONS_ID
     {
          Paint = 10000,
          Reset_Table,
          SetMatrix,
          Add_Data,
          Add_Sparse_Matrix
     };
     switch (LOWORD(wparam))
     {
     case Paint:
     {
          if (Bools[0] == true && Bools[1] == true)
          {
               Buttons_state[0] = !Buttons_state[0];
               InvalidateRect(Main_hwnd, NULL, true);
               UpdateWindow(Main_hwnd);
          }
          if (Bools[0] == false)
          {
               MessageBoxW(Main_hwnd, L"Nastav X_Lenght Y_Lenght a Lenght Of Data", MB_OK, NULL);
          }
          if (Bools[1] == false)
          {
               MessageBoxW(Main_hwnd, L"Pridaj data", MB_OK, NULL);
          }
          break;
     }

     case Reset_Table:
     {
          Indexes[0] = 0;
          // Sparse_matrix.Reset_Data();

          for (int i{}; i < 5; i++)
          {
               if (Buffer_Edit[i] != nullptr)
               {
                    delete[] Buffer_Edit[i];
                    Buffer_Edit[i] = nullptr;
               }
               SetWindowTextW(Edit_Boxes[i], L"");
          }

          MessageBoxW(Main_hwnd, L"Table Reseted", MB_OK, NULL);
          break;
     }
     case SetMatrix:
     {
          if (Buffer_Edit[0] && Buffer_Edit[1] && Buffer_Edit[2])
          {
               if (wcscmp(Buffer_Edit[0], L"0") == 0 && wcscmp(Buffer_Edit[1], L"0") == 0 && wcscmp(Buffer_Edit[2], L"0") == 0)
               {
                    if (GetWindowTextLengthW(Edit_Boxes[0]) != 0 && GetWindowTextLengthW(Edit_Boxes[1]) != 0 && GetWindowTextLengthW(Edit_Boxes[2]) != 0)
                    {
                         if (GetWindowTextLengthW(Edit_Boxes[0]) != 0)
                         {
                              Size_Of_Buffers[0] = GetWindowTextLengthW(Edit_Boxes[0]);
                              Size_Of_Buffers[0]++;
                              if (Buffer_Edit[0] != nullptr)
                              {
                                   delete[] Buffer_Edit[0];
                                   Buffer_Edit[0] = nullptr;
                              }
                              Buffer_Edit[0] = new wchar_t[Size_Of_Buffers[0]];
                              GetWindowTextW(Edit_Boxes[0], Buffer_Edit[0], Size_Of_Buffers[0]);
                         }
                         if (GetWindowTextLengthW(Edit_Boxes[1]) != 0)
                         {
                              Size_Of_Buffers[1] = GetWindowTextLengthW(Edit_Boxes[1]);
                              Size_Of_Buffers[1]++;
                              if (Buffer_Edit[1] != nullptr)
                              {
                                   delete[] Buffer_Edit[1];
                                   Buffer_Edit[1] = nullptr;
                              }
                              Buffer_Edit[1] = new wchar_t[Size_Of_Buffers[1]];
                              GetWindowTextW(Edit_Boxes[1], Buffer_Edit[1], Size_Of_Buffers[1]);
                         }
                         if (GetWindowTextLengthW(Edit_Boxes[2]) != 0)
                         {
                              Size_Of_Buffers[2] = GetWindowTextLengthW(Edit_Boxes[2]);
                              Size_Of_Buffers[2]++;
                              if (Buffer_Edit[2] != nullptr)
                              {
                                   delete[] Buffer_Edit[2];
                                   Buffer_Edit[2] = nullptr;
                              }
                              Buffer_Edit[2] = new wchar_t[Size_Of_Buffers[2]];
                              GetWindowTextW(Edit_Boxes[2], Buffer_Edit[2], Size_Of_Buffers[2]);
                         }
                         if (GetWindowTextLengthW(Edit_Boxes[0]) != 0 && GetWindowTextLengthW(Edit_Boxes[1]) != 0 && GetWindowTextLengthW(Edit_Boxes[2]) != 0)
                         {
                              Buffer_Message_Box[0] = L"";
                              Buffer_Message_Box[0] = L"Matrix set X: ";
                              Buffer_Message_Box[0] += Buffer_Edit[0];
                              Buffer_Message_Box[0] += L"\nMatrix set Y: ";
                              Buffer_Message_Box[0] += Buffer_Edit[1];
                              Buffer_Message_Box[0] += L"\nX a Y Nastavene.";
                              Sparse_matrix.set_Lenght_X_Y_Size(Buffer_Edit[0], Buffer_Edit[1], Buffer_Edit[2]);
                              InvalidateRect(Main_hwnd, NULL, true);
                              UpdateWindow(Main_hwnd);
                              MessageBoxW(Main_hwnd, Buffer_Message_Box->c_str(), MB_OK, NULL);
                              Bools[0] = true;
                              break;
                         }
                    }
               }

               else
               {
                    Buffer_Message_Box[0] = L"";
                    Buffer_Message_Box[0] = L"Matrix set X: ";
                    Buffer_Message_Box[0] += Buffer_Edit[0];
                    Buffer_Message_Box[0] += L"\nMatrix set Y: ";
                    Buffer_Message_Box[0] += Buffer_Edit[1];
                    Buffer_Message_Box[0] += L"\nPre nove nastavenie stlac reset tlacidlo.";
                    MessageBoxW(Main_hwnd, Buffer_Message_Box->c_str(), MB_OK, NULL);
                    SetWindowTextW(Edit_Boxes[0], Buffer_Edit[0]);
                    SetWindowTextW(Edit_Boxes[1], Buffer_Edit[1]);
                    SetWindowTextW(Edit_Boxes[2], Buffer_Edit[2]);
               }
          }
          else
          {
               MessageBoxW(Main_hwnd, L"Buffers = nullptr", MB_OK, NULL);
               Buffer_Edit[0] = new wchar_t[2]{L"0"};
               Buffer_Edit[1] = new wchar_t[2]{L"0"};
               Buffer_Edit[2] = new wchar_t[2]{L"0"};
          }
          break;
     }
     case Add_Data:
     {
          std::wstring Data_Index = Buffer_Edit[2];
          if (Indexes[0] != std::stoi(Data_Index))
          {

               if (GetWindowTextLengthW(Edit_Boxes[3]) != 0 && GetWindowTextLengthW(Edit_Boxes[4]) != 0 && GetWindowTextLengthW(Edit_Boxes[5]) != 0)
               {

                    Size_Of_Buffers[4] = GetWindowTextLengthW(Edit_Boxes[3]);
                    Size_Of_Buffers[4]++;
                    if (Buffer_Edit[4] != nullptr)
                    {
                         delete[] Buffer_Edit[4];
                         Buffer_Edit[4] = nullptr;
                    }
                    Buffer_Edit[4] = new wchar_t[Size_Of_Buffers[4]];
                    GetWindowTextW(Edit_Boxes[4], Buffer_Edit[4], Size_Of_Buffers[4]);
                    Size_Of_Buffers[5] = GetWindowTextLengthW(Edit_Boxes[4]);
                    Size_Of_Buffers[5]++;
                    if (Buffer_Edit[5] != nullptr)
                    {
                         delete[] Buffer_Edit[5];
                         Buffer_Edit[5] = nullptr;
                    }
                    Buffer_Edit[5] = new wchar_t[Size_Of_Buffers[5]];
                    GetWindowTextW(Edit_Boxes[5], Buffer_Edit[5], Size_Of_Buffers[5]);
                    Size_Of_Buffers[3] = GetWindowTextLengthW(Edit_Boxes[3]);
                    Size_Of_Buffers[3]++;
                    if (Buffer_Edit[3] != nullptr)
                    {
                         delete[] Buffer_Edit[3];
                         Buffer_Edit[3] = nullptr;
                    }

                    Buffer_Edit[3] = new wchar_t[Size_Of_Buffers[3]];
                    GetWindowTextW(Edit_Boxes[4], Buffer_Edit[3], Size_Of_Buffers[3]);
                    Indexes[0] = Sparse_matrix.add_data(Buffer_Edit[3], Buffer_Edit[4], Buffer_Edit[5]);

                    if (wcscmp(Buffer_Edit[3], L"") != 0)
                    {
                         if (Indexes[0] != -1)
                         {
                              SetWindowTextW(Edit_Boxes[3], L"");
                              MessageBoxW(Main_hwnd, L"Data added", MB_OK, NULL);
                         }
                         else
                         {
                              MessageBoxW(Main_hwnd, L"X or Y is used!!", MB_OK, NULL);
                         }
                    }
                    if (wcscmp(Buffer_Edit[4], L"") != 0)
                    {
                         SetWindowTextW(Edit_Boxes[4], L"");
                    }
                    if (wcscmp(Buffer_Edit[5], L"") != 0)
                    {
                         SetWindowTextW(Edit_Boxes[5], L"");
                    }
               }
          }

          else
          {
               MessageBoxW(Main_hwnd, L"Buffer full", MB_OK, NULL);
               Bools[1] = true;
          }

          break;
     }
     case Add_Sparse_Matrix:
     {
          Data_Struct_Page::Add_Sparse_Matrix(One, Two, Edit_Boxes);
          break;
     }
     }
}
void Data_Struct_Page::Key_Board_Func(WPARAM wparam, LPARAM lparam, int ID_Button, HWND *Window)
{
     switch (wparam)
     {
     case VK_RETURN:
     {
     }
     }
}

void Data_Struct_Page::Add_Sparse_Matrix(Sparse_Matrix &First, Sparse_Matrix &Second, HWND *Buttons)
{
     std::wstring Temp_Y, Temp_X;
     Two.set_Lenght_X_Y_Size(L"5", L"5", L"5");
     One.set_Lenght_X_Y_Size(L"5", L"5", L"5");
     for (int i = 1; i < 6; i++)
     {
          Temp_X = std::to_wstring(i);
          Two.add_data(L"2", Temp_X.c_str(), L"1");

          Temp_Y = std::to_wstring(i);
          One.add_data(L"1", L"1", Temp_Y.c_str());
     }
     Sparse_matrix = One + Two;
     {
          std::wstring Temp_X_Lenght, Temp_Y_Lenght, *Temp_X, *Temp_Y, Temp_Size;
          wchar_t **Temp_Buffer;
          Temp_Size = std::to_wstring(Sparse_matrix.Get_Size());
          Temp_X = new std::wstring[Sparse_matrix.Get_Size()];
          Temp_Y = new std::wstring[Sparse_matrix.Get_Size()];
          Temp_X_Lenght = std::to_wstring(Sparse_matrix.Get_Lenght_X());
          Temp_Y_Lenght = std::to_wstring(Sparse_matrix.Get_Lenght_Y());
          for (int i{}; i < Sparse_matrix.Get_Size(); i++)
          {
               Temp_X[i] = std::to_wstring(Sparse_matrix.Get_X(i));
               Temp_Y[i] = std::to_wstring(Sparse_matrix.Get_Y(i));
          }
          for (int i{}; i < 6; i++)
          {
               if (Buffer_Edit[i] != nullptr)
               {
                    delete[] Buffer_Edit[i];
                    Buffer_Edit[i] = nullptr;
               }
          }

          int Size_Of_String = Temp_X_Lenght.length();
          Buffer_Edit[0] = new wchar_t[Size_Of_String];
          wcscpy(Buffer_Edit[0], Temp_X_Lenght.c_str());
          Size_Of_String = Temp_Y_Lenght.length();
          Buffer_Edit[1] = new wchar_t[Size_Of_String];
          wcscpy(Buffer_Edit[1], Temp_Y_Lenght.c_str());
          Size_Of_String = Temp_Size.length();
          Buffer_Edit[2] = new wchar_t[Size_Of_String];
          wcscpy(Buffer_Edit[2], Temp_Size.c_str());

          for (int i{}; i < 3; i++)
          {
               SetWindowTextW(Buttons[i], Buffer_Edit[i]);
          }
          Temp_Buffer = new wchar_t *[10];
          Temp_Buffer = Sparse_matrix.Get_Data();
          MessageBoxW(Main_hwnd, Temp_Buffer[2], MB_OK, NULL);
     }

     Bools[0] = true;
     Bools[1] = true;
     Indexes[0] = 6;
}

void Data_Struct_Page::To_Wstring()
{
}

void Data_Struct_Page::Edit_Box_Paint(HDC hdc)
{
     std::vector<std::wstring> Text{L"Degree",L"Coeficient",L"Exponecial"};
     HPEN hpen = CreatePen(PS_SOLID, 3, RGB(200, 0, 0));
     HPEN holdpen = (HPEN)SelectObject(hdc, hpen);
     HBRUSH hOldBrush;
     HBRUSH Second = CreateSolidBrush(RGB(0, 0, 200));
     HFONT hOldFont;
     HFONT HFont = CreateFontW(15, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_OUTLINE_PRECIS, CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, VARIABLE_PITCH, L"Segoe UI");
     for (int i{6}; i < 9; i++)
     {
          hOldFont = (HFONT) SelectObject(hdc,HFont);
          hOldBrush = (HBRUSH)SelectObject(hdc, GetStockObject(NULL_BRUSH));
          Rectangle(hdc, Edit_Postion_X[i] - 3, Edit_Postion_Y[i] - 23, Main_Rect.right, Edit_Postion_Y[i] + 23);
          SelectObject(hdc, hOldBrush);
          hOldBrush = (HBRUSH)SelectObject(hdc, Second);
          Rectangle(hdc, Edit_Postion_X[i], Edit_Postion_Y[i] - 20, Main_Rect.right, Edit_Postion_Y[i] - 3);
          TextOutW(hdc,Edit_Postion_X[i] + 83,Edit_Postion_Y[i]-19,Text[i - 6].c_str(),Text[i-6].length());
          SelectObject(hdc, hOldBrush);
          SelectObject(hdc,hOldFont);
     }
     HFONT hFont = CreateFontW(30, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE,
                               DEFAULT_CHARSET, OUT_OUTLINE_PRECIS, CLIP_DEFAULT_PRECIS,
                               CLEARTYPE_QUALITY, VARIABLE_PITCH, L"Segoe UI");
     hOldFont = (HFONT) SelectObject(hdc,hFont);
     TextOutW(hdc, Edit_Postion_X[6] + 40, Edit_Postion_Y[6] - 60, L"Polynomials", 12);
     SelectObject(hdc, hOldBrush);
     SelectObject(hdc, holdpen);
     SelectObject(hdc, hpen);
     SelectObject(hdc,hOldFont);
     DeleteObject(Second);
     DeleteObject(hFont);
     DeleteObject(HFont);
}