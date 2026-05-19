#ifndef VBOCUBE_H
#define VBOCUBE_H

class VBOCube
{

private:
    unsigned int vaoHandle;

public:
    VBOCube();

    void init();
    void render();
};

#endif // VBOCUBE_H
