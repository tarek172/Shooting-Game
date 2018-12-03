// rahman , md. rubel 15-28447-1
// barnile, modhubroty Dey 15-28492-1

#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include<sstream>
#include <string>
#include<string.h>
#include<windows.h>
#include<mmsystem.h>
#define GAME_SCREEN 0
#define MENU_SCREEN 4

using namespace std;

int flag,flag2;
float speed=0.06f;///obj1
float speed2=0.0f;///bullet y
float speed3=0.04f;///obj2
float speed4=0.08f;///obj3
float speed5=0.1f;///bulet x
float speed6=0.03f;///obj4
float speed7=0.09f;///obj5


int point=0;
int cnt=0;
int life=20;


float birdbodyx1=2.0;
float birdbodyx2=2.40;
float birdbodyy1=1.0;
float birdbodyy2=1.15;

float birdbody2x1=2.0;
float birdbody2x2=2.40;
float birdbody2y1=2.0;
float birdbody2y2=2.15;

float birdbody3x1=3.0;
float birdbody3x2=3.40;
float birdbody3y1=1.5;
float birdbody3y2=1.65;

float birdbody4x1=2.0;
float birdbody4x2=2.40;
float birdbody4y1=1.7;
float birdbody4y2=1.85;

float birdbody5x1=3.0;
float birdbody5x2=3.40;
float birdbody5y1=1.2;
float birdbody5y2=1.35;


float gunpipex1=-0.1,gunpipex2=0.1;


float buletx1=((gunpipex1+gunpipex2)/2)-.02;
float buletx2=((gunpipex1+gunpipex2)/2)+.02;


float bulety1=-2.0f;
float bulety2=-1.96f;


float _cloud = -10.0;
float _cameraAngle = 0.0;
float _ang_tri = 0.0;


GLint m_viewport[4];
float mouseX ,mouseY ;
bool mButtonPressed= false,startGame=false,gameOver=false;
bool startScreen = true ;
bool gameQuit = false,instructionsGame = false, optionsGame = false;

bool fullScreenMode = true;

void drawScene();
void drawScene();
void GameScreenDisplay();
void GameOverScreen();

void check(float b)
{
    if(b>1 && buletx2>=birdbodyx1 && buletx1<birdbodyx2 && b<1.15)
    {

        cout<<"detedted" << buletx1 <<endl;
        birdbodyx1=8.0f;
        birdbodyx2=8.40f;
        cnt++;

    }

    if(b>2 && buletx2>=birdbody2x1 && buletx1<birdbody2x2 && b<2.15)
    {
        cout<<"detedted" << buletx1 <<endl;
        birdbody2x1=8.0f;
              birdbody2x2=8.40f;
      cnt++;

    }
    if(b>1.5 && buletx2>=birdbody3x1 && buletx1<birdbody3x2 && b<1.65)
    {
        cout<<"detedted" << buletx1 <<endl;
        birdbody3x1=8.0f;
        birdbody3x2=8.40f;
       cnt++;

    }

    if(b>1.7 && buletx2<=birdbody4x1 && buletx1>birdbody4x2 && b<1.85)
    {
        cout<<"detedted" << buletx1 <<endl;
        birdbody4x1=-8.0f;
        birdbody4x2=-8.40f;
       cnt++;

    }

    if(b>1.2 && buletx2<=birdbody5x1 && buletx1>birdbody5x2 && b<1.35)
    {
        cout<<"detedted" << buletx1 <<endl;
        birdbody5x1=-8.0f;
        birdbody5x2=-8.40f;
       cnt++;

    }

}


void displayRasterText(float x ,float y ,float z ,char *stringToDisplay) {
	int length;
	glRasterPos3f(x, y, z);
		length = strlen(stringToDisplay);

	for(int i=0 ;i<length ;i++){
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24 ,stringToDisplay[i]);
	}
}
void SetDisplayMode(int modeToDisplay) {
		switch(modeToDisplay){
		case GAME_SCREEN: glClearColor(1, 1, 1, 1);break;
		case MENU_SCREEN : glClearColor(0.000, 0.980, 0.604, 1);break;
	}
}

