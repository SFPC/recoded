void draw() {
    for (square in squares) {
        // Add curves to random lines
        if (random() > [[pctJitter]]) {
            addJitter([[maxOffset]]);
        }
        
        // Randomly move some squares around
        setAnimatedTranslationAmount([[maxTranslation]]);
        
        drawSquare(square.size);
    }
}