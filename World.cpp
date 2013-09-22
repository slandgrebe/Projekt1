#include "World.h"
#include "MyWindow.h"

World::World(void) {
    try {	    
        // ground Plane
        unitPlane = new Model("UnitPlane.xml");
        unitPlane->setShaderProgram(MyWindow::getInstance()->getUniformColorProgram()->getProgram());
        unitPlane->setModelToWorldMatrixUniform(MyWindow::getInstance()->getUniformColorProgram()->getModelToWorldMatrixUnif());
        unitPlane->setBaseColorUniform(MyWindow::getInstance()->getUniformColorProgram()->getBaseColorUnif(), 0.302f, 0.416f, 0.0589f, 1.0f);
        unitPlane->scale(glm::vec3(100.0f, 1.0f, 100.0f));

        // LookAt Point
        unitCubeColor = new Model("UnitCubeColor.xml");
        unitCubeColor->setShaderProgram(MyWindow::getInstance()->getObjectColorProgram()->getProgram());
        unitCubeColor->setModelToWorldMatrixUniform(MyWindow::getInstance()->getObjectColorProgram()->getModelToWorldMatrixUnif());

        // pillar1
        pillar = new Model("UnitCylinderTint.xml");
        pillar->setShaderProgram(MyWindow::getInstance()->getUniformColorTintProgram()->getProgram());
        pillar->setBaseColorUniform(MyWindow::getInstance()->getUniformColorTintProgram()->getBaseColorUnif(), 0, 1, 1, 1);
        pillar->setModelToWorldMatrixUniform(MyWindow::getInstance()->getUniformColorProgram()->getModelToWorldMatrixUnif());
        pillar->setPosition(10, 5, 10);
        pillar->scale(glm::vec3(4, 10, 4));

        // pillar2
        pillar2 = new Model("UnitCylinderTint.xml");
        pillar2->setShaderProgram(MyWindow::getInstance()->getUniformColorTintProgram()->getProgram());
        pillar2->setBaseColorUniform(MyWindow::getInstance()->getUniformColorTintProgram()->getBaseColorUnif(), 0, 1, 1, 1);
        pillar2->setModelToWorldMatrixUniform(MyWindow::getInstance()->getUniformColorProgram()->getModelToWorldMatrixUnif());
        pillar2->setPosition(10, 5, 20);
        pillar2->scale(glm::vec3(4, 10, 4));

        // joist
        joist = new Model("UnitCubeTint.xml");
        joist->setShaderProgram(MyWindow::getInstance()->getUniformColorTintProgram()->getProgram());
        joist->setBaseColorUniform(MyWindow::getInstance()->getUniformColorTintProgram()->getBaseColorUnif(), 1, 1, 0, 1);
        joist->setModelToWorldMatrixUniform(MyWindow::getInstance()->getUniformColorProgram()->getModelToWorldMatrixUnif());
        joist->setPosition(10, 12, 15);
        joist->scale(glm::vec3(4, 4, 10));
        
    }
    catch(std::exception& except) {
        printf("%s\n", except.what());
		throw;
    }
}


World::~World(void) {
    delete unitPlane;
    unitPlane = NULL;

    delete unitCubeColor;
    unitCubeColor = NULL;

    delete pillar;
    pillar = NULL;

    delete pillar2;
    pillar2 = NULL;

    delete joist;
    joist = NULL;
}


void World::render() {
    glutil::MatrixStack modelMatrix;

    // boden
    unitPlane->render(modelMatrix);

    // würfel
    unitCubeColor->setPosition(MyWindow::getInstance()->getCamera()->getTarget().x, MyWindow::getInstance()->getCamera()->getTarget().y, MyWindow::getInstance()->getCamera()->getTarget().z);
    unitCubeColor->render(modelMatrix);

    // tor
    pillar->render(modelMatrix);
    pillar2->render(modelMatrix);
    joist->render(modelMatrix);
}

// GETTER
Model* World::getUnitCubeColor() {
    return unitCubeColor;
}

Model* World::getUnitPlane() {
    return unitPlane;
}