void startScreenDisplay()
{
	glLineWidth(50);
	SetDisplayMode(MENU_SCREEN);

	glColor3f(0.957, 0.643, 0.376);



	glLineWidth(1);

	glColor3f(1.000, 0.271, 0.000);
		glBegin(GL_POLYGON);				//START GAME PLOYGON
		glVertex3f(-0.8,1.0,0.05);
		glVertex3f(-0.8,1.3,0.05);
		glVertex3f(0.8,1.3,0.05);
		glVertex3f(0.8,1.0, 0.05);
	glEnd();


    glBegin(GL_POLYGON);				//INSTRUCTIONS POLYGON
		glVertex3f(-.8,0.5,.05);
		glVertex3f(-.8,.15,.05);
		glVertex3f(.8,.15,.05);
		glVertex3f(.8,.5, .05);
	glEnd();


	glBegin(GL_POLYGON);				//QUIT POLYGON
		glVertex3f(-.8,-.3,.05);
		glVertex3f(-.8,-.6,.05);
		glVertex3f(.8, -.6,.05);
		glVertex3f(.8, -.3,.05);
	glEnd();
	if(mouseX>=-0.15 && mouseX<=0.08 && mouseY>=0.04 && mouseY<=0.07){
		glColor3f(0.098, 0.098, 0.439) ;
		if(mButtonPressed){
			startGame = true ;
			gameOver = false;
			mButtonPressed = false;
		}
	} else
		glColor3f(0 , 0, 0);

	displayRasterText(-0.2,1.1,0.4 ,"Start Game");

	if(mouseX>=-0.15 && mouseX<=-0.08 && mouseY>=-.10 && mouseY<=-0.07) {
		glColor3f(0.098, 0.098, 0.439);
		if(mButtonPressed){
			instructionsGame = true ;
			mButtonPressed = false;
		}
	} else
		glColor3f(0 , 0, 0);
	displayRasterText(-0.3,.3,.4 ,"Instructions");

	if(mouseX>=-0.15 && mouseX<=-0.08 && mouseY>=-.25 && mouseY<=-.2){
		glColor3f(0.098, 0.098, 0.439);
		if(mButtonPressed){
			gameQuit = true ;
			mButtonPressed = false;
		}
	}
	else
		glColor3f(0 , 0, 0);
	displayRasterText(-.08,-.45,0.4 ,"Quit");

}
void backButton() {
	if(mouseX <=-0.15 && mouseX >= -0.24 && mouseY >= -.50 && mouseY <=-.45){
			glColor3f(0, 0, 1);
			if(mButtonPressed){
				mButtonPressed = false;
				instructionsGame = false;
				startScreenDisplay();
			}
	}
	else glColor3f(0, 0, 0);
	displayRasterText(-1.0,-2.0 ,0, "Back");
}

void InstructionsScreenDisplay()
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	SetDisplayMode(MENU_SCREEN);
	//colorBackground();
	glColor3f(0, 0, 0);

	displayRasterText(-2.500 ,1.20 ,0.4 ,"Key right to move right.");
	displayRasterText(-2.500 ,0.800 ,0.4 ,"Key left to move left.");
	displayRasterText(-2.500 ,.400 ,0.4 ,"Key 'a' For Shoot.");

	displayRasterText(-2.500 ,.000 ,0.4 ,"You Get 1 point for shooting each object");

   backButton();
	/*if(previousScreen)
		nextScreen = false ,previousScreen = false; //as set by backButton()*/


}



void sprint( float x, float y, string st)
{
    int l,i;
//    l=strlen( st ); // see how many characters are in text string.
    glColor3f(1.0,0.0,0.0);
    glRasterPos2f( x, y); // location to start printing text
    for( i=0; i <  st.length(); i++) // loop until i is greater then l
    {
       glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, st[i]);

    }
}


void drawbulet()
{

    glPushMatrix();
    glColor3ub(0,0,0);
	//glTranslatef(0.0f, ,0.0f);
    glBegin(GL_QUADS);
        glVertex3f(buletx1, bulety1, 0.0f);   //// 1st object
        glVertex3f(buletx2, bulety1, 0.0f);
        glVertex3f(buletx2, bulety2, 0.0f);
        glVertex3f(buletx1, bulety2, 0.0f);

	glEnd();
    glPopMatrix();

}


//Draws the 3D scene

void initRendering() {
	glEnable(GL_DEPTH_TEST);
}

