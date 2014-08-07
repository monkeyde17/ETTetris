#include "ETLoadingScene.h"

bool ETLoadingScene::init()
{
    if (!Scene::init())
    {
        return false;
    }

    initBg();
    initAction();
    return true;
}

void ETLoadingScene::initBg()
{
    m_pBgLayer = LayerColor::create(Color4B(0, 0, 0, 255));
    addChild(m_pBgLayer, zOrderBgLayer, kTagBgLayer);
}

void ETLoadingScene::initAction()
{
    // call the srand only once
    srand(time(nullptr));
}

void ETLoadingScene::loadingCallBack(Texture2D *pTexture)
{
    //SpriteFrameCache::getInstance()->addSpriteFrame(
    //SpriteFrameCache::getInstance()->addSpriteFramesWithFile("pic2.plist", pTexture);

    Director::getInstance()->replaceScene(TransitionFade::create(1, TSceneMain::create(), Color3B(255, 255, 255)));
}

void ETLoadingScene::loading()
{
    // init the config
    ETEncrypt::getInstance()->initConfig();

    // init the txt-ch.xml
    ETDictionary::getInstance();

    // loading sound


    // loading image

    // effect
    Director::getInstance()->getTextureCache()->addImageAsync("block.png", CC_CALLBACK_1(ETLoadingScene::loadingCallBack, this));
}