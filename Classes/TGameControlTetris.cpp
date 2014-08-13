#include "TGameControlTetris.h"


TGameControlTetris::TGameControlTetris()
{
    setPoint(-1, 4, 255);
    setPoint(24, -1, 255);
    setPoint(4, -1, 255);
}

TGameControlTetris::~TGameControlTetris()
{

}

void TGameControlTetris::update(float time)
{}