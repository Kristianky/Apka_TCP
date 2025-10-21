#include "Data_Struct.h"

Data_Struct_Page::Data_Struct_Page(HWND hwnd) : Pages(hwnd)

{
     Windows_Names = new wchar_t *[9]{{L"Paint"}, {L"ShowStauts"}, {L"0"}, {L"0"}, {L"0"}, {L"0"}, {L"0"}, {L"0"}, {L"Add Data"}};
     Windows_CLASS = new wchar_t *[5]{{L"BUTTON"}, {L"EDIT"}};
     Number_Of_Windows = new int{9};
     Windows_PositionsX = new int[9]{10, 210, 10, 10, 10, 10, 10, 10, 410};
     Windows_PositionsY = new int[9]{10, 10, 200, 215, 230, 245, 260, 275, 10};
     Windows = new HWND[10];
     Size_Of_Buffers = new int[8];
     Buffer_1 = new wchar_t *[6]{{L"0"}, {L"0"}, {L"0"}, {L"0"}, {L"0"}, {L"0"}};
     Indexes = new int[5]{0};
}

Data_Struct_Page::~Data_Struct_Page()
{
}

void Data_Struct_Page::Create_WindowW(HWND *Buttons, int BUTTON)
{

     for (int i{}; i < *Number_Of_Windows; i++)
     {
          if (i < 2 || i > 7)
          {
               Buttons[i] = CreateWindowW(Windows_CLASS[0], Windows_Names[i], WS_CHILD | WS_VISIBLE, Windows_PositionsX[i], Windows_PositionsY[i], 200, 100, Main_hwnd, (HMENU)(BUTTON + i), NULL, NULL);
               Windows[i] = Buttons[i];
          }
          else
          {
               Buttons[i] = CreateWindowW(Windows_CLASS[1], Windows_Names[i], WS_CHILD | WS_VISIBLE, Windows_PositionsX[i], Windows_PositionsY[i], 190, 15, Main_hwnd, (HMENU)(BUTTON + i), NULL, NULL);
               Windows[i] = Buttons[i];
          }
     }
}

void Data_Struct_Page::Cout_Button_1(HDC hdc)
{
     if (wcscmp(Buffer_1[0], L"0") == 0)
     {
          SetTextColor(hdc, RGB(255, 255, 255)); // biely text
          SetBkMode(hdc, TRANSPARENT);
          TextOutW(hdc, 350, 200, L"Nastav dlzku pola X", 20);
     }
     if (wcscmp(Buffer_1[1], L"0") == 0)
     {
          SetTextColor(hdc, RGB(255, 255, 255)); // biely text
          SetBkMode(hdc, TRANSPARENT);
          TextOutW(hdc, 350, 215, L"Nastav dlzku pola Y", 20);
     }
     if (wcscmp(Buffer_1[2], L"0") == 0)
     {
          SetTextColor(hdc, RGB(255, 255, 255)); // biely text
          SetBkMode(hdc, TRANSPARENT);
          TextOutW(hdc, 350, 230, L"Nastav velkost dat", 20);
     }
     else
     {
          Sparse_Matrix.set_Lenght_X_Y(Buffer_1[0], Buffer_1[1]);
          std::wstring Size_Temp = Buffer_1[0];
          Size_Of_Buffers[6] = std::stoi(Size_Temp);
          Size_Temp = Buffer_1[1];
          Size_Of_Buffers[7] = std::stoi(Size_Temp);
          SetTextColor(hdc, RGB(255, 255, 255)); // biely text
          SetBkMode(hdc, TRANSPARENT);
          RECT rect;
          rect.left = 350;
          rect.top = 230;
          rect.right = 600;
          rect.bottom = 300;
          int Position_Y{500};
          for (int j{}; j < Size_Of_Buffers[6]; j++)
          {
               Sparse_Matrix.Print(Buffer_2);
               TextOutW(hdc,500,Position_Y,Buffer_2.c_str(),20);
               Position_Y += 15;
          }
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
}

void Data_Struct_Page::Buttons_Function(int &page_num, HWND *Buttons, bool *Buttons_state, WPARAM wparam, LPARAM lparam)
{
     enum BUTTONS_ID
     {
          Paint = 10000,
          ShowWindow,
          Add_Data = 10008
     };
     switch (LOWORD(wparam))
     {
     case Paint:
          Buttons_state[0] = !Buttons_state[0];
          InvalidateRect(Main_hwnd, NULL, true);
          UpdateWindow(Main_hwnd);

          break;
     case ShowWindow:
          if (Buttons_state[0])
          {
               MessageBoxW(Main_hwnd, L"True", MB_OK, MB_OK);
          }
          else if (!Buttons_state[0])
          {
               MessageBoxW(Main_hwnd, L"False", MB_OK, MB_OK);
          }
          break;
     case Add_Data:
          Size_Of_Buffers[4] = GetWindowTextLengthW(Buttons[6]);
          Size_Of_Buffers[4]++;
          GetWindowTextW(Buttons[6], Buffer_1[4], Size_Of_Buffers[4]);
          Size_Of_Buffers[5] = GetWindowTextLengthW(Buttons[7]);
          Size_Of_Buffers[5]++;
          GetWindowTextW(Buttons[7], Buffer_1[5], Size_Of_Buffers[5]);
          Size_Of_Buffers[3] = GetWindowTextLengthW(Buttons[5]);
          Size_Of_Buffers[3]++;
          GetWindowTextW(Buttons[5], Buffer_1[3], Size_Of_Buffers[3]);
          Sparse_Matrix.add_data(Buffer_1[3], Buffer_1[2], Indexes[0], Buffer_1[5], Buffer_1[6]);
          break;
     }
}

void Data_Struct_Page::Key_Board_Func(WPARAM wparam, LPARAM lparam, int ID_Button, HWND *Window)
{
     switch (wparam)
     {
     case VK_RETURN:
     {
          Size_Of_Buffers[0] = GetWindowTextLengthW(Window[2]);
          Size_Of_Buffers[0]++;
          Buffer_1[0] = new wchar_t[Size_Of_Buffers[0]];
          GetWindowTextW(Window[2], Buffer_1[0], Size_Of_Buffers[0]);
          Size_Of_Buffers[1] = GetWindowTextLengthW(Window[3]);
          Size_Of_Buffers[1]++;
          Buffer_1[1] = new wchar_t[Size_Of_Buffers[1]];
          GetWindowTextW(Window[3], Buffer_1[1], Size_Of_Buffers[1]);
          Size_Of_Buffers[2] = GetWindowTextLengthW(Window[4]);
          Size_Of_Buffers[2]++;
          Buffer_1[2] = new wchar_t[Size_Of_Buffers[2]];
          GetWindowTextW(Window[4], Buffer_1[2], Size_Of_Buffers[2]);
          Sparse_Matrix.set_Lenght_X_Y(Buffer_1[0], Buffer_1[1]);
          MessageBoxW(Main_hwnd, L"Stlacil si enter", MB_OK, NULL);
     }
     }
}
