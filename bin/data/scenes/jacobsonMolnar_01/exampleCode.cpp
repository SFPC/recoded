vector<Triangle> triangles = delaunay.getTriangles();
for (Triangle triangle : triangles) {    
    //    A
    //    |\
    //    | \
    //  c |  \ b
    //    |   \
    //    |    \
    //    B-----C
    //       a
    // a + b + c
    float perimeter = triangle.getPerimeter();
    // sqrt(s * (s - a) * (s - b) * (s - c))
    float area = triangle.getArea();
    // (a * A + b * B + c * C) / perimeter
    point incenter = triangle.getIncenter();
    // 2 * area / perimeter
    float inscribedRadius = triangle.getInscribedRadius;
    
    float noiseValue = noise([[noiseResolution]] * incenter, 
                          [[timeScale]] * time);
    // how to fill triangle
    float stepSize = map(noiseValue, 0, 1, 
                         [[stepSizeMin]], [[stepSizeMax]]);
    for (float n = stepSize; n < inscribedRadius; n += stepSize) {
        
        float scale = inscribedRadius / (inscribedRadius - n);
        Triangle t = triangle.getHomotheticTransform(incenter, scale);
        t.draw();
    }
}