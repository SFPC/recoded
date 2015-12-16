currentPainter = [[currentPainter]];

Class TimePainter {
  float [[currentPainterX]], [[currentPainterY]];

  void update(){
    if(this.painter.isAlive()){
      this.painter.keepDrawing();
    } else {
      this.painter.explode();
      this.painter.explode();
    }
  }
}
