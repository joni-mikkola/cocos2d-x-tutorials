#ifndef __SHADOWLAYER_H__
#define __SHADOWLAYER_H__

#include "cocos2d.h"

USING_NS_CC;

class ShadowLayer : public LayerColor {
private:
    GLProgram* _lightShaderProgram;
    Point _lightPosition;
    float _lightSize;
public:
    virtual bool init();
    CREATE_FUNC(ShadowLayer);
    
    void setLightPosition(Point pos);
    void setLightSize(float size);
    
    virtual void draw(Renderer *renderer, const Mat4 &transform, uint32_t flags);
};

#endif
