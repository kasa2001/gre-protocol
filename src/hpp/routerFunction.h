#ifndef GRE_ROUTERFUNCTION_H
#define GRE_ROUTERFUNCTION_H


#include "Router.h"
class Router;

extern Router *router[4];
void renderRouter(int positionX, int positionY);
void renderGre(int positionX, int positionY, int firstInterface, int secondInterface);

#endif //GRE_ROUTERFUNCTION_H
