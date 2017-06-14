void setup() {
  string completeText = openTextFile("MurielCooperLetter.txt");
  vector<string> splitText = splitStringByParagraph(completeText);
  for(text in splitText) {
    3dText t;
    t.setText(text);
    t.setHsbColor(random(255), random(230, 255), random(180, 255));
    t.setFont("Helvetica Neue");
    vec3 axis;
    int sign = randomInt(0,1);
    axis[randomInt(0, 2)] = (sign == 0)?-1:1;
    t.rotate(random([[min angle]], [[max angle]], axis);
    t.move(prevText.width, 0,0);
    t.setParent(3dTexts.back());
    3dTexts.add(t);
  }
}
void draw(){
  if(3dTexts[currentText].getNumberOfWords() * [[Pause Duration]]
     < getElapsedTime - lastTextTime){
    camera.tweenToLookAt(3dTexts[currentText], [[Tween Duration]],
                         easeInOut, EXPONENTIAL_EASING);
    currentText = wrap(currentText+1, 0, 3dTexts.size());
    lastTextTime = getElapsedTime;
  }
  camera.begin();
  3dTexts[currentText].draw();
  camera.end();
}
