#include "TSceneBase.h"

TSceneBase::TSceneBase()
    : m_pBgLayer(nullptr)
    , m_pActionLayer(nullptr)
    , m_pMenuLayer(nullptr)
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

void TSceneBase::initBgLayer()
{
    m_pBgLayer = ETBgLayer::create();
    addChild(m_pBgLayer, zOrderBgLayer);
}

void TSceneBase::initActionLayer()
{
    m_pActionLayer = Layer::create();
    addChild(m_pActionLayer, zOrderActionLayer);
}

void TSceneBase::initMenuLayer()
{
    m_pMenuLayer = Layer::create();
    addChild(m_pMenuLayer, zOrderMenuLayer);
}
