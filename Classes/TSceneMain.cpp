#include "TSceneMain.h"

void TSceneMain::initActionLayer()
{
    TSceneBase::initActionLayer();

    auto sprite = Sprite::create("block.png");
    auto s = sprite->getContentSize();

    for (auto i = 0; i < DWIDTH / s.width; i++)
    {
        for (auto j = 0; j < DHEIGHT / s.height; j++)
        {
            auto sprite = Sprite::create("block.png");
            m_pActionLayer->addChild(sprite);
            sprite->setPosition(ETPOS(i * s.width + s.width / 2, j * s.height + s.height / 2));
        }
    }
}