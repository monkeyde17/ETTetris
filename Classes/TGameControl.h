#ifndef __T_GAME_CONTROL_H__
#define __T_GAME_CONTROL_H__

#include "ETCommon.h"

class TGameControlBase
{
public:
    TGameControlBase();
    virtual ~TGameControlBase();

    /**
     * update mode, each mode should rewrite this function
     */
    virtual void update(float delta) = 0;

    /**
     * set point value
     * @ x : point x
     * @ y : point y
     * @ v : value
     * if the value is -1, means we should light on a line
     * for example, setPoint(0, -1, true); means light on the first line
     */
    void setPoint(int x, int y, uchar v);

    /**
     * get point value
     * @ x : point x
     * @ y : point y
     */
    uchar getPoint(int x, int y);

    /**
     * test information for debug
     */
    void testInfo();
public:
    static const int SWIDTH = 30;
    static const int SHEIGHT = 50;

protected:
    /**
     * data, all share this data
     * the date means to the Opacity
     */
    static uchar m_pScreen[SHEIGHT][SWIDTH];
};

#endif