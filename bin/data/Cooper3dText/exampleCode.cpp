float [[tweenVal]] = tween.update();
if (tween.isTweening()) {
    ofQuaternion q;
    q.slerp([[tweenVal]], [[camStartOrientation]], [[camEndOrientation]]);
    cam.setPosition([[camPos]]));
    cam.setOrientation([[camOrientation]]);
}