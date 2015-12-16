
/*
Recoding of "Untitled 7" by Belfort Group, 1976
When the code starts it draws the original artwork.
When the SPACE is pressed the animation mode is turned on, generating variations
Press up / down / to change the probability of a different line to be created 
and left / right to change the speed
*/

//display size
int w = 750;
// if the screen is 750, adjust is 6.4. if screen = 750/2, adjust is 3.2
float adjust = 6.4;
//background color;
int back=25;

//number of columns and row
int col=75;
int row=47;

//size os each square
float rectW=w/75;

//keep trackk of the cell number
int totalCount=0;

//probability of a different new line
float ran;
float prob=0.1;

int [][] dots = new int [col][row+1];

//original sequences
int [] origA = {1,1,1,1,1,0,1,1,1,0,0,1,0,1,1,0,1,1,0,1,1,1,0,1,0,0,0,0,1,0,0,1,0,0,0,1,0,1,1,1,0,1,0,0,0,0,1,0,0,1,0,1,0,0,0,0,0,1,0,1,1,0,0,1,0,0,0,1,0,0,0,0,0,0,0};
int [] origB = {0,1,0,1,0,0,0,0,0,0,0,0,0,1,1,0,0,1,0,0,1,0,1,0,1,1,0,1,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,1,0,1,0,0,0,1,1,1,0,1,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1};
int [] origC = {0,0,0,0,1,1,0,0,0,1,1,0,0,0,0,0,1,1,0,1,0,1,1,1,0,0,0,1,0,1,0,1,0,0,1,0,1,1,0,0,0,0,1,1,1,1,1,1,0,1,0,0,0,0,1,0,1,0,1,1,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0};

int [] newLine = new int [75];

//starts/spots the creation of variations of the original artwork
boolean generate=false;

//frameRate
int rate = 8;

void setup (){
  
size(750,750); 
fill (255);
stroke(back);
strokeWeight(2);
background(back);
frameRate(rate);

// draw original artwork seqeuence
original ();
}





void draw (){

if(generate) Generate();

frameRate(rate);
  
}




 //create variations of the orginal artwork 

void Generate(){
// println("generating");

//drawing the current sequence
for (int i=0; i<col;i++){
for (int j=0;j<row;j++){

  if(dots[i][j]==1)fill (255);
  if(dots[i][j]==0)fill (back);
  rect(rectW*i,rectW*j+(j*adjust),rectW,rectW);  
 
  }
  }

//STEP : animating the lines down the screen. the line in the row 0 goes to 1, etc...
 for (int i=0; i<col;i++){ 
  arrayCopy(dots[i], 0, dots[i], 1, 45);
 }
 
 //contraning the possibilities of creating a diferent line. 10%. for new line 90% for the same
ran=random(1);

if(ran<prob){

 
 //creating new sequences in the first line, to animate the sequences
  for (int i=0; i<col;i++){ 
 // ran=round(random(1));
  dots[i][0]=round(random(1));
 }
 
}
 
}

//////////////////////////////////////////////////////////

void keyPressed () {

//If space is pressed generate a new sequence  
   if ( key == ' ') {
     generate=!generate;
   }

//up and down keys, change the probability of a different line to be created 
if (key == CODED) {
    if (keyCode == UP) {
    if(prob<=1.0)prob=prob+0.1;
      }
      
          if (keyCode == DOWN) {
    if(prob>=0.0)prob=prob-0.1;
      }

//CHANGING SPEED      
     if (keyCode == RIGHT) {
     
       if(rate<=40) rate=rate+4;
     } 
     
          if (keyCode == LEFT) {
     
       if(rate>=5) rate=rate-4;
     } 
      
 }
// println ("prob-"+prob+" "+"velocity-"+rate);
   
}

///////////////////////////////////////////////////////////

// DRAWING THE ORIGINAL ARTWORK SEQUENCE
void original (){
  
  for (int i=0; i<col;i++){
  for (int j=0;j<row;j++){
   if(j<5){
    if(origA[totalCount]==1)fill (255);
    if(origA[totalCount]==0)fill (back);
    rect(rectW*i,rectW*j+(j*adjust),rectW,rectW); 
  dots[i][j]=origA[totalCount];   
   }   
   if(j>=5 && j<29){
     if(origB[totalCount]==1)fill (255);
     if(origB[totalCount]==0)fill (back);
     rect(rectW*i,rectW*j+(j*adjust),rectW,rectW);
   dots[i][j]=origB[totalCount];  
   }  
      if(j>=29){
     if(origC[totalCount]==1)fill(255);
     if(origC[totalCount]==0)fill(back);
     rect(rectW*i,rectW*j+(j*adjust),rectW,rectW);  
     
     dots[i][j]=origC[totalCount];
     
   }   
  }
  totalCount++;
 } 
  
}
