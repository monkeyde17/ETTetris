#ifndef _BLOCK_BG_LAYER_H_
#define _BLOCK_BG_LAYER_H_

#include "ETCommon.h"

class ETBgLayer : public LayerColor
{
public:
    ETBgLayer(const char szBgPath[]);
    virtual bool initWithColor(const Color4B &color);
    static ETBgLayer* create(const char szBgPath[] = nullptr, const Color4B &color = Color4B(0, 0, 0, 255));

private:
    void initBg();
private:
    Sprite *m_pBg;
    const char *m_szBgPath;
};

#endif