//Called when the window is resized
void handleResize(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
}

void clouds(){



    glPushMatrix(); //Save the current state of transformations
	glTranslatef(-2.50,2.25,0); //Move to the center of the triangle
	glRotatef(0, 0.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)
	glBegin(GL_TRIANGLE_FAN);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=.20;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();

	glPushMatrix(); //Save the current state of transformations
	glTranslatef(-2.25,2.45,0); //Move to the center of the triangle
	glRotatef(0, 0.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)
	glBegin(GL_TRIANGLE_FAN);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=.25;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();


	glPushMatrix(); //Save the current state of transformations
	glTranslatef(-2.0,2.25,0); //Move to the center of the triangle
	glRotatef(0, 0.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)
	glBegin(GL_TRIANGLE_FAN);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=.20;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();

	glPushMatrix(); //Save the current state of transformations
	glTranslatef(-2.25,2.15,0); //Move to the center of the triangle
	glRotatef(0, 0.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)
	glBegin(GL_TRIANGLE_FAN);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=.20;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();

}




void drawgun()
{

     glPushMatrix(); //Save the transformations performed thus far
     glColor3ub(100,100,100);
     glBegin(GL_QUADS);
        glVertex3f(gunpipex1,-4.0, 0.0f);   //// 1st object
        glVertex3f(gunpipex2,-4.0, 0.0f);
        glVertex3f(gunpipex2,-2.0, 0.0f);
        glVertex3f(gunpipex1,-2.0, 0.0f);

	glEnd();

	glPopMatrix();


}




void drawbird(float x1,float y1,float x2,float y2)

{
    ///block1
    glPushMatrix();


    glBegin(GL_QUADS);
        glVertex3f(x1, y1, 0.0f);   //// 1st object
        glVertex3f(x2, y1, 0.0f);
        glVertex3f(x2, y2, 0.0f);
        glVertex3f(x1, y2, 0.0f);

	glEnd();
	  glPopMatrix();


}


void grass()
{
     glPushMatrix();
    glColor3ub(0,240,0);
    glTranslatef(-4.0,-2.5,0.0);
    glRotatef(100,-1.0,0.0,0.0);

    glutSolidCone(15,.01,5000,5000); //(GLdouble base, GLdouble height,GLint slices, GLint stacks);
    glPopMatrix();
}
void tree()
{
    glPushMatrix();
    glColor3ub(139,69,19);
    glTranslatef(-3.8,-1.2,0.0);
    glScalef(1.0,3.5,1.0);

    glutSolidCube(.4);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(34,139,34);
    glTranslatef(-3.8,-0.7,0.0);
    //glScalef(1.0,2.5,1.0);
    glRotatef(90,-1.0,0.0,0.0);
    glutSolidCone(.8,1.0,15,15);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(34,139,34);
    glTranslatef(-3.8,-0.3,0.0);
    //glScalef(1.0,2.5,1.0);
    glRotatef(90,-1.0,0.0,0.0);
    glutSolidCone(.6,1.0,15,15);
    glPopMatrix();

      glPushMatrix();
    glColor3ub(139,69,19);
    glTranslatef(3.8,-1.6,0.0);
    glScalef(1.0,3.5,1.0);

    glutSolidCube(.2);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(34,139,34);
    glTranslatef(3.8,-1.4,0.0);
    //glScalef(1.0,2.5,1.0);
    glRotatef(90,-1.0,0.0,0.0);
    glutSolidCone(.3,0.5,15,15);
    glPopMatrix();
     glPushMatrix();
    glColor3ub(34,139,34);
    glTranslatef(3.8,-1.2,0.0);
    //glScalef(1.0,2.5,1.0);
    glRotatef(90,-1.0,0.0,0.0);
    glutSolidCone(.3,0.5,15,15);
    glPopMatrix();

       glPushMatrix();
    glColor3ub(139,69,19);
    glTranslatef(3.1,-1.6,0.0);
    glScalef(1.0,3.5,1.0);

    glutSolidCube(.2);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(34,139,34);
    glTranslatef(3.1,-1.4,0.0);
    //glScalef(1.0,2.5,1.0);
    glRotatef(90,-1.0,0.0,0.0);
    glutSolidCone(.3,0.5,15,15);
    glPopMatrix();
     glPushMatrix();
    glColor3ub(34,139,34);
    glTranslatef(3.1,-1.2,0.0);
    //glScalef(1.0,2.5,1.0);
    glRotatef(90,-1.0,0.0,0.0);
    glutSolidCone(.3,0.5,15,15);
    glPopMatrix();

}



