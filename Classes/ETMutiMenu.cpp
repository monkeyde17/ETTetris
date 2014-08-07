#include "ETMutiMenu.h"

bool ETMutiMenu::init()
{
    if (!Menu::init())
    {
        return false;
    }

    _eventDispatcher->removeEventListenersForTarget(this);

    return true;
}

void ETMutiMenu::onEnter()
{
    Menu::onEnter();

    auto pListener = EventListenerTouchAllAtOnce::create();
    
    pListener->onTouchesBegan = CC_CALLBACK_2(ETMutiMenu::onTouchesBegan, this);
    pListener->onTouchesMoved = CC_CALLBACK_2(ETMutiMenu::onTouchesMoved, this);
    pListener->onTouchesEnded = CC_CALLBACK_2(ETMutiMenu::onTouchesEnded, this);
    pListener->onTouchesCancelled = CC_CALLBACK_2(ETMutiMenu::onTouchesCancelled, this);

    _eventDispatcher->addEventListenerWithSceneGraphPriority(pListener, this);
}

void ETMutiMenu::onTouchesBegan(const std::vector<Touch*> &pTouches, Event *pE)
{
    for (auto pT : pTouches)
    {
        auto item = this->getItemForTouch(pT);

        if (item)
        {
            item->selected();
        }
    }
}

void ETMutiMenu::onTouchesEnded(const std::vector<Touch*> &pTouches, Event *pE)
{
    this->retain();
    
    for (auto pT : pTouches)
    {
        auto item = this->getItemForTouch(pT);
        if (item)
        {
            item->unselected();
            item->activate();
        }
    }
    
    this->release();
}

void ETMutiMenu::onTouchesMoved(const std::vector<Touch*> &pTouches, Event *pE)
{
    for (auto pT : pTouches)
    {
        auto item = this->getItemForTouch(pT);
        if (item)
        {
            item->selected();
        }
    }
    
}

void ETMutiMenu::onTouchesCancelled(const std::vector<Touch*> &pTouches, Event *pE)
{
    this->retain();
    for (auto pT : pTouches)
    {
        auto item = this->getItemForTouch(pT);
        if (item)
        {
            item->unselected();
        }
    }
    this->release();
}
