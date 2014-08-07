#include "ETFgLayer.h"

ETFgLayer::ETFgLayer()
    : m_bIsTouch(false)
    , m_pMenu(nullptr)
    , m_pBg(nullptr)
{
}

ETFgLayer::ETFgLayer(const std::string path)
    : m_bIsTouch(false)
    , m_pMenu(nullptr)
    , m_pBg(nullptr)
{
    m_sBgPath = path;
}

ETFgLayer* ETFgLayer::create(const std::string path)
{
    ETFgLayer *pLayer = new ETFgLayer(path);
    if (pLayer && pLayer->init())
    {
        pLayer->autorelease();
        return pLayer;
    }

    CC_SAFE_DELETE(pLayer);
    return nullptr;
}

bool ETFgLayer::init()
{
    if ( !LayerColor::initWithColor(Color4B(0, 0, 0, 144)) )
    {
        return false;
    }

    initBg();

    return true;
}

void ETFgLayer::initBg()
{
    Size bSize = getContentSize();
    m_pBg = Sprite::createWithSpriteFrameName(m_sBgPath);
    m_pBg->setPosition(Point(bSize.width / 2, bSize.height / 2));
    addChild(m_pBg);
}

void ETFgLayer::onEnter()
{
    Layer::onEnter();

    auto listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);

    listener->onTouchBegan = CC_CALLBACK_2(ETFgLayer::onTouchBegan, this);
    listener->onTouchMoved = CC_CALLBACK_2(ETFgLayer::onTouchMoved, this);
    listener->onTouchCancelled = CC_CALLBACK_2(ETFgLayer::onTouchCancelled, this);
    listener->onTouchEnded = CC_CALLBACK_2(ETFgLayer::onTouchEnded, this);

    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

bool ETFgLayer::onTouchBegan(Touch *pT, Event *pE)
{
    if (m_pMenu)
    {
        m_bIsTouch =  m_pMenu->onTouchBegan(pT, pE);
    }



    return true;
}

void ETFgLayer::onTouchMoved(Touch *pT, Event *pE)
{
    if (m_bIsTouch)
    {
        m_pMenu->onTouchMoved(pT, pE);
    }
}

void ETFgLayer::onTouchCancelled(Touch *pT, Event *pE)
{
    if (m_bIsTouch)
    {
        m_pMenu->onTouchCancelled(pT, pE);
    }
}

void ETFgLayer::onTouchEnded(Touch *pT, Event *pE)
{
    if (m_bIsTouch)
    {
        m_pMenu->onTouchEnded(pT, pE);
    }
    else
    {
        if (m_pBg)
        {
            if (!m_pBg->getBoundingBox().containsPoint(pT->getLocation()))
            {
                removeFromParent();
            }
        }
    }
}