void sun()
{
    glPushMatrix(); //Save the current state of transformations
	glTranslatef(2.2,2.2,0); //Move to the center of the triangle
	glRotatef(0, 0.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)
	glBegin(GL_TRIANGLE_FAN);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=.30;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();
}

void GameScreenDisplay()
{
    ///1st target
     glPushMatrix();

     glColor3ub(0,0,0);
     drawbird(birdbodyx1,birdbodyy1,birdbodyx2,birdbodyy2);
    glPopMatrix();

     ///2nd target
     glPushMatrix();
     glColor3ub(255,0,0);
     drawbird(birdbody2x1,birdbody2y1,birdbody2x2,birdbody2y2);
     glPopMatrix();

     ///3rd target
     glPushMatrix();

     glColor3ub(0,255,0);
     drawbird(birdbody3x1,birdbody3y1,birdbody3x2,birdbody3y2);
     glPopMatrix();


       ///4th target
     glPushMatrix();

     glColor3ub(0,0,255);
     drawbird(birdbody4x1,birdbody4y1,birdbody4x2,birdbody4y2);
     glPopMatrix();

       ///5th target
     glPushMatrix();

     glColor3ub(0,255,255);
     drawbird(birdbody5x1,birdbody5y1,birdbody5x2,birdbody5y2);
     glPopMatrix();




      ///sun
      glPushMatrix();
     //glRotatef(30, 1.0, 1.0, 0.0);
     glColor3ub(240,0,0);
     glScalef(0.8,0.8,0.8);
     glTranslatef(0.0,0.5,0.0);

     sun();
     glPopMatrix();



     ///1st cloud
      glPushMatrix();
     //glRotatef(30, 1.0, 1.0, 0.0);
     glColor3ub(135,206,250);
     glScalef(0.5,0.8,0.9);
     glTranslatef(0.0,1.3,0.0);
     glTranslatef(_cloud,0.0,0.0);
     clouds();
     glPopMatrix();



     ///2nd cloud
      glPushMatrix();
     //glRotatef(30, 1.0, 1.0, 0.0);
     glColor3ub(135,206,250);
     glScalef(0.6,0.6,0.9);
     glTranslatef(0.0,1.2,0.0);
     glTranslatef(_cloud,0.0,0.0);
     clouds();
     glPopMatrix();


      ///3rd cloud
      glPushMatrix();
     //glRotatef(30, 1.0, 1.0, 0.0);
     glColor3ub(135,206,250);
     glScalef(0.9,0.5,0.9);
     glTranslatef(0.0,1.3,0.0);
     glTranslatef(_cloud,0.0,0.0);
     clouds();
     glPopMatrix();


     ///4th cloud
      glPushMatrix();
     //glRotatef(30, 1.0, 1.0, 0.0);
     glColor3ub(135,206,250);
     glScalef(0.8,0.5,0.9);
     glTranslatef(0.0,1.4,0.0);
     glTranslatef(_cloud,0.0,0.0);
     clouds();
     glPopMatrix();


     ///grass
     glPushMatrix();

     grass();
     glPopMatrix();



     ///tree
     glPushMatrix();

     tree();
     glPopMatrix();


       ///Gun

    glPushMatrix();

     drawgun();

    glPopMatrix();

     ///Bulet

     glColor3ub(0,0,0);

     drawbulet();

     glPopMatrix();

    glPushMatrix();
     glColor3ub(255,0,0);

     ostringstream cnvrt;
     cnvrt << cnt;
     sprint(-4,-2.3,"SCORE: "+cnvrt.str());
     glPopMatrix();


      glPushMatrix();
     glColor3ub(255,0,0);
     ostringstream cnvrt2;
     cnvrt2 << life;
     sprint(-4,-2.4,"LIFE REMAINING: "+cnvrt2.str());
     glPopMatrix();


        if(life<0)
        {
            gameOver=true;
        }
        glutFullScreen();
        instructionsGame = false;
		startScreen = false;
		 glutPostRedisplay();
}

