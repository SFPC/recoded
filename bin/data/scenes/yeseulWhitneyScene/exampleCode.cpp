drawParticles() {
  // draw particles for the background and make the particles spin
  for (int r=0; r<width; r+=1) {
    ofRotate([[spinSpeed]]*sin(r)*elapsedTime);
    for (int a=0; a<20; a+=1) {
      ofRotate(360/20);
      ofDrawCircle(0, r*10, 1);
    }
  }
}

drawDiffusion() {
  // draw an expanding circle particles every [[diffusionInterval]] seconds
  if ([[diffusionInterval]] <= elapsedTime - lastDiffusionTime) {
    diffusion.push_back(circlesDiffusion(elapsedTime, [[diffusionSize]]));
  }
}
