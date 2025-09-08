#include "Pages.h"

Pages::Pages(){

}

Pages::~Pages(){
    delete [] Buttons;
    delete [] Buttons_Names;
    delete [] Buttons_PositionsX;
    delete [] Buttons_PositionsY;
}