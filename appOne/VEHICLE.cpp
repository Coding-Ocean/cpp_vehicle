#include"graphic.h"
#include"mathUtil.h"
#include "VEHICLE.h"

const VECTOR2& VEHICLE::pos() 
{ 
    return Pos; 
}

const VECTOR2& VEHICLE:: vel() 
{ 
    return Vel; 
}

const VECTOR2& VEHICLE::acc()const
{
    return Acc;
}

void VEHICLE::setImage(int img) 
{ 
    Id = ID::IMAGE; Img = img; 
}

void VEHICLE::setShape(int img) 
{ 
    Id = ID::CUSTOM; Img = img; 
}

void VEHICLE::setScale(float scale)
{
    Scale = scale;
}

void VEHICLE::setPos(float x, float y)
{
    Pos.x = x; Pos.y = y;
}

void VEHICLE::setVel(float x, float y)
{
    Vel.x = x; Vel.y = y;
}

VECTOR2 VEHICLE::toword() 
{ 
    return VECTOR2(sin(Angle), -cos(Angle)); 
}

void VEHICLE::setMaxSpeed(float maxSpeed)
{
    MaxSpeed = maxSpeed;
}

void VEHICLE::setMaxForce(float maxForce)
{
    MaxForce = maxForce;
}

VECTOR2 VEHICLE::attracted(const VECTOR2& target) 
{
    auto desired = target - Pos;
    //ターゲットに近づいたらスピードダウン
    auto distance = desired.mag();
    if (distance < RadiusArrive) {
        auto speed = map(distance, 0, RadiusArrive, 0, MaxSpeed);
        desired.setMag(speed);
    }
    else {
        desired.setMag(MaxSpeed);
    }
    return desired;
}

VECTOR2 VEHICLE::seek(const VECTOR2& target) 
{
    VECTOR2 desired = target - Pos;
    desired.setMag(MaxSpeed);
    VECTOR2 steer = desired - Vel;
    steer.limmit(MaxForce);
    return steer;
}

VECTOR2 VEHICLE::arrive(const VECTOR2& target) 
{
    auto desired = target - Pos;
    //ターゲットに近づいたらスピードダウン
    auto distance = desired.mag();
    if (distance < RadiusArrive) {
        auto speed = map(distance, 0, RadiusArrive, 0, MaxSpeed);
        desired.setMag(speed);
    }
    else {
        desired.setMag(MaxSpeed);
    }
    auto steer = desired - Vel;
    steer.limmit(MaxForce);
    return steer;
}

VECTOR2 VEHICLE::flee(const VECTOR2& target)
{
    VECTOR2 desired = target - Pos;
    if (desired.mag() < RadiusFlee) {
        desired.setMag(MaxSpeed);
        VECTOR2 steer = desired - Vel;
        steer.limmit(MaxForce);
        return -steer;
    }
    return VECTOR2(0, 0);
}

void VEHICLE::applyForce(const VECTOR2& force)
{
    Acc += force;
}

void VEHICLE::update()
{
    Vel += Acc;
    Vel.limmit(MaxSpeed);
    Pos += Vel;
    Acc *= 0;
}
void VEHICLE::draw()
{
    if (Id == ID::CUSTOM) {
        shape(Img, Pos.x, Pos.y, Angle, Scale);
    }
    else if (Id == ID::IMAGE) {
        rectMode(CENTER);
        image(Img, Pos.x, Pos.y, Angle);
    }
    else {
        fill(255, 255, 0);
        circle(Pos.x, Pos.y, Scale * 2);
    }
}
