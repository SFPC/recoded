void draw(){
    for (int h = 0; h < 40; h++){
        Polyline myLine;
        for (int i = 0; i < 80; i++){          
            float yDown = Random([[height]]);
            float yUp = Random(20);
            float xForward = Random([[width]]);
            float xBack = Random(10);
            
            float pct = Map(i*(h*500*0.01), 0, 1000, 0, 1); 
            
            if (i % 2 == 0){

                float x = xBack + i * [[length]] + 
                	Random(-[[emotion]]*10*h*0.3, 
                	[[emotion]]*10*h*0.3);

                float y = -yDown + (i*0) + h * vertSpacer;
                myLine.addVertex(x,y);
            } else {
                float x = xBack + xForward + i * [[length]] + 
                	Random(-[[emotion]]*10*h*0.3,
                	[[emotion]]*10*h*0.3); 
                float y = yDown + (i*0) +  h * vertSpacer;
                myLine.addVertex(x,y);
            }
        myLine.draw();
        }
    }