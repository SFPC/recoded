void update() {
  // Move the camera and look at the middle of the screen
  camera.setPosition(ofVec3f([[cameraRotationX]], [[cameraRotationY]], [[cameraRotationZ]]));
  camera.lookAt(ofVec3f(0, 0, 0));
  camera.setDistance([[cameraZoom]]);

  // 0 is clear, 255 is opaque
  text1.setOpacity([[text1Opacity]]);
  text2.setOpacity([[text2Opacity]]);
  text1Plane.setOpacity([[text1PlaneOpacity]]);
  text2Plane.setOpacity([[text2PlaneOpacity]]);

  // Draw the text in space!
  text1.draw();
  text2.draw();
  text1Plane.draw();
  text2Plane.draw();
}
