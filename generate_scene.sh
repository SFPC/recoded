#!/bin/bash

if [ $# -eq 1 ]
then
    SCENE_NAME="$1"
    cp -r bin/data/emptyScene "bin/data/$SCENE_NAME"
    sed "s/emptyScene/$SCENE_NAME/g" src/scenes/emptyScene.h > "src/scenes/$SCENE_NAME.h"
    sed "s/emptyScene/$SCENE_NAME/g" src/scenes/emptyScene.cpp > "src/scenes/$SCENE_NAME.cpp"
else
    echo "Usage: ./generate_scene.sh sceneName"
fi