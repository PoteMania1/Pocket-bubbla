#include "Colisionable.h"

bool colisionable::isColision(colisionable& obj) const
{
    return getBounds().intersects(obj.getBounds());
}
