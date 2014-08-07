#include "ETBgLayer.h"


ETBgLayer::ETBgLayer(const char szBgPath[])
{
    m_szBgPath = szBgPath;
}

ETBgLayer *ETBgLayer::create(const char szBgPath[], const Color4B & color)
{
    ETBgLayer *pLayer = new ETBgLayer(szBgPath);

    if (pLayer && pLayer->initWithColor(color))
    {
        pLayer->autorelease();
        return pLayer;
    }

    CC_SAFE_DELETE(pLayer);
    pLayer = NULL;

    return NULL;
}

bool ETBgLayer::initWithColor(const Color4B &color)
{
    if (!LayerColor::initWithColor(color))
    {
        return false;
    }

    initBg();

    return true;
}

void ETBgLayer::initBg()
{
    if (m_szBgPath == nullptr) { return ; }

    m_pBg = Sprite::createWithSpriteFrameName(m_szBgPath);
    m_pBg->setPosition(ETPOS(DWIDTH / 2, DHEIGHT / 2));
    addChild(m_pBg);
}

