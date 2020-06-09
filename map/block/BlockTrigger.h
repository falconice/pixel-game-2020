#ifndef BLOCK_TRIGER_H
#define BLOCK_TRIGER_H

#include <SFML/Graphics.hpp>

using namespace sf;

class BlockTrigger
{
private:
    float xBegin, yBegin, xEnd, yEnd;
    int type = 0;
    char flag = 'n';

public:
    BlockTrigger(int type, char flag, float xBegin, float yBegin)
    {
        this->type = type;
        this->flag = flag;
    };

    char getFlag()
    {
        return this->flag;
    };

    int getType()
    {
        return this->type;
    };

    float getBeginX()
    {
        return this->xBegin;
    };

    float getBeginY()
    {
        return this->yBegin;
    }

    float getEndX()
    {
        return this->xEnd;
    }
    float getEndY()
    {
        return this->yEnd;
    }
};

#endif