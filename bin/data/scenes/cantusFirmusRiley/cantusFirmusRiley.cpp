void draw(){
  translateX([[offsetX]]);
  scaleX([[zoom]]);

  for (stripe in stripes) {
    setColor(stripe.color);
    stripe.draw();
  }
}
