#include "unit.h"

Unit::Unit() : Element()
{
    // init Physics
    flying = false;
    movingLeft = false;
    movingRight = false;
    falling = false;
    jumping = false;
    xForce = 0;
    weight = 200;
    yForce = 0;
    xAcceleration = 0.5;

    maxSpeed = MAX_SPEED;
}

void Unit::SetMovingRight(bool state)
{
    movingRight = state;
}

void Unit::SetMovingLeft(bool state)
{
    movingLeft = state;
}

void Unit::updateMovementStates()
{
    if(yForce > 0 )
        falling = true;
    else
        falling = false;

    if(yForce < 0){
        jumping = true;
    }
    else{
        jumping = false;
    }
    if(yForce == 0){
        flying = false;
        // better grip on the floor
        xAcceleration = 1;
    }
    else{
        flying = true;
        // lower grip in the air
        xAcceleration = 0.5;
    }
}

void Unit::increaseLeftForce()
{
    if(xForce > - maxSpeed){
        xForce -= 1 * xAcceleration;
    }
}

void Unit::increaseRightForce()
{
    if(xForce < maxSpeed){
        xForce += 1 * xAcceleration;
    }
}

void Unit::decreaseXForce()
{
    if(xForce > 0)
        xForce -= 1 * xAcceleration;
    if(xForce < 0)
        xForce += 1 * xAcceleration;
}

float Unit::getXForce() const
{
    return xForce;
}

void Unit::setXForce(float value)
{
    xForce = value;
}

float Unit::getYForce() const
{
    return yForce;
}

void Unit::setYForce(float value)
{
    yForce = value;
    updateMovementStates();
}

void Unit::setMovingLeft(bool value)
{
    movingLeft = value;
}

bool Unit::isMovingRight() const
{
    return movingRight;
}

void Unit::setMovingRight(bool value)
{
    movingRight = value;
}

bool Unit::isMovingLeft() const
{
    return movingLeft;
}

int Unit::getWeight() const
{
    return weight;
}

bool Unit::isJumping() const
{
    return jumping;
}

bool Unit::isFalling() const
{
    return falling;
}

bool Unit::isFlying() const
{
    return flying;
}
