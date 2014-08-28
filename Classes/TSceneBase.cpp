#include "TSceneBase.h"

TSceneBase::TSceneBase()
    : m_pBgLayer(nullptr)
    , m_pActionLayer(nullptr)
    , m_pMenuLayer(nullptr)
    , m_pGameControl(nullptr)
{}

TSceneBase::~TSceneBase()
{}

bool TSceneBase::init()
{
    if (!Scene::init())
    {
        return false;
    }

    initBgLayer();
    initActionLayer();
    initMenuLayer();

    return true;
}

void TSceneBase::setGameControl(TGameControlBase* pControl)
{
    if (m_pGameControl)
    {
        delete m_pGameControl;
        m_pGameControl = nullptr;
    }

    m_pGameControl = pControl;
}

void TSceneBase::initBgLayer()
{
    m_pBgLayer = ETBgLayer::create();
    addChild(m_pBgLayer, zOrderBgLayer);
}

void TSceneBase::initActionLayer()
{
    m_pActionLayer = Layer::create();
    addChild(m_pActionLayer, zOrderActionLayer);

    auto batchSprite = Sprite::create(szImgBlock);
    auto s = batchSprite->getContentSize();

    for (auto i = 0; i < TGameControlBase::SWIDTH; i++)
    {
        for (auto j = 0; j < TGameControlBase::SHEIGHT; j++)
        {
            auto sprite = Sprite::createWithSpriteFrame(batchSprite->getDisplayFrame());
            m_pActionLayer->addChild(sprite);
            sprite->setTag(10000 + 100 * i + j);
            sprite->setPosition(ETPOS(i * s.width + s.width / 2, j * s.height + s.height / 2));
            sprite->setOpacity(125);
        }
    }

}

void TSceneBase::initMenuLayer()
{
    m_pMenuLayer = Layer::create();
    addChild(m_pMenuLayer, zOrderMenuLayer);
}

void TSceneBase::update(float time)
{
    if (nullptr == m_pGameControl) { return ; }

    m_pGameControl->update(time);

    for (auto i = 0; i < TGameControlBase::SWIDTH; i++)
    {
        for (auto j = 0; j < TGameControlBase::SHEIGHT; j++)
        {
            auto sprite = m_pActionLayer->getChildByTag(10000 + i * 100 + j);
            sprite->setOpacity(m_pGameControl->getPoint(i, j));
        }
    }
}

