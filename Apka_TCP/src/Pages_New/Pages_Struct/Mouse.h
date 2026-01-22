#ifndef _MOUSE_H_
#define _MOUSE_H_

#include <windows.h>

// Tuto classu nikde nevytvarat vsetko budeme pouzivat ako stati nech sa to da volat z viacerych miest
// classa pre ovladanie, pozicoivanie mysi
class Mouse
{
protected:
   // Suradnice X a Y
   inline static short X;
   inline static short Y;

public:
   inline static bool Lh_Butt_Down_Status;
   static void UpdatePosition(LPARAM lp);
   static bool Inside(RECT &rect);
   static bool LH_Button_Down()
   {
      Lh_Butt_Down_Status = true;
      return true;
   }
   static bool LH_Button_Up() { return true; }
   static bool LH_BUTTON_Clicked();
};
#endif