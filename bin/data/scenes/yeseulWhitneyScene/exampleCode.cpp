drawParticles() {
  // draw particles for the background and make the particles spin
  for (int r=0; r<width; r+=1) {
    rotate([[spinSpeed]]*sin(r)*elapsedTime);
    for (int a=0; a<20; a+=1) {
      rotate(360/20);
      circle(0, r*10, 1);
    }
  }
}

drawDiffusion() {
  // draw expanding circle particles every [[diffusionInterval]] seconds
  if ([[diffusionInterval]] <= totalTime - lastDiffusionTime) {
    for (int a=0; a<360; a+=10) {
      rotate(10);
      circle(0, y, [[diffusionSize]]);
    }
  }
}
