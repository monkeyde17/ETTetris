#ifndef __T_SCENE_MAIN_H__
#define __T_SCENE_MAIN_H__

#include "TSceneBase.h"

class TSceneMain : public TSceneBase
{
public:
    CREATE_FUNC(TSceneMain);

private:
    void initActionLayer();
};

#endif