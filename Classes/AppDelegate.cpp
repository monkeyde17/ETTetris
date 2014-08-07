#include "AppDelegate.h"

#include "ETCommon.h"
#include "ETLoadingScene.h"

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();

    if(!glview) 
    {
        glview = GLView::createWithRect(APPNAME, Rect(0, 0, DWIDTH / 2, DHEIGHT / 2));
        director->setOpenGLView(glview);
    }

    director->setDisplayStats(ETDEBUG);
    director->setAnimationInterval(1.0 / 60);
    if (WWIDTH * DHEIGHT > WHEIGHT * DWIDTH) 
    {
        glview->setDesignResolutionSize(DWIDTH, DHEIGHT, ResolutionPolicy::FIXED_HEIGHT);
    }
    else 
    {
        glview->setDesignResolutionSize(DWIDTH, DHEIGHT, ResolutionPolicy::FIXED_WIDTH);
    }

    auto scene = ETLoadingScene::create();
    director->runWithScene(scene);
    scene->loading();    

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
