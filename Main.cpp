
#include "MyWindow.h"

//Called after the window and OpenGL are initialized. Called exactly once, before the main loop.
void init() {
    MyWindow::getInstance()->init();
}

//Called to update the display.
//You should call glutSwapBuffers after all of your rendering to display what you rendered.
//If you need continuous updates of the screen, call glutPostRedisplay() at the end of the function.
void display() {
    MyWindow::getInstance()->display();
}

//Called whenever the window is resized. The new window size is given, in pixels.
//This is an opportunity to call glViewport or glScissor to keep up with the change in size.
void reshape (int w, int h) {
    MyWindow::getInstance()->reshape(w, h);
}

//Called whenever a key on the keyboard was pressed.
//The key is given by the ''key'' parameter, which is in ASCII.
//It's often a good idea to have the escape key (ASCII value 27) call glutLeaveMainLoop() to 
//exit the program.
void keyboard(unsigned char key, int x, int y) {
    MyWindow::getInstance()->keyboard(key, x, y);
}


unsigned int defaults(unsigned int displayMode, int &width, int &height) {return displayMode;}
