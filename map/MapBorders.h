// Map Borders of Section 1

#ifndef MAP_SECTION_H
#define MAP_SECTION_H

class MapBorders
{

public:
    bool FirstBlock_CanGoUp(float x, float y)
    {

        if (0 < y)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool FirstBlock_CanGoDown(float x, float y)
    {

        if (y < 940)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool FirstBlock_CanGoRight(float x, float y)
    {

        if (x < 1860)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool FirstBlock_CanGoLeft(float x, float y)
    {

        if (0 < x)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    float FirstBlock_TeleportLeft(float x, float y) //<----
    {

        return (+1852);
    }

    float
    FirstBlock_TeleportRight(float x, float y) //---->
    {

        return (-1852);
    }

    float FirstBlock_TeleportUp(float x, float y) //^
    {

        return (+935);
    }

    float FirstBlock_TeleportDown(float x, float y) // v
    {
        return (-935);
    }
};

#endif