#include"graphic.h"
#include"mathUtil.h"
int createTriangle() {
    angleMode(DEGREES);
    float angle = 150;
    struct SHAPE_VERTEX v[3] = {
         sin(0), -cos(0),
         sin(-angle),-cos(-angle),
         sin(angle),-cos(angle)
    };
    return createShape(v,3);
}

int createCircle() {
    angleMode(DEGREES);
    const int numCorners = 36;
    float angle = 360.0f / numCorners;
    struct SHAPE_VERTEX v[numCorners];
    for(int i=0; i<numCorners; i++){
        v[i].x = sin(angle * i);
        v[i].y = cos(angle * i);
    }
    return createShape(v, numCorners);
}