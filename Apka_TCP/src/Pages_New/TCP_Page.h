#ifndef _TCPPAGE_H_
#define _TCPPAGE_H_

#include "PagesVirtual.h"

class TCPPage : public VirtualPage
{
private:
  RECT Draw_Text; // potom vymazat ked urobime zvlast classu na text
  std::vector<Button> Buttons;
  TCPClient Client1;

public:
  virtual void Button_Animation(HDC hdc) override;
  virtual ~TCPPage() {};
  TCPPage(HWND hwnd);
  virtual void Buttons_Func(HWND hwnd, LPARAM lparam) override;
  virtual void Buttons_Mouse_Clicked_Call(HWND Main_hwnd, UINT umsg) override;
  virtual void Page_Calls() override;
};

#endif