font.load("Helvetica Neue", 60);

background(251, 241, 229);

Color cyan(167, 200, 250);
Color magenta(235, 173, 137);
Color yellow(249, 235, 106);

enableBlendMode(MULTIPLY);
setColor(cyan);
font.drawString("BAUHAUS", 10, 504 - [[displacement]] * 1);
font.drawString("BAUHAUS", 10, 504 - [[displacement]] * 2);

setColor(magenta);
font.drawString("BAUHAUS", 10, 504 - [[displacement]] * 3);
font.drawString("BAUHAUS", 10, 504 - [[displacement]] * 4);

setColor(yellow);
font.drawString("BAUHAUS", 10, 504 - [[displacement]] * 5);
font.drawString("BAUHAUS", 10, 504 - [[displacement]] * 6);

disableBlendMode();
