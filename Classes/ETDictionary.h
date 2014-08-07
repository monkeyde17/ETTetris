#ifndef __ET_DICTIONARY_H__
#define __ET_DICTIONARY_H__

#include "ETCommon.h"

class ETDictionary
{
public:
    ETDictionary();
    ~ETDictionary();

    static ETDictionary * getInstance();
    static void destroyInstance();

    std::string request(std::string key);
    std::string request(std::string key, int id);
private:
    Dictionary *m_pDic;

private:
    static ETDictionary * m_instance;
};

#endif