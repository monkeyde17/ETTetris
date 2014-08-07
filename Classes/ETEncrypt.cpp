#include "ETEncrypt.h"

static const char szSavePath[] = "image.png";

static const char szPassword[] = {
    0x41, 0x02, 0x14, 0x34, 0x34,
    0x61, 0x22, 0x34, 0x14, 0x34,
    0x45, 0x12, 0x24, 0x74, 0x34,
    0x51, 0x42, 0x14, 0x44, 0x10,
    0x00
};

ETEncrypt *ETEncrypt::m_pEncrypt;

ETEncrypt *ETEncrypt::getInstance()
{
    if (m_pEncrypt == NULL)
    {
        m_pEncrypt = new ETEncrypt();
    }

    return m_pEncrypt;
}

void ETEncrypt::destroyInstance()
{
    if (m_pEncrypt)
    {
        delete m_pEncrypt;
        m_pEncrypt = NULL;
    }
}

ETEncrypt::ETEncrypt()
{
    m_pGameData = new GameData();
    memset(m_pGameData, 0, sizeof(GameData));

}

ETEncrypt::~ETEncrypt()
{
    if (m_pGameData) 
    {
        delete m_pGameData;
        m_pGameData = NULL;
    }
}


bool ETEncrypt::initFromFile()
{
    // CCFileUtils::sharedFileUtils()->fullPathFromRelativeFile(szSavePath);

    std::string  path;
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID) 
    ssize_t len;
    unsigned char *data;
    data = FileUtils::getInstance()->getFileDataFromZip(szSavePath, "rb", &len);
    path = FileUtils::getInstance()->getWritablePath();

    if (data)
    {
        delete []data;
        data = NULL;
    }
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
    path = "";
#endif

    path += szSavePath;

    FILE *pFile = NULL;
    pFile = fopen(path.c_str(), "rb");

    if (pFile == NULL)
    {

        saveToFile();
        return false;
    }

    fread(m_pGameData, sizeof(char), sizeof(GameData), pFile);

    fclose(pFile);

    pFile = NULL;

    decode();

    return true;
}

void ETEncrypt::encode()
{
    char *pBuf = NULL;
    int i, j = 0;
    int len;

    pBuf = (char *) m_pGameData;
    len = strlen(szPassword);

    for (i = 0; i < sizeof(GameData); i++)
    {
        pBuf[i] ^= szPassword[j++];
        j %= len;
    }
}

void ETEncrypt::encode(char *pBuf)
{
    int i, j = 0;
    int len;

    len = strlen(szPassword);

    for (i = 0; i < sizeof(GameData); i++)
    {
        pBuf[i] ^= szPassword[j++];
        j %= len;
    }
}

void ETEncrypt::decode()
{
    char *pBuf = NULL;
    int i, j = 0;
    int len;

    pBuf = (char *) m_pGameData;
    len = strlen(szPassword);

    for (i = 0; i < sizeof(GameData); i++)
    {
        pBuf[i] ^= szPassword[j++];
        j %= len;
    }
}

bool ETEncrypt::saveToFile()
{
    std::string path;
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    ssize_t len;
    unsigned char *data;
    data = FileUtils::getInstance()->getFileDataFromZip(szSavePath, "wb", &len);
    path = FileUtils::getInstance()->getWritablePath();

    if(data)
    {
        delete []data;
        data = NULL;
    }
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
    path = "";
#endif

    path += szSavePath;

    FILE *pFile = NULL;
    char buf[512];

    pFile = fopen(path.c_str(), "wb");

    if (NULL == pFile)
    {
        return false;
    }

    memcpy(buf, m_pGameData, sizeof(GameData));

    encode(buf);

    fwrite(buf, sizeof(char), sizeof(GameData), pFile);

    fclose(pFile);

    return true;
}

void ETEncrypt::initConfig()
{
    initFromFile();
}