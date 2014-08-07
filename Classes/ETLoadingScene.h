#ifndef __ET_LOADING_SCENE_H__
#define __ET_LOADING_SCENE_H__

#include "ETCommon.h"
#include "ETDictionary.h"
#include "TSceneMain.h"

class ETLoadingScene : public Scene
{
public:
    bool init();
    CREATE_FUNC(ETLoadingScene);

    void loading();

private:
    void initAction();
    void initBg();

    void loadingCallBack(Texture2D *pNode);

private:
    Layer *m_pBgLayer;
    Layer *m_pActionLayer;
};

#endif
