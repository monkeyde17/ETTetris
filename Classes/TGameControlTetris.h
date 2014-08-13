#ifndef __T_GAME_CONTROL_TETRIS_H__
#define __T_GAME_CONTROL_TETRIS_H__

#include "TGameControl.h"

class TGameControlTetris : public TGameControlBase
{
public:
    TGameControlTetris();
    virtual ~TGameControlTetris();

    virtual void update(float time);
};

#endif