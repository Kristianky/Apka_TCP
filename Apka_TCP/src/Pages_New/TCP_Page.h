#ifndef _TCPPAGE_H_
#define _TCPPAGE_H_

#include "PagesVirtual.h"

class TCPPage : public VirtualPage
{
private:
  std::vector<Button> Buttons;
public:
  virtual void Button_Animation(HDC hdc) override;
  virtual ~TCPPage() {};
  TCPPage(HWND hwnd);
  virtual void Buttons_Func(HWND hwnd, LPARAM lparam) override;
  virtual void Buttons_Mouse_Clicked_Call(HWND Main_hwnd,UINT umsg) override;
};

#endif