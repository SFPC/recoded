#!/bin/bash

if [ $# -eq 1 ]
then
    SCENE_NAME="$1"
    cp -r bin/data/scenes/emptyScene "bin/data/zzScenes/$SCENE_NAME"
    mkdir "src/zzScenes/$SCENE_NAME"
    sed "s/emptyScene/$SCENE_NAME/g" src/scenes/emptyScene/emptyScene.h > "src/zzScenes/$SCENE_NAME/$SCENE_NAME.h"
    sed "s/emptyScene/$SCENE_NAME/g" src/scenes/emptyScene/emptyScene.cpp > "src/zzScenes/$SCENE_NAME/$SCENE_NAME.cpp"
else
    echo "Usage: ./generate_zz_scene.sh sceneName"
fi
