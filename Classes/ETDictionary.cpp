#include "ETDictionary.h"

ETDictionary * ETDictionary::m_instance;

ETDictionary::ETDictionary()
{
    //m_pDic = Dictionary::createWithContentsOfFileThreadSafe(szXMLTextCh);
}

ETDictionary::~ETDictionary()
{
    if (m_pDic)
    {
        CC_SAFE_RELEASE(m_pDic);
    }
}

ETDictionary * ETDictionary::getInstance()
{
    if (m_instance == nullptr)
    {
        m_instance = new ETDictionary();
    }

    return m_instance;
}

void ETDictionary::destroyInstance()
{
    if (m_instance)
    {
        CC_SAFE_DELETE(m_instance);
    }

}

std::string ETDictionary::request(std::string key)
{
    return m_pDic->valueForKey(key)->getCString();
}

std::string ETDictionary::request(std::string key, int id)
{
    char buf[16] = {0};

    sprintf(buf, "%d", id);

    return m_pDic->valueForKey(key + buf)->getCString();
}
