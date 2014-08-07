#ifndef __ET_ENCRYPT_H_
#define __ET_ENCRYPT_H_

#include "ETCommon.h"

/**
 * game data
 */
typedef struct __GameData
{
    float   m_fMusicVolume;
    float   m_fSoundVolume;

}GameData;

class ETEncrypt
{
public:
    ETEncrypt();
    ~ETEncrypt();

    static ETEncrypt* getInstance();
    static void destroyInstance();

public:
    void initConfig();

private:
    /**
     * read file
     */
    bool initFromFile();

    /**
     * encode
     */
    void encode();
    void encode(char *buf);

    /**
     * decode
     */
    void decode();

    /**
     * save file
     */
    bool saveToFile();

private:
    GameData            *m_pGameData;
    static ETEncrypt    *m_pEncrypt;
};

#endif 