// Time Paint by John Maeda
// 1990
//

TimePainters = createTimePainters(50);
currentPainter = 0;

if(TimePainters[currentPainter].isStillAlive?()){
  updateCurrentPainter();
} else {
  resetCurrentPainter();
}

if(currentPainter < 50){
  currentPainter++;
} else {
  currentPainter = 0;
}
