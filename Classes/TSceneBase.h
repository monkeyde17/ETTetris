#ifndef __T_SCENE_BASE_H__
#define __T_SCENE_BASE_H__

#include "ETCommon.h"
#include "ETBgLayer.h"

class TSceneBase : public Scene
{
public:
    TSceneBase();
    virtual ~TSceneBase();
    virtual bool init();
    CREATE_FUNC(TSceneBase);

protected:
    virtual void initBgLayer();
    virtual void initActionLayer();
    virtual void initMenuLayer();

protected:
    Layer *m_pBgLayer;
    Layer *m_pActionLayer;
    Layer *m_pMenuLayer;
};

#endif 