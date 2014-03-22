//
//  Terrain.cpp
//  kunonekonok
//
//  Created by damingdan on 14-3-21.
//
//

#include "Terrain.h"

Terrain::Terrain() {}

Terrain::~Terrain() {}

bool Terrain::init() {
    if (Node::init()) {
        return true;
    }else {
        return false;
    }
}

Sprite* Terrain::spriteWithColor(Color4F color, float width, float height) {
    // 1: Create new RenderTexture
    auto texture = RenderTexture::create(width, height);
    
    // 2: Call RenderTexture:begin
    texture->beginWithClear(color.r, color.g, color.b, color.a);
    
    // 3: Draw into the texture
    this->setShaderProgram(ShaderCache::getInstance()->getProgram(GLProgram::SHADER_NAME_POSITION_COLOR));
    CC_NODE_DRAW_SETUP();
    
    float gradientAlpha = 0.7f;
    Point vertices[4];
    Color4F colors[4];
    int verticesNumber = 0;
    vertices[verticesNumber] = Point(0, 0);
    colors[verticesNumber ++] = Color4F(0, 0, 0, 0);
    vertices[verticesNumber] = Point(width, 0);
    colors[verticesNumber ++] = Color4F(0, 0, 0, 0);
    vertices[verticesNumber] = Point(0, height);
    colors[verticesNumber ++] = Color4F(0, 0, 0, gradientAlpha);
    vertices[verticesNumber] = Point(width, height);
    colors[verticesNumber ++] = Color4F(0, 0, 0, gradientAlpha);
    
    GL::enableVertexAttribs(GL::VERTEX_ATTRIB_FLAG_POSITION | GL::VERTEX_ATTRIB_FLAG_COLOR);
    glVertexAttribPointer(GLProgram::VERTEX_ATTRIB_POSITION, 2, GL_FLOAT, GL_FALSE, 0, vertices);
    glVertexAttribPointer(GLProgram::VERTEX_ATTRIB_COLOR, 4, GL_FLOAT, GL_FALSE, 0, colors);
    glBlendFunc(CC_BLEND_SRC, CC_BLEND_DST);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, (GLsizei)verticesNumber);
    
    
    auto noise = Sprite::create("Noise-iphone5hd.png");
    noise->setBlendFunc((BlendFunc){GL_DST_COLOR, GL_ZERO});
    noise->setPosition(width/2, height/2);
    noise->visit();
    
    // 4: Call CCRenderTexture:end
    texture->end();
    
    // 5: Create a new Sprite from the texture
    return Sprite::createWithTexture(texture->getSprite()->getTexture());
}

Sprite* Terrain::stripedSpriteWithColor(Color4F foregroundColor, Color4F backgroundColor, float width, float height, int stripCount) {
    RenderTexture* texture = RenderTexture::create(width, height);
    texture->beginWithClear(backgroundColor.r, backgroundColor.g, backgroundColor.b, backgroundColor.a);
    
    
    this->setShaderProgram(ShaderCache::getInstance()->getProgram(GLProgram::SHADER_NAME_POSITION_COLOR));
    CC_NODE_DRAW_SETUP();
    
    // layer strips
    // ready the points
    Vertex2F* vertices = new Vertex2F[stripCount*6];
    Color4F* colors = new Color4F[stripCount*6];
    
    int verticeIndex = 0;
    float x1 = -height;
    float x2;
    float y1 = height;
    float y2 = 0;
    float dx = width/stripCount*2;
    float stripWidth = dx/2;
    for (int i = 0; i < stripCount; ++i) {
        x2 = x1 + height;
        
        vertices[verticeIndex] = Vertex2F(x1, y1);
        colors[verticeIndex ++] = Color4F(foregroundColor.r, foregroundColor.g, foregroundColor.b, foregroundColor.a);
        
        vertices[verticeIndex] = Vertex2F(x1 + stripWidth, y1);
        colors[verticeIndex ++] = Color4F(foregroundColor.r, foregroundColor.g, foregroundColor.b, foregroundColor.a);
        
        vertices[verticeIndex] = Vertex2F(x2, y2);
        colors[verticeIndex ++] = Color4F(foregroundColor.r, foregroundColor.g, foregroundColor.b, foregroundColor.a);
        
        vertices[verticeIndex] = vertices[verticeIndex - 2];
        colors[verticeIndex ++] = Color4F(foregroundColor.r, foregroundColor.g, foregroundColor.b, foregroundColor.a);
        
        vertices[verticeIndex] = vertices[verticeIndex - 2];
        colors[verticeIndex ++] = Color4F(foregroundColor.r, foregroundColor.g, foregroundColor.b, foregroundColor.a);
        
        vertices[verticeIndex] = Vertex2F(x2 + stripWidth, y2);
        colors[verticeIndex ++] = Color4F(foregroundColor.r, foregroundColor.g, foregroundColor.b, foregroundColor.a);
        
        x1 += dx;
    }
    GL::enableVertexAttribs(GL::VERTEX_ATTRIB_FLAG_POSITION | GL::VERTEX_ATTRIB_FLAG_COLOR);
    glVertexAttribPointer(GLProgram::VERTEX_ATTRIB_POSITION, 2, GL_FLOAT, GL_FALSE, 0, vertices);
    glVertexAttribPointer(GLProgram::VERTEX_ATTRIB_COLOR, 4, GL_FLOAT, GL_TRUE, 0, colors);
    //glBlendFunc(CC_BLEND_SRC, CC_BLEND_DST);
    glDrawArrays(GL_TRIANGLES, 0, (GLsizei)verticeIndex);
    CC_SAFE_DELETE_ARRAY(vertices);
    CC_SAFE_DELETE_ARRAY(colors);
    
    // layer noise
    auto noise = Sprite::create("Noise-iphone5hd.png");
    noise->setBlendFunc((BlendFunc){GL_DST_COLOR, GL_ZERO});
    noise->setPosition(width/2, height/2);
    noise->visit();
    
    texture->end();
    return Sprite::createWithTexture(texture->getSprite()->getTexture());
}



Color4F Terrain::randomBrightColor() {
    while (true) {
        float requiredBrightness = 192;
        Color4B randomColor = Color4B(arc4random() % 255,
                                      arc4random() % 255,
                                      arc4random() % 255,
                                      255);
        if (randomColor.r > requiredBrightness ||
            randomColor.g > requiredBrightness ||
            randomColor.b > requiredBrightness) {
            return Color4F(randomColor);
        }
    }
}

void Terrain::genBackground() {
    if(background != NULL && background != nullptr) {
        background->removeFromParent();
    }
    Color4F foregroundColor = this->randomBrightColor();
    Color4F backgroundColor = this->randomBrightColor();
    int stripCount = ((rand() % 4) + 1) * 2;
    //background = this->spriteWithColor(color, this->getContentSize().width, this->getContentSize().height);
    background = this->stripedSpriteWithColor(foregroundColor, backgroundColor, this->getContentSize().width, this->getContentSize().height, stripCount);
    //background->setScale(0.5f);
    this->addChild(background);
}