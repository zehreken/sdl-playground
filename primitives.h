#ifndef PRIMITIVES_H
#define PRIMITIVES_H

typedef struct ColorRGBTag
{
    int r;
    int g;
    int b;
} ColorRGB;

typedef struct IntVector2Tag
{
    int x;
    int y;
} IntVector2;

typedef struct Box2DTag
{
    IntVector2 position;
    IntVector2 size;
    ColorRGB color;
} Box2D;

#endif