void GameOverScreen()
{
	SetDisplayMode(MENU_SCREEN);
	glColor3f(0,0,0);
	glLineWidth(50);
	glBegin(GL_LINE_LOOP);               //Border
		glVertex3f(-2.5 ,-1.500 ,.05);
		glVertex3f(-2.5 ,2.0 ,.05);
		glVertex3f(2.5 ,2.0 ,.05);
		glVertex3f(2.5 ,-1.500, .05);
	glEnd();

	glLineWidth(1);

	glColor3f(0, 1, 0);
	glBegin(GL_POLYGON);				//START GAME PLOYGON
		glVertex3f(-1.8,3.0,0.05);
		glVertex3f(-1.8,2.5,0.05);
		glVertex3f(1.8,2.5,0.05);
		glVertex3f(1.8,3.0, 0.05);
	glEnd();

	glColor3f(1, 1, 0);
	glBegin(GL_POLYGON);				//RESTART POLYGON
		glBegin(GL_POLYGON);				//START GAME PLOYGON
		glVertex3f(-1.0,0.5,0.05);
		glVertex3f(-1.0,1.0,0.05);
		glVertex3f(1.0,1.0,0.05);
		glVertex3f(1.0,0.5, 0.05);
	glEnd();

	glBegin(GL_POLYGON);				//QUIT POLYGON
		glVertex3f(-1.0,-.1,.05);
		glVertex3f(-1.0,-.6,.05);
		glVertex3f(1.0, -.6,.05);
		glVertex3f(1.0, -.1,.05);
	glEnd();


	displayRasterText(-1.0,2.5,0.4,"G A M E    O V E R ! ! !");
	glColor3f(0 , 0, 0);
	char temp[40];


	if(mouseX>=-0.01 && mouseX<=0.45 && mouseY>=-0.25 && mouseY<=-0.11){
		glColor3f(0 ,0 ,1);
		if(mButtonPressed){                                                       //Reset game default values
			startGame = true ;
			gameOver=false;
			mButtonPressed = false;
			point=0;
            cnt=0;
           life=20;
           SetDisplayMode(GAME_SCREEN);
		}
	} else
		glColor3f(0 , 0, 0);
	displayRasterText(-0.3,0.7,.4  ,"Restart");

	if(mouseX>=-0.01 && mouseX<=0.45 && mouseY>=-.53 && mouseY<=-.40){
		glColor3f(0 ,0 ,1);
		if(mButtonPressed){
			exit(0);
			mButtonPressed = false;
		}
	}
	else
		glColor3f(0 , 0, 0);
	displayRasterText(-.5,-.42,0.4  ,"    Quit");
	glutSwapBuffers();

}



void drawScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW); //Switch to the drawing perspective
	glLoadIdentity(); //Reset the drawing perspective
	glRotatef(-_cameraAngle, 0.0, 1.0, 0.0); //Rotate the camera
	glTranslatef(0.0, 0.0, -7.0); //Move forward 5 units



    if(startGame && !gameOver)
		GameScreenDisplay();


	else if(instructionsGame )
		InstructionsScreenDisplay();
else if(gameOver)
		GameOverScreen();

	else if(startScreen){

			startScreenDisplay();
			if(gameQuit || startGame || optionsGame || instructionsGame){
				//startScreen = false;

				if(startGame){
					SetDisplayMode(GAME_SCREEN);
					startScreen = false;

				} else if(gameQuit)
					exit(0);

				} else if(instructionsGame) {
					SetDisplayMode(GAME_SCREEN);
					InstructionsScreenDisplay();
				}
		}


	glFlush();

    glutSwapBuffers();




     glutPostRedisplay();



   }


