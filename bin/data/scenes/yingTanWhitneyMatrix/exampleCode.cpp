
draw() {
    time += timePerFrame() * [[time_scale]];

    hexagon1.draw(time);
    hexagon2.draw(time + 3);
    hexagon3.draw(time + 8);

    hexagon1.spacing = [[spacing]]
    hexagon2.spacing = [[spacing]]
    hexagon3.spacing = [[spacing]]
}
