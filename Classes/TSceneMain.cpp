#include "TSceneMain.h"

void TSceneMain::initActionLayer()
{
    TSceneBase::initActionLayer();
    
    if (nullptr == m_pGameControl)
    {
        setGameControl(new TGameControlTetris());
    }

    m_pGameControl->testInfo();
    update(1);
}