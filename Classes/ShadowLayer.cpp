#include "ShadowLayer.h"

USING_NS_CC;

// on "init" you need to initialize your instance
bool ShadowLayer::init() {
    if (!LayerColor::initWithColor(Color4B(0, 0, 0, 180))) {
        return false;
    }

    _lightShaderProgram = GLProgram::createWithFilenames("res/shaders/vertexShader.vert", "res/shaders/fragmentShader.frag");
    setGLProgram(_lightShaderProgram);
    
    _lightSize = 0.0;
    _lightPosition = Point(0, 0);

    return true;
}

void ShadowLayer::setLightPosition(Point pos) {
    _lightPosition = pos;
}

void ShadowLayer::setLightSize(float size) {
    _lightSize = size;
}

void ShadowLayer::draw(Renderer *renderer, const Mat4 &transform, uint32_t flags) {
    LayerColor::draw(renderer, transform, flags);
    _lightShaderProgram->use();
    
    GLuint position = glGetUniformLocation(_lightShaderProgram->getProgram(), "position");
    _lightShaderProgram->setUniformLocationWith2f(position, _lightPosition.x, _lightPosition.y);
    
    GLuint lightSize = glGetUniformLocation(_lightShaderProgram->getProgram(), "lightSize");
    _lightShaderProgram->setUniformLocationWith1f(lightSize, _lightSize);
}