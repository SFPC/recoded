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
    
    // how to fill triangle
    float stepSize = map(noise([[noiseResolution]] * incenter, [[timeScale]] * time), 0, 1, [[stepSizeMin]], [[stepSizeMax]]);
    
    for (float n = stepSize; n < inscribedRadius; n += stepSize) {
        
        float scale = inscribedRadius / (inscribedRadius - n);
        
        Triangle transform = triangle.getHomotheticTransform(incenter, scale);
        
        transform.draw();
    }
}
