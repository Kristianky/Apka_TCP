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
   inline static bool Lh_Butt_Up_Status;
   inline static bool Lh_Butt_Clicked_Status;
   inline static HCURSOR Cursor;
   static void UpdatePosition(LPARAM lp);
   static bool Inside(RECT &rect);
   static void LH_Button_Down()
   {
      Lh_Butt_Down_Status = true;
      Lh_Butt_Up_Status = false;
   }
   static void LH_Button_Up()
   {
      Lh_Butt_Up_Status = true;
      Lh_Butt_Clicked_Status = false;
      Lh_Butt_Down_Status = false;
   }
   static void LH_BUTTON_Clicked();
};
#endif