void update(int value) {
    if(flag==0)
        {
            bulety2+=speed2;
            bulety1+=speed2;
            glutPostRedisplay();

           if(bulety2>4.5)
           {
              bulety1=-2.0f;

              bulety2=-1.96f;
              flag=1;
           }

        }
        check(bulety2);


            birdbodyx1-=speed;
            birdbodyx2-=speed;
            glutPostRedisplay();

           if(birdbodyx2<-5)
           {
               life--;
              birdbodyx1=8.0f;
              birdbodyx2=8.40f;

           }


         check(bulety2);
           birdbody2x1-=speed3;
            birdbody2x2-=speed3;
            glutPostRedisplay();

           if(birdbody2x2<-5)
           {
               life--;
              birdbody2x1=8.0f;
              birdbody2x2=8.40f;

           }


         check(bulety2);
           birdbody3x1-=speed4;
            birdbody3x2-=speed4;
            glutPostRedisplay();

           if(birdbody3x2<-5)
           {
               life--;
              birdbody3x1=8.0f;
              birdbody3x2=8.40f;

           }

           check(bulety2);
           birdbody4x1+=speed6;
            birdbody4x2+=speed6;
            glutPostRedisplay();

           if(birdbody4x2>5)
           {
               life--;
              birdbody4x1=-8.0f;
              birdbody4x2=-8.40f;

           }

           check(bulety2);
           birdbody5x1+=speed7;
            birdbody5x2+=speed7;
            glutPostRedisplay();

           if(birdbody5x2>5)
           {
               life--;
              birdbody5x1=-8.0f;
              birdbody5x2=-8.40f;

           }


         check(bulety2);

        if(flag2==0)
        {

            buletx2+=speed5;
            buletx1+=speed5;

            gunpipex1+=speed5;
            gunpipex2+=speed5;
            glutPostRedisplay();
            flag2=1;
            if(gunpipex1<=-4)
            {

                gunpipex1=2.72;
                gunpipex2=2.92;
                 buletx1=((gunpipex1+gunpipex2)/2)-.02;
                buletx2=((gunpipex1+gunpipex2)/2)+.02;

                glutPostRedisplay();
                flag2=1;
            }
            else if(gunpipex1>=3)
            {

                gunpipex1=-2.72;
                gunpipex2=-2.92;
                buletx1=((gunpipex1+gunpipex2)/2)-.02;
                buletx2=((gunpipex1+gunpipex2)/2)+.02;
                 glutPostRedisplay();
                 flag2=1;
            }



        }

         check(bulety2);




	_ang_tri += 2.0f;
	if (_ang_tri > 360) {
		_ang_tri -= 360;
	}


    _cloud +=0.015;
    if(_cloud>6.0){
        _cloud=-6;
    }




	glutPostRedisplay(); //Tell GLUT that the display has changed

	//Tell GLUT to call update again in 25 milliseconds
	glutTimerFunc(10, update, 0);
}
void mouseClick(int buttonPressed ,int state ,int x, int y) {

	if(buttonPressed == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		mButtonPressed = true;
	else
		mButtonPressed = false;
drawScene() ;
}
  void passiveMotionFunc(int x,int y) {

	//when mouse not clicked
	mouseX = float(x)/(m_viewport[2]/1)-.600;  //converting screen resolution to ortho 2d spec
	mouseY = -(float(y)/(m_viewport[3]/1)-.350);


	drawScene();
}


void specialkey(int key, int x,int y)
{
    switch(key)
    {
    case GLUT_KEY_LEFT:
        flag2=0;
        speed5=-0.1f;
        break;

    case GLUT_KEY_RIGHT:

        flag2=0;
        speed5=0.1f;
        break;

    }

}



void keyboard(unsigned char key, int x, int y) {
   switch (key)

   {
      case 27:     // ESC key
         exit(0);
         break;



         case 'a':
           flag=0;

           sndPlaySound("9_mm_gunshot-mike-koenig-123.wav",SND_ASYNC);

           speed2=0.25f;
        break;

   }
}

int main(int argc, char** argv) {
	//Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1000,768);
	glutInitWindowPosition(200,100);


	glutCreateWindow("BLOCK SHOOTING");
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	initRendering();

	glutDisplayFunc(drawScene);

	glutReshapeFunc(handleResize);

	glutTimerFunc(25, update, 0); //Add a timer

    glutSpecialFunc(specialkey);
    glutKeyboardFunc(keyboard);
    //sndPlaySound("color_switch.wav",SND_ASYNC|SND_LOOP);
    glutPassiveMotionFunc(passiveMotionFunc);
    SetDisplayMode(GAME_SCREEN);
    glGetIntegerv(GL_VIEWPORT ,m_viewport);

    glutMouseFunc(mouseClick);
    //glutFullScreen();
	glutMainLoop();
	return 0;
}





