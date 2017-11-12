
img.resize([[imageSize]], [[imageSize]]);

for (int n = 1; n < countLevels; n++) {
    for (int i = 0; i < n; i++) {
        float r = framePad * min(w / 2, h / 2) * n / countLevels;
        float t = map(i, 0, n, 0, 2 * PI) +
        ([[rotationSpeed]] * n / countLevels) * 
        (time + noise(n / countLevels, 0.2 * time, 0.2 * time)
        + [[phaseShift]]);
        float x = r * cos(t) + (1 - n / countLevels)
         * sin(time + 5 * PI * n / countLevels);
        float y = r * sin(t) + (1 - n / countLevels) 
        * cos(time + 5 * PI * n / countLevels);
        setColor(127 + 0.01 * (n * i) + 80 * cos(0.6 * time),
        		 127 + 0.02 * (n * i) + 50 * cos(0.4 * time + 1),
        		 127 + 0.9 * (n * i), 255);
        drawCircle(x, y);
        img.draw(x, y);
    }
}