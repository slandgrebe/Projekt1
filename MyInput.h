
#ifndef MYINPUT_H
#define MYINPUT_H

#include "MyWindow.h"

class MyInput {
public:
    MyInput();
    ~MyInput(void);

    void keyboard(unsigned char key, int x, int y);
};

#endif