void draw(){
    float time = GetElapsedSeconds();
    float n = Noise([[Noise Scale]]*time);
    SetColor(ColorFromHsb(n*255,255,255));
    PushMatrix();
    TranslateToCenter();
    
    for (int i = 0; i < 2000; i++){
        NoFill();
        Rotate(time*[[Rotate]]);
        DrawCircle(i, i, 80 + sin(time * [[Speed]]) * [[Oscilation Scale]]);
    }
    PopMatrix();
}