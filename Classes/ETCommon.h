#ifndef _ET_COMMON_H_
#define _ET_COMMON_H_

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
#pragma warning(disable:4996)
#pragma warning(disable:4819)
#endif

#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "ETResouce.h"
#include "ETEncrypt.h"


#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#include <jni.h>
#include "platform/android/jni/JniHelper.h"
#include <android/log.h>
#endif

#include <stdio.h>
#include <string>
#include <vector>

USING_NS_CC;
using namespace CocosDenshion;

/******ET Templete Start******/

// Debug opt
#define ETDEBUG		(true)

// Name
#define APPNAME		("Elevator")


// Design
#define DWIDTH		(480)
#define DHEIGHT		(800)

// Resouce
#define RWIDTH		(480)
#define RHEIGHT		(800)

//#define FONTSIZE(x)	((x) * RESRATE)

#define BGGRAY		(Color4B(77, 97, 111, 255))

// Windows
#define WHEIGHT		(cocos2d::Director::getInstance()->getWinSize().height)
#define WWIDTH		(cocos2d::Director::getInstance()->getWinSize().width)

// Origin
#define OWIDTH		((WWIDTH - DWIDTH) / 2.0)
#define OHEIGHT		((WHEIGHT - DHEIGHT) / 2.0)

// Fix
#define FIXHEIGHT	(0.01 * DHEIGHT)
#define FIXWIDTH	(0.01 * DWIDTH)

#define ONEPIX      (1)

// Position with orign
#define ETPOS(x, y)     ((Point(OWIDTH + x, OHEIGHT + y)))

#define ETGETSIZE(x)    ((x)->getContentSize())


#define ETTOPORDER      (999)

enum ETOrder
{
    zOrderBgLayer = 1,
    zOrderActionLayer,
    zOrderTouchLayer,
    zOrderMenuLayer,
    zOrderFgLayer
};

enum ETTag
{
    kTagBgLayer = 1,
    kTagActionLayer,
    kTagTouchLayer,
    kTagMenuLayer,
    kTagFgLayer
};

// Time & Date
class ETTime 
{
public:
    static unsigned long getCurrentTime()
    {
        time_t t;
        time(&t);
        return t;
    }

    static __String* getCurrentDate(time_t *t)
    {
        struct tm *timeinfo;
        timeinfo = localtime(t);

        return __String::createWithFormat("%4d-%02d-%02d", timeinfo->tm_year + 1900, timeinfo->tm_mon + 1, timeinfo->tm_mday);
    }
};
/******ET Templete End******/

typedef unsigned char uchar;

#endif