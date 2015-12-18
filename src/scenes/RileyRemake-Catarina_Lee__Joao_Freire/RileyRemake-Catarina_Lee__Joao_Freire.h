#pragma once

#include "ofMain.h"
#include "baseScene.h"


struct cell
{
    void create(int _x, int _y, string _direction, ofColor _color)
    {
        origin.set(_x, _y);
        size.set(60,30);
        direction = _direction;
        color = _color;
    }
    
    void draw()
    {
        ofFill();
        ofSetColor(color.r, color.g, color.b, color.a);
        
        glBegin(GL_QUADS) ;
        ofPoint aux;
        
        
        glVertex2f(origin.x, origin.y) ;
        aux.x = origin.x + size.x;
        aux.y = origin.y - size.y ;
        glVertex2f(aux.x, aux.y) ;
        aux += ofPoint(0,size.y);
        glVertex2f(aux.x, aux.y) ;
        aux += ofPoint(-size.x,  size.y);
        glVertex2f(aux.x, aux.y) ;
        glEnd() ;
    }
    
    void update()
    {
        if(direction == "down")
        {
            origin.y += 1;
        }
        else
        {
            origin.y += 1.5;
            origin.x -= 1;
        }
    }
    
    ofPoint origin;
    ofPoint size;
    string direction;
    ofColor color;
    
};

struct vertical_stripe
{
    void create(int _x, int _y, ofColor _color)
    {
        color = _color;
        
        for(int i = 0; i < 7; i++)
        {
            cell* aux;
            aux = new cell();
            aux->create(_x, _y + i*30, "down", color);
            cells.push_back(aux);
        }
    }
    
    void moveUp(int _y)
    {
        cells[0]->origin.y = _y;
        for (int i = 0; i < cells.size(); i++)
        {
            cells[i]->origin.y = cells[0]->origin.y + i*30;
        }
    }
    
    void update()
    {
        for(int i = 0; i < cells.size(); i++)
        {
            cells[i]->color = color;
            cells[i]->update();
        }
    }
    
    void draw()
    {
        for(int i = 0; i < cells.size(); i++)
        {
            cells[i]->draw();
        }
    }
    
    vector<cell*> cells;
    ofColor color;
};


class RileyRemake_Catarina_Lee__Joao_Freire : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();
    vector <ofParameter<ofColor> > colors;
    
    vector<vertical_stripe*> stripe1, stripe2, stripe3, stripe4;
    
    vector< vector <vertical_stripe*> > stripes;
    
    vector<cell> floating_cells;
//    ofParameter<float> param;
};
