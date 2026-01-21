#include "Mouse.h"

// získanie X a Y z LPARAM
void Mouse::UpdatePosition(LPARAM lp) {
    X = static_cast<short>(lp & 0xFFFF);
    Y = static_cast<short>((lp >> 16) & 0xFFFF);
}
