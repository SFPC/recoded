
for (int layer = 0; layer < burger.size(); layer++) {
    layer = burger.getLayer(i);
    float xOffset = random(layer.width);
    float yOffset = random(layer.height);
    
    layer.translate(xOffset, yOffset);
    layer.rotateZ([[chaos]] * random(-50, 50));
    layer.rotateY([[chaos]] * random(-50, 50));
    layer.draw();
}
