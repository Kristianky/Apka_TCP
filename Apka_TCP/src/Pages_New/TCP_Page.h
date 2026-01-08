#ifndef _TCPPAGE_H_
#define _TCPPAGE_H_

#include "PagesVirtual.h"

class TCPPage : public VirtualPage
{
private:
public:
  virtual void Button_Create(HDC hdc) override;
  virtual ~TCPPage() {};
  TCPPage(HWND hwnd);
  virtual void Pages_Func(HWND hwnd, HDC hdc, LPARAM lparam, WPARAM wparam) override;
};

#endif