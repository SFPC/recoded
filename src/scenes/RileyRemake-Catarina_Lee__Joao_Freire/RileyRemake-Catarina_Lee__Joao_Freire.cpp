
#include "RileyRemake-Catarina_Lee__Joao_Freire.h"
#define NUM_COLORS 5
void RileyRemake_Catarina_Lee__Joao_Freire::setup(){
  
// setup pramaters
//    param.set("param", 5, 0, 100);
//    parameters.add(param);
    
    ofEnableAlphaBlending();
    
    for(int i = 0; i < 7; i++)
    {
        colors.push_back(ofParameter<ofColor>());
        parameters.add(colors.back().set("color"+ofToString(i), ofColor(100,100,140), ofColor(0,0),ofColor(255,255)));
    }
    
    for(int j = 0; j < 18; j++)
    {
        ofColor auxColor = colors[ofRandom(0,7)];
        
        stripe1.clear();
        for(int i = 0; i < 7; i ++)
        {
            vertical_stripe *aux;
            aux = new vertical_stripe();
            aux->create(j * 60, -j*30+ i*7*30, auxColor);
            stripe1.push_back(aux);
        }
        stripes.push_back(stripe1);
    }
    
    int nFloating = ofRandom(400,500);
    cell aux;
    
    for(int i = 0; i < nFloating; i++)
    {
        int x = ofRandom(17);
        int y = ofRandom(4);
        int num_cell = ofRandom(7);
        aux.create(stripes[x][y]->cells[num_cell]->origin.x + 1*17*60,  stripes[x][y]->cells[num_cell]->origin.y-30*30,"diagonal", colors[ofRandom(7)]);
        floating_cells.push_back(aux);
    }
    

    loadCode("scenes/RileyRemake-Catarina_Lee__Joao_Freire/exampleCode.cpp");
}

void RileyRemake_Catarina_Lee__Joao_Freire::update(){
    ofBackground(0, 0, 0);
    for(int j = 0; j < stripes.size(); j++)
    {
        for(int i = 0; i < stripes[j].size(); i ++)
        {
            stripes[j][i]->update();
            if(stripes[j][i]->cells[0]->origin.y > ofGetHeight() + stripes[j][i]->cells[0]->size.y * .8)
            {
                stripes[j][i]->moveUp(stripes[j][i]->cells[0]->origin.y - 6*7*30);
                stripes[j][i]->color = colors[ofRandom(0,7)];
            }
        }
    }
    
    for(int i = 0; i < floating_cells.size(); i++)
    {
        floating_cells[i].update();
        if(floating_cells[i].origin.y > ofGetHeight() + floating_cells[i].size.y || floating_cells[i].origin.x < -60)
        {
            int x = ofRandom(20);
            int y = ofRandom(15);
            int num_cell = ofRandom(7);
            floating_cells[i].origin += ofPoint((18 + x)*60, -(6 + y)*7*30);
            floating_cells[i].color = colors[ofRandom(0,7)];
            
        }
    }
}

void RileyRemake_Catarina_Lee__Joao_Freire::draw(){
    for(int j = 0; j < stripes.size(); j++){
        for(int i = 0; i < stripes[j].size(); i++)
        {
            stripes[j][i]->draw();
        }
    }
    for(int i = 0; i < floating_cells.size(); i++){
        floating_cells[i].draw();
    }
}
