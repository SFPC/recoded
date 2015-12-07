draw_circles(centerX, centerY, radius, time = [[Current Time]], size = [[Current Size]], currentIteration){
    for (int i =0; i < numCircles; i++) {
        float angle = TWO_PI*(i/[[Number Of Circles]]) + time;
        if (currentIteration < [[Iterations]]) {
            drawCircles(centerX+ radius*sin(angle),
                        centerY+ radius*cos(angle),
                        [[Current Size]]*2,
                        [[Current Time]]/2,
                        radius/2*(1+sin([[Current Time]]) * [[Grow Factor]] * 2),
                        [[Number Of Circles]]*2,
                        currentIteration+1);
        }else{
            ofDrawCircle(centerX+ radius*sin(angle),
                         centerY+ radius*cos(angle),
                         size);
        }
    }
}