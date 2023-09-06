/*
 * Copyright 2011-2019 Branimir Karadzic. All rights reserved.
 * License: https://github.com/bkaradzic/bgfx#license-bsd-2-clause
 */
#include "Engine/App.h"
#include "entry/entry.h"
#include "Engine/Data.h"
#include <iostream>

class EditorSandbox : public App {
public:
    EditorSandbox(int x, int y, const char string[8]) : App(x, y, string) {
    }

    void init() override {
        App::init();
        currentCamera = new OCamera();
        debugProgram = bgfx::createProgram(
                Data::loadShaderBin("v_simple.vert"),
                Data::loadShaderBin("f_simple.frag"),
                false
        );
        testMesh = new Object();
        testMesh->addComponent<CTransform>()->setPosition({0.0, 0.0, 0.0});
        testMesh->addComponent<CMeshRenderer>()
                ->setMesh(Data::loadMesh("data/queen.off"), MOVABLE)
                ->setMaterial(debugProgram);
        //testMesh->addComponent<CRigidBody>();
    }
};


int _main_(int, char**) { return 0;}

int main(int _argc, const char* const* _argv)
{
    EditorSandbox application(1024, 768, "useless");

    application.init();
    application.run();
    application.cleanup();
    return 0;
}
