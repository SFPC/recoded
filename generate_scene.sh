#!/bin/bash

addAfterPlaceholder (){
sed -i '' "s/\(\/\/$1.*$\)/$2\\`echo -e '\n\r'`\1/g" $3
}
addBeforePlaceholder (){
sed -i '' "s/\(\/\/$1.*$\)/\1\\`echo -e '\n\r'`$2/g" $3
}

if [ $# -eq 1 ]
then
    SCENE_NAME="$1"
    cp -r bin/data/scenes/emptyScene "bin/data/scenes/$SCENE_NAME"
    mkdir "src/scenes/$SCENE_NAME"
    sed "s/emptyScene/$SCENE_NAME/g" src/scenes/emptyScene/emptyScene.h > "src/scenes/$SCENE_NAME/$SCENE_NAME.h"
    sed "s/emptyScene/$SCENE_NAME/g" src/scenes/emptyScene/emptyScene.cpp > "src/scenes/$SCENE_NAME/$SCENE_NAME.cpp"
    addAfterPlaceholder "SCRIPT_PLACEHOLDER_INCLUDE" "\#include \"$SCENE_NAME.h\"" src/scenes/sceneManager.cpp
	addBeforePlaceholder "SCRIPT_PLACEHOLDER_PUSH_SCENE" "    scenes.push_back(new $SCENE_NAME());" src/scenes/sceneManager.cpp
else
    echo "Usage: ./generate_scene.sh sceneName"
fi