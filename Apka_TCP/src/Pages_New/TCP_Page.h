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
  virtual void Pages_Func(HWND hwnd, LPARAM lparam) override;
};

#endif