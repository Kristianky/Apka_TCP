#ifndef _MOUSE_H_
#define _MOUSE_H_

#include <windows.h>

//Tuto classu nikde nevytvarat vsetko budeme pouzivat ako stati nech sa to da volat z viacerych miest
//classa pre ovladanie, pozicoivanie mysi
class Mouse
{
    private:
    //Suradnice X a Y
       inline static short X;
       inline static short Y;
    public:
       static void UpdatePosition(LPARAM lp);
       static bool Inside(RECT &rect);
};
#endif