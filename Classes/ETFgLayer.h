#ifndef __ET_FG_LAYER_H__
#define __ET_FG_LAYER_H__


#include "ETCommon.h"

class ETFgLayer : public LayerColor
{
public:
    ETFgLayer();

    ETFgLayer(const std::string bgPath);

    static ETFgLayer* create(const std::string bgPath);
    bool init();

    virtual void onEnter();

    bool onTouchBegan(Touch *pT, Event *pE);
    void onTouchMoved(Touch *pT, Event *pE);
    void onTouchEnded(Touch *pT, Event *pE);
    void onTouchCancelled(Touch *pT, Event *pE);

private:
    void initBg();

protected:
    Menu *m_pMenu;
    std::string m_sBgPath;
    Sprite *m_pBg;
    SpriteFrameCache *m_pCache;
private:
    bool m_bIsTouch;
};

#endif