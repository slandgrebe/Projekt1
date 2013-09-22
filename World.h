#ifndef WORLD_H
#define WORLD_H

#include "framework.h"
#include "Mesh.h"
#include "Model.h"

class World {
private:
    Model* unitCubeColor;
    Model* unitPlane;
    Model* pillar;
    Model* pillar2;
    Model* joist;

public:
    World(void);
    ~World(void);

    void render();

    // models
    Model* getUnitCubeColor();
    Model* getUnitPlane();
};

#endif WORLD_H