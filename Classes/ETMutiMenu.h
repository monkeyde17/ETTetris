#ifndef __ET_MUTI_MENU_H__
#define __ET_MUTI_MENU_H__

#include "ETCommon.h"

class ETMutiMenu : public Menu
{
public:
    CREATE_FUNC(ETMutiMenu);

    virtual bool init();
    virtual void onEnter();

    void onTouchesBegan(const std::vector<Touch*> &pTouches, Event *pE);
    void onTouchesMoved(const std::vector<Touch*> &pTouches, Event *pE);
    void onTouchesEnded(const std::vector<Touch*> &pTouches, Event *pE);
    void onTouchesCancelled(const std::vector<Touch*> &pTouches, Event *pE);
};

#endif