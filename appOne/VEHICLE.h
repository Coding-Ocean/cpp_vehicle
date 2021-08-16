#pragma once
#include"VECTOR2.h"
class VEHICLE
{
    enum class ID { CIRCLE, CUSTOM, IMAGE };
    VEHICLE::ID Id;
    int Img = 0;
    float Angle=0;
    float Scale=1;
    VECTOR2 Pos;
    VECTOR2 Vel;
    VECTOR2 Acc;
    float MaxSpeed=0;
    float MaxForce=0;
    float RadiusArrive=100;
    float RadiusFlee=200;
public:
    const VECTOR2& pos();
    const VECTOR2& vel();
    const VECTOR2& acc()const;
    void setImage(int img);
    void setShape(int img);
    void setScale(float scale);
    void setPos(float x, float y);
    void setVel(float x, float y);
    void setMaxSpeed(float maxSpeed);
    void setMaxForce(float maxForce);
    VECTOR2 toword();

    VECTOR2 attracted(const VECTOR2& target);
    VECTOR2 seek(const VECTOR2& target);
    VECTOR2 flee(const VECTOR2& target);
    VECTOR2 arrive(const VECTOR2& target);
    void applyForce(const VECTOR2& force);
    void update();
    void draw();
};

