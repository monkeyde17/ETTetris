#include "TGameControl.h"


uchar TGameControlBase::m_pScreen[TGameControlBase::SHEIGHT][TGameControlBase::SWIDTH];

TGameControlBase::TGameControlBase()
{
    memset(m_pScreen, 0, sizeof(m_pScreen));
}

TGameControlBase::~TGameControlBase()
{

}

void TGameControlBase::setPoint(int x, int y, uchar v)
{
    if (x >= SWIDTH || y >= SHEIGHT)
    {
        return ;
    }

    if (x <= -1 && y <= -1)
    {
        memset(m_pScreen, v, sizeof(m_pScreen));
    }
    else if (x <= -1)
    {
        for (int i = 0; i < SWIDTH; i++)
        {
            m_pScreen[y][i] = v;
        }
    }
    else if (y <= -1)
    {
        for (int i = 0; i < SHEIGHT; i++)
        {
            m_pScreen[i][x] = v;
        }
    }
    else 
    {
        m_pScreen[y][x] = v;
    }
}

uchar TGameControlBase::getPoint(int x, int y)
{
    if (x < 0 || x >= SWIDTH || y < 0 || y >= SHEIGHT) { return uchar(0); }
    
    return m_pScreen[y][x];
}

void TGameControlBase::testInfo()
{
    CCLOG("--------TestInformation----------");
    for (int i = SHEIGHT - 1; i >= 0; i--)
    {
        std::string str;
        for (int j = 0; j < SWIDTH; j++)
        {
            str += m_pScreen[i][j] ? "*" : "-";
        }
        CCLOG("%s", str.c_str());
    }
    CCLOG("~~~~~~~~TestInformation~~~~~~~~~~");
}

