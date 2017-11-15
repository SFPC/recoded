creationDelay = ofMap([[jiggle]], 0.05, 0.25, 0.9, 0.03);

int cloud_width = [[cloud_size]];
int cloud_height = cloud_width*.72;

if (timeSinceLastEmoji > creationDelay){
    total_emojis += 1;
    Emoji temp;
    int index = ofRandom(0,icons.size());
    temp.setup(center_x+ofRandom(-cloud_width/2*.9,cloud_width/2*.6), center_y, &icons[index]);
    temp.emojiSize = ofMap(cloud_size, 50, 700, 0.1, 0.5);
    my_emojis.push_back(temp);
    lastCreationTime = getElapsedTimef();
}

for (int i=0;i<my_emojis.size();i++){
    my_emojis[i].draw();
}
