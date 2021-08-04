#include<stdio.h>
#include<GL/glut.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>
#include<time.h>

float red = 1.0;
float blue = 0.0;
float green = 1.0;
int square;
GLfloat DEG2RAD = 3.1459 / 180;
GLint flag = 0;
bool updateGeom;
void drawBalloon(int y);
void frontscreen();
void mydisplay();
int balloon, screen1;
int x, y;
GLfloat xbird = 500.0, xcloud = 500.0, xman = 0.0;
GLfloat xC1 = 0.0;
int manflag = 0;
int manheadflag = 0;
int manjumpflag = 0;
GLfloat x1 = 0.0, x2 = 0.0, x3 = 0.0, yC1 = 0.0, yC2 = 0.0, yC3 = 0.0;

void frontscreen(void)
{
    int i;
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3d(1.0, 0.0, 0.0);
    
    char z[60] = "PRESS ENTER TO START";
    glColor3f(1.0, 1.0, 1.0);
    glRasterPos2d(180, 60);
    for (i = 0; i < 60; i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, z[i]);
    glEnd();
    glFlush();
}

void myKeyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 13:
        if (flag == 1)
        {
            flag = 2;
            mydisplay();
        }
        if (flag == 0)
        {
            flag = 1;
            mydisplay();
        }
        break;
    }
    if (key == 'h')
    {
        updateGeom = false;//stop updating
    }
    if (key == 's')
    {
        updateGeom = true;//start updating
        manheadflag = 1;
        manflag = 1;
    }
}

void circle()
{
    GLint i;
    GLfloat degInrad;
    glColor3d(1.0, 0.0, 1.0);
    glBegin(GL_POLYGON);
    for (i = 0; i <= 180; i++)
    {
        degInrad = i * DEG2RAD;
        glVertex2f((cos(degInrad) * 80) + (x + 100), (sin(degInrad) * 80) + (y + 200));
    }
    glEnd();
}

void sleep(unsigned int msec)
{
    clock_t goal = msec + clock();
    while (goal > clock());
}

void clouds()
{
    GLint i;
    GLfloat degInrad;
    glColor3d(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    for (i = 0; i <= 360; i++)
    {
        degInrad = i * DEG2RAD;
        glVertex2f((cos(degInrad) * 50) + (30), (sin(degInrad) * 50) + (460));
    }
    glEnd();
    glColor3d(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    for (i = 0; i <= 360; i++)
    {
        degInrad = i * DEG2RAD;
        glVertex2f((cos(degInrad) * 60) + (95), (sin(degInrad) * 60) + (460));
    }
    glEnd();
    glColor3d(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    for (i = 0; i <= 360; i++)
    {
        degInrad = i * DEG2RAD;
        glVertex2f((cos(degInrad) * 50) + (250), (sin(degInrad) * 50) + (475));
    }
    glEnd();
    glColor3d(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    for (i = 0; i <= 360; i++)
    {
        degInrad = i * DEG2RAD;
        glVertex2f((cos(degInrad) * 50) + (330), (sin(degInrad) * 50) + (475));
    }
    glEnd();
    glColor3d(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    for (i = 0; i <= 360; i++)
    {
        degInrad = i * DEG2RAD;
        glVertex2f((cos(degInrad) * 60) + (400), (sin(degInrad) * 60) + (475));
    }
    glEnd();
}

void birds()
{
    //bird1
    glColor3d(0.0, 0.0, 0.0);
    glBegin(GL_TRIANGLES);
    glVertex2d(350, 300);
    glVertex2d(350, 320);
    glVertex2d(340, 310);
    glEnd();
    glBegin(GL_TRIANGLES);
    glVertex2d(350, 320);
    glVertex2d(350, 340);
    glVertex2d(340, 330);
    glEnd();
    glColor3d(1.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex2d(330, 320);
    glVertex2d(340, 310);
    glVertex2d(370, 320);
    glVertex2d(340, 330);
    glEnd();

    //bird2
    glColor3d(0.0, 0.0, 0.0);
    glBegin(GL_TRIANGLES);
    glVertex2d(390, 350);
    glVertex2d(390, 370);
    glVertex2d(380, 360);
    glEnd();
    glBegin(GL_TRIANGLES);
    glVertex2d(390, 370);
    glVertex2d(390, 390);
    glVertex2d(380, 380);
    glEnd();
    glColor3d(1.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex2d(370, 370);
    glVertex2d(380, 360);
    glVertex2d(410, 370);
    glVertex2d(380, 380);
    glEnd();

    //bird3
    glColor3d(0.0, 0.0, 0.0);
    glBegin(GL_TRIANGLES);
    glVertex2d(390, 270);
    glVertex2d(390, 290);
    glVertex2d(380, 280);
    glEnd();
    glBegin(GL_TRIANGLES);
    glVertex2d(390, 290);
    glVertex2d(390, 310);
    glVertex2d(380, 300);
    glEnd();
    glColor3d(1.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex2d(370, 290);
    glVertex2d(380, 280);
    glVertex2d(410, 290);
    glVertex2d(380, 300);
    glEnd();

}

void drawSquare(int x)
{
    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(x + 20, 20);
    glVertex2f(x + 50, 20);
    glVertex2f(x + 50, 50);
    glVertex2f(x + 20, 50);
    glEnd();
    glFlush();
}

void hat()
{
    GLint i;
    GLfloat degInrad;
    glColor3d(0.46, 0.139, 0.87);
    glBegin(GL_POLYGON);
    for (i = 0; i <= 180; i++)
    {
        degInrad = i * DEG2RAD;
        glVertex2f((cos(degInrad) * 10) + (x + 200), (sin(degInrad) * 10) + (y + 70));
    }
    glEnd();
    glColor3d(0.46, 0.139, 0.87);
    glBegin(GL_POLYGON);
    glVertex2d(180, 70);
    glVertex2d(180, 65);
    glVertex2d(220, 65);
    glVertex2d(220, 70);
    glEnd();
}

void man()
{
    GLint i;
    GLfloat degInrad;
    glColor3d(1.2, 0.720, 0.0);
    glBegin(GL_POLYGON);
    for (i = 0; i <= 360; i++)
    {
        degInrad = i * DEG2RAD;
        glVertex2f((cos(degInrad) * 10) + (x + 200), (sin(degInrad) * 10) + (y + 65));
    }
    glEnd();
    glColor3d(0.0, 0.0, 0.0);
    glPointSize(3);
    glBegin(GL_POINTS);
    glVertex2d(196, 63);
    glVertex2d(204, 63);
    glEnd();
    glColor3d(1.0, 0.0, 0.0);
    {
        glLineWidth(2.0);
        glBegin(GL_LINES);
        glVertex2d(197, 59);
        glVertex2d(203, 59);
        glEnd();
    }
    glColor3d(1.2, 0.720, 0.0);
    {
        glLineWidth(8.0);
        glBegin(GL_LINES);
        glVertex2d(200, 53);
        glVertex2d(200, 55);
        glEnd();
    }
    glColor3d(0.54, 0.163, 0.32);
    glBegin(GL_POLYGON);
    glVertex2d(190, 53);
    glVertex2d(210, 53);
    glVertex2d(210, 36);
    glVertex2d(190, 36);
    glEnd();

    glColor3d(0.54, 0.163, 0.32);
    glBegin(GL_POLYGON);
    glVertex2d(190, 53);
    glVertex2d(190, 45);
    glVertex2d(185, 35);
    glVertex2d(180, 35);
    glEnd();
    glColor3d(1.2, 0.720, 0.0);
    glPointSize(5);
    glBegin(GL_POINTS);
    glVertex2d(182, 35);
    glEnd();

    glColor3d(0.54, 0.163, 0.32);
    glBegin(GL_POLYGON);
    glVertex2d(210, 53);
    glVertex2d(210, 45);
    glVertex2d(215, 35);
    glVertex2d(220, 35);
    glEnd();
    glColor3d(1.2, 0.720, 0.0);
    glPointSize(5);
    glBegin(GL_POINTS);
    glVertex2d(218, 35);
    glEnd();

    glColor3d(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2d(190, 36);
    glVertex2d(210, 36);
    glVertex2d(210, 0);
    glVertex2d(190, 0);
    glEnd();
    glColor3d(0.0, 0.0, 0.0);
    {
        glLineWidth(2.0);
        glBegin(GL_LINES);
        glVertex2d(200, 0);
        glVertex2d(200, 25);
        glEnd();
    }
    hat();
}

void headballoon()
{

    //man
    GLint i;
    GLfloat degInrad;
    glColor3d(1.2, 0.720, 0.0);
    glBegin(GL_POLYGON);
    for (i = 0; i <= 360; i++)
    {
        degInrad = i * DEG2RAD;
        glVertex2f((cos(degInrad) * 10) + (x + 100), (sin(degInrad) * 10) + (y + 60));
    }
    glEnd();

    glColor3d(0.0, 0.0, 0.0);
    glPointSize(3);
    glBegin(GL_POINTS);
    glVertex2d(96, 59);
    glVertex2d(104, 59);
    glEnd();
    glColor3d(1.0, 0.0, 0.0);
    {
        glLineWidth(2.0);
        glBegin(GL_LINES);
        glVertex2d(97, 54);
        glVertex2d(103, 54);
        glEnd();
    }

    //hat
    glColor3d(0.46, 0.139, 0.87);
    glBegin(GL_POLYGON);
    for (i = 0; i <= 180; i++)
    {
        degInrad = i * DEG2RAD;
        glVertex2f((cos(degInrad) * 10) + (x + 100), (sin(degInrad) * 10) + (y + 60));
    }
    glEnd();
    glColor3d(0.46, 0.139, 0.87);
    glBegin(GL_POLYGON);
    glVertex2d(82, 65);
    glVertex2d(82, 60);
    glVertex2d(118, 60);
    glVertex2d(118, 65);
    glEnd();
}

void drawBalloon(int y)
{
    glColor3f(1.0, 0.6, 0.0);
    glBegin(GL_POLYGON);
    glVertex2d(80, y + 10);
    glVertex2d(80, y + 50);
    glVertex2d(120, y + 50);
    glVertex2d(120, y + 10);
    glEnd();
    glColor3d(0.0, 0.0, 0.0);
    {
        glLineWidth(1.0);
        glBegin(GL_LINES);
        glVertex2d(90, y + 10);
        glVertex2d(90, y + 50);
        glVertex2d(100, y + 10);
        glVertex2d(100, y + 50);
        glVertex2d(110, y + 10);
        glVertex2d(110, y + 50);
        glEnd();
        glColor3d(0.0, 0.0, 0.0);
        glBegin(GL_LINES);
        glVertex2d(80, y + 20);
        glVertex2d(120, y + 20);
        glVertex2d(80, y + 30);
        glVertex2d(120, y + 30);
        glVertex2d(80, y + 40);
        glVertex2d(120, y + 40);
        glEnd();
        glColor3d(0.0, 0.0, 0.0);
        glBegin(GL_LINE_LOOP);
        glVertex2d(80, y + 50);
        glVertex2d(80, y + 70);
        glVertex2d(120, y + 50);
        glVertex2d(120, y + 70);
        glEnd();
    }
    glColor3d(0.2, 0.5, 1.0);
    glBegin(GL_TRIANGLES);
    glVertex2d(80, y + 70);
    glVertex2d(80, y + 200);
    glVertex2d(20, y + 200);
    glEnd();
    glColor3d(0.2, 0.5, 1.0);
    glBegin(GL_TRIANGLES);
    glVertex2d(120, y + 70);
    glVertex2d(120, y + 200);
    glVertex2d(180, y + 200);
    glEnd();
    glColor3d(1.0, 0.7, 0.5);
    glBegin(GL_POLYGON);
    glVertex2d(80, y + 70);
    glVertex2d(120, y + 70);
    glVertex2d(120, y + 200);
    glVertex2d(80, y + 200);
    glEnd();
    glTranslatef(0.0, y, 0.0);
    circle();

    if (manheadflag == 1)
    {
        headballoon();
    }
    glFlush();
}

//1st screen
void drawScreen1()
{
    int i;
    glColor3d(0.0, 1.0, 0.170);
    glBegin(GL_POLYGON);
    glVertex2d(0, 0);
    glVertex2d(500, 0);
    glVertex2d(500, 250);
    glVertex2d(0, 250);
    glEnd();
    glColor3d(0.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2d(0, 250);
    glVertex2d(500, 250);
    glVertex2d(500, 500);
    glVertex2d(0, 500);
    glEnd();

    glColor3d(0.5, 0.5, 0.5);
    glBegin(GL_POLYGON);
    glVertex2d(40, 5);
    glVertex2d(40, 60);
    glVertex2d(160, 60);
    glVertex2d(160, 5);
    glEnd();

    //tree1
    glColor3d(0.8, 0.4, 0.2);
    glBegin(GL_POLYGON);
    glVertex2d(270, 100);
    glVertex2d(280, 100);
    glVertex2d(280, 200);
    glVertex2d(270, 200);
    glEnd();

    glColor3d(0.0, 0.6, 0.0);
    glBegin(GL_TRIANGLES);
    glVertex2d(230, 200);
    glVertex2d(320, 200);
    glVertex2d(275, 250);
    glEnd();
    glColor3d(0.0, 0.6, 0.0);
    glBegin(GL_TRIANGLES);
    glVertex2d(240, 230);
    glVertex2d(310, 230);
    glVertex2d(275, 270);
    glEnd();
    glColor3d(0.0, 0.6, 0.0);
    glBegin(GL_TRIANGLES);
    glVertex2d(250, 255);
    glVertex2d(300, 255);
    glVertex2d(275, 300);
    glEnd();

    //tree2
    glColor3d(0.8, 0.4, 0.2);
    glBegin(GL_POLYGON);
    glVertex2d(360, 60);
    glVertex2d(370, 60);
    glVertex2d(370, 140);
    glVertex2d(360, 140);
    glEnd();

    glColor3d(0.0, 0.6, 0.0);
    glBegin(GL_TRIANGLES);
    glVertex2d(320, 140);
    glVertex2d(410, 140);
    glVertex2d(365, 200);
    glEnd();
    glColor3d(0.0, 0.6, 0.0);
    glBegin(GL_TRIANGLES);
    glVertex2d(330, 170);
    glVertex2d(400, 170);
    glVertex2d(365, 220);
    glEnd();
    glColor3d(0.0, 0.6, 0.0);
    glBegin(GL_TRIANGLES);
    glVertex2d(340, 200);
    glVertex2d(390, 200);
    glVertex2d(365, 250);
    glEnd();

    //tree3
    glColor3d(0.8, 0.4, 0.2);
    glBegin(GL_POLYGON);
    glVertex2d(440, 180);
    glVertex2d(450, 180);
    glVertex2d(450, 260);
    glVertex2d(440, 260);
    glEnd();
    glColor3d(0.0, 0.6, 0.0);
    glBegin(GL_TRIANGLES);
    glVertex2d(400, 260);
    glVertex2d(490, 260);
    glVertex2d(445, 300);
    glEnd();
    glColor3d(0.0, 0.6, 0.0);
    glBegin(GL_TRIANGLES);
    glVertex2d(410, 285);
    glVertex2d(480, 285);
    glVertex2d(445, 320);
    glEnd();
    glColor3d(0.0, 0.6, 0.0);
    glBegin(GL_TRIANGLES);
    glVertex2d(420, 310);
    glVertex2d(470, 310);
    glVertex2d(445, 350);
    glEnd();
    clouds();

    if (manflag == 0)
        man();
    if (manheadflag == 1)
    {
        glPushMatrix();
        glTranslatef(x1, yC1, 0.0);
        headballoon();
        glPopMatrix();
    }
    char w[60] = "PRESS 'S' TO START";
    glColor3f(0.0, 0.0, 0.0);
    glRasterPos2d(325, 30);
    for (i = 0; i < 60; i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, w[i]);
    glEnd();

    glFlush();
}

//2nd screen
void sun()
{
    GLint i;
    GLfloat degInrad;
    glColor3f(red, green, blue);
    glBegin(GL_POLYGON);
    for (i = 0; i <= 360; i++)
    {
        degInrad = i * DEG2RAD;
        glVertex2f((cos(degInrad) * 40) + (50), (sin(degInrad) * 40) + 430);
    }
    glEnd();
}

void drawDesert(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.8, 0.2, 0.0, 1.0);
    glColor3d(0.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2d(0, 250);
    glVertex2d(500, 250);
    glVertex2d(500, 500);
    glVertex2d(0, 500);
    glEnd();
    glColor3d(0.8, 0.4, 0.0);
    glBegin(GL_TRIANGLES);
    glVertex2d(0, 160);
    glVertex2d(165, 160);
    glVertex2d(85, 300);
    glEnd();
    glColor3d(0.8, 0.6, 0.0);
    glBegin(GL_TRIANGLES);
    glVertex2d(165, 160);
    glVertex2d(170, 180);
    glVertex2d(85, 300);
    glEnd();
    glColor3d(0.8, 0.4, 0.0);
    glBegin(GL_TRIANGLES);
    glVertex2d(250, 10);
    glVertex2d(380, 10);
    glVertex2d(315, 140);
    glEnd();
    glColor3d(0.8, 0.6, 0.0);
    glBegin(GL_TRIANGLES);
    glVertex2d(380, 10);
    glVertex2d(390, 30);
    glVertex2d(315, 140);
    glEnd();
    glColor3d(0.8, 0.4, 0.0);
    glBegin(GL_TRIANGLES);
    glVertex2d(370, 160);
    glVertex2d(480, 160);
    glVertex2d(420, 270);
    glEnd();
    glColor3d(0.8, 0.6, 0.0);
    glBegin(GL_TRIANGLES);
    glVertex2d(480, 160);
    glVertex2d(485, 180);
    glVertex2d(420, 270);
    glEnd();
    glColor3d(1.0, 0.8, 0.0);
    {
        glLineWidth(5.0);
        glBegin(GL_LINES);
        glVertex2d(0, 430);
        glVertex2d(8, 430);
        glVertex2d(100, 430);
        glVertex2d(140, 430);
        glVertex2d(45, 380);
        glVertex2d(45, 340);
        glVertex2d(45, 480);
        glVertex2d(45, 500);
        glEnd();
        glColor3d(1.0, 0.9, 0.0);
        glLineWidth(2.0);
        glBegin(GL_LINES);
        glVertex2d(28, 495);
        glVertex2d(32, 480);
        glVertex2d(12, 480);
        glVertex2d(20, 465);
        glVertex2d(0, 460);
        glVertex2d(6, 450);
        glVertex2d(58, 480);
        glVertex2d(62, 495);
        glVertex2d(74, 470);
        glVertex2d(82, 485);
        glVertex2d(90, 450);
        glVertex2d(98, 465);
        glVertex2d(6, 410);
        glVertex2d(0, 400);
        glVertex2d(12, 380);
        glVertex2d(20, 395);
        glVertex2d(28, 365);
        glVertex2d(32, 385);
        glVertex2d(58, 380);
        glVertex2d(62, 360);
        glVertex2d(74, 390);
        glVertex2d(86, 370);
        glVertex2d(88, 410);
        glVertex2d(98, 395);
        glEnd();
    }
    
    glEnd();
    sun();
    glFlush();
}

//3rd screen
void moon()
{
    GLint i;
    GLfloat degInrad;
    glColor3d(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    for (i = 0; i <= 360; i++)
    {
        degInrad = i * DEG2RAD;
        glVertex2f((cos(degInrad) * 35) + (445), (sin(degInrad) * 35) + 460);
    }
    glEnd();
}

void tent()
{
    glColor3d(0.4, 0.0, 0.2);
    glBegin(GL_POLYGON);
    glVertex2d(30, 20);
    glVertex2d(80, 20);
    glVertex2d(110, 120);
    glVertex2d(50, 120);
    glEnd();
    glColor3d(0.0, 0.3, 0.7);
    glBegin(GL_TRIANGLES);
    glVertex2d(80, 20);
    glVertex2d(95, 20);
    glVertex2d(110, 120);
    glEnd();
    glColor3d(0.0, 0.3, 0.7);
    glBegin(GL_TRIANGLES);
    glVertex2d(115, 20);
    glVertex2d(130, 20);
    glVertex2d(110, 120);
    glEnd();

    //bonfire
    glColor3d(1.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex2d(200, 24);
    glVertex2d(230, 29);
    glVertex2d(200, 65);
    glVertex2d(170, 29);
    glEnd();
    glColor3d(1.0, 1.0, 0.0);
    glBegin(GL_QUADS);
    glVertex2d(200, 25);
    glVertex2d(220, 30);
    glVertex2d(200, 60);
    glVertex2d(180, 30);
    glEnd();
    {
        glColor3d(0.34, 0.139, 0.0);
        glLineWidth(5.0);
        glBegin(GL_LINES);

        //stick1
        glVertex2d(180, 20);
        glVertex2d(210, 30);

        //stick2
        glVertex2d(200, 10);
        glVertex2d(200, 40);

        //stick3
        glVertex2d(220, 20);
        glVertex2d(190, 30);
        glEnd();
    }
}

void hatjump()
{
    GLint i;
    GLfloat degInrad;
    glColor3d(0.46, 0.139, 0.87);
    glBegin(GL_POLYGON);
    for (i = 0; i <= 180; i++)
    {
        degInrad = i * DEG2RAD;
        glVertex2f((cos(degInrad) * 10) + (x + 400), (sin(degInrad) * 10) + (y + 70));
    }
    glEnd();
    glColor3d(0.46, 0.139, 0.87);
    glBegin(GL_POLYGON);
    glVertex2d(380, 70);
    glVertex2d(380, 65);
    glVertex2d(420, 65);
    glVertex2d(420, 70);
    glEnd();
}


void manjump()
{
    GLint i;
    GLfloat degInrad;
    glColor3d(1.2, 0.720, 0.0);
    glBegin(GL_POLYGON);
    for (i = 0; i <= 360; i++)
    {
        degInrad = i * DEG2RAD;
        glVertex2f((cos(degInrad) * 10) + (x + 400), (sin(degInrad) * 10) + (y + 65));
    }
    glEnd();
    glColor3d(0.0, 0.0, 0.0);
    glPointSize(3);
    glBegin(GL_POINTS);
    glVertex2d(396, 63);
    glVertex2d(404, 63);
    glEnd();
    glColor3d(1.0, 0.0, 0.0);
    {
        glLineWidth(2.0);
        glBegin(GL_LINES);
        glVertex2d(397, 59);
        glVertex2d(403, 59);
        glEnd();
    }
    glColor3d(1.2, 0.720, 0.0);
    {
        glLineWidth(8.0);
        glBegin(GL_LINES);
        glVertex2d(400, 53);
        glVertex2d(400, 55);
        glEnd();
    }
    glColor3d(0.54, 0.163, 0.32);
    glBegin(GL_POLYGON);
    glVertex2d(390, 53);
    glVertex2d(410, 53);
    glVertex2d(410, 36);
    glVertex2d(390, 36);
    glEnd();

    glColor3d(0.54, 0.163, 0.32);
    glBegin(GL_POLYGON);
    glVertex2d(390, 53);
    glVertex2d(390, 45);
    glVertex2d(385, 35);
    glVertex2d(380, 35);
    glEnd();
    glColor3d(1.2, 0.720, 0.0);
    glPointSize(5);
    glBegin(GL_POINTS);
    glVertex2d(382, 35);
    glEnd();

    glColor3d(0.54, 0.163, 0.32);
    glBegin(GL_POLYGON);
    glVertex2d(410, 53);
    glVertex2d(410, 45);
    glVertex2d(415, 35);
    glVertex2d(420, 35);
    glEnd();
    glColor3d(1.2, 0.720, 0.0);
    glPointSize(5);
    glBegin(GL_POINTS);
    glVertex2d(418, 35);
    glEnd();

    glColor3d(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2d(390, 36);
    glVertex2d(410, 36);
    glVertex2d(410, 0);
    glVertex2d(390, 0);
    glEnd();
    glColor3d(0.0, 0.0, 0.0);
    {
        glLineWidth(2.0);
        glBegin(GL_LINES);
        glVertex2d(400, 0);
        glVertex2d(400, 25);
        glEnd();
    }
    hatjump();
}

void drawscreen2(void)
{
    int i;
    glColor3d(0.0, 0.139, 0.0);
    glBegin(GL_POLYGON);
    glVertex2d(0, 0);
    glVertex2d(0, 250);
    glVertex2d(500, 0);
    glVertex2d(500, 250);
    glEnd();
    glColor3d(0.0, 0.0, 0.128);
    glBegin(GL_POLYGON);
    glVertex2d(0, 250);
    glVertex2d(500, 250);
    glVertex2d(500, 500);
    glVertex2d(0, 500);
    glEnd();
    glColor3d(0.0, 0.2, 0.6);
    glBegin(GL_TRIANGLES);
    glVertex2d(0, 250);
    glVertex2d(250, 125);
    glVertex2d(500, 250);
    glEnd();
    glColor3d(0.34, 0.139, 0.0);
    glBegin(GL_TRIANGLES);
    glVertex2d(0, 250);
    glVertex2d(167, 250);
    glVertex2d(84, 300);
    glEnd();
    glColor3d(0.34, 0.139, 0.0);
    glBegin(GL_TRIANGLES);
    glVertex2d(167, 250);
    glVertex2d(334, 250);
    glVertex2d(250, 300);
    glEnd();
    glColor3d(0.34, 0.139, 0.0);
    glBegin(GL_TRIANGLES);
    glVertex2d(334, 250);
    glVertex2d(500, 250);
    glVertex2d(417, 300);
    glEnd();

    glColor3d(0.5, 0.5, 0.5);
    glBegin(GL_POLYGON);
    glVertex2d(420, 5);
    glVertex2d(420, 60);
    glVertex2d(500, 60);
    glVertex2d(500, 5);
    glEnd();

    //stars
    glColor3d(1.0, 1.0, 1.0);
    glPointSize(3);
    glBegin(GL_POINTS);
    glVertex2d(10, 425);
    glVertex2d(260, 375);
    glVertex2d(120, 325);
    glVertex2d(420, 425);
    glVertex2d(390, 375);
    glVertex2d(327, 325);
    glVertex2d(257, 333);
    glVertex2d(444, 332);
    glVertex2d(127, 369);
    glVertex2d(313, 273);
    glVertex2d(309, 468);
    glVertex2d(456, 345);
    glVertex2d(123, 432);
    glVertex2d(200, 499);
    glVertex2d(197, 399);
    glVertex2d(167, 468);
    glVertex2d(127, 437);
    glVertex2d(24, 496);
    glVertex2d(27, 369);
    glVertex2d(13, 273);
    glVertex2d(9, 468);
    glVertex2d(56, 345);
    glEnd();
    moon();
    tent();
    glFlush();
}

void myinit()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0, 0.0, 0.0, 0.0);
    gluOrtho2D(0.0, 500.0, 0.0, 500.0);
    square = glGenLists(1);
    glNewList(square, GL_COMPILE);
    drawSquare(0);
    glEndList();
    screen1 = glGenLists(1);
    glNewList(screen1, GL_COMPILE);
    drawScreen1();
    glEndList();
    balloon = glGenLists(1);
    glNewList(balloon, GL_COMPILE);
    drawBalloon(0);
    glEndList();
}

//menu
void top_menu(int id)
{
    switch (id)
    {
    case 1:
        red = 1.0;
        green = 0.0;
        blue = 0.0;
        break;

    case 2:
        red = 1.0;
        green = 0.8;
        blue = 0.0;
        break;

    case 3:
        red = 1.0;
        green = 1.0;
        blue = 0.0;
        break;

    default:
        break;
    }
    glutPostRedisplay();
}





void end()
{
    int i;
    glClearColor(0.0, 0.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glTranslatef(xC1, 0.0, 0.0);
    glCallList(square);
    glFlush();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(xC1, 450.0, 0.0);
    glCallList(square);
    glFlush();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.0, xC1, 0.0);
    glCallList(square);
    glFlush();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(450.0, xC1, 0.0);
    glCallList(square);
    glFlush();
    glPopMatrix();
    if (xC1 == 500.0)
        xC1 = 0.0;
    xC1 = xC1 + 5.0;
    sleep(100);
    glutPostRedisplay();
    glutSwapBuffers();

   
    glEnd();
    glFlush();
}

void mydisplay()
{
    if (flag == 0)
        frontscreen();
    else
        if (flag == 1)
        {
            glClear(GL_COLOR_BUFFER_BIT);
            glPushMatrix();
            drawScreen1();
            glPushMatrix();
            glTranslatef(xbird, 0.0, 0.0);
            birds();
            glPopMatrix();
            xbird = xbird - 2.0;
            if (xbird == 500.0)
            {
                xbird = 0.0;
            }
            glPushMatrix();
            glTranslatef(x1, yC1, 0.0);
            glCallList(balloon);
            glPopMatrix();
            if (updateGeom)
            {
                x1 = x1 + 1.0;
                yC1 = yC1 + 0.5;
            }
            sleep(40);
            glPopMatrix();

            if (yC1 >= 200.0 && x2 < 350.0)
            {
                drawDesert();
                glPushMatrix();
                glTranslatef(xcloud, 0.0, 0.0);
                clouds();
                glPopMatrix();
                xcloud = xcloud - 3.0;
                if (xcloud == 500.0)
                {
                    xcloud = 0.0;
                }
                glPushMatrix();
                glTranslatef(x2, 0.0, 0.0);
                drawBalloon(200);
                glPopMatrix();
                x2 = x2 + 1.0;
                sleep(40);
                glPopMatrix();
            }

            if (x2 >= 350.0)
            {
                drawscreen2();
                glPushMatrix();
                glTranslatef(x3, yC3, 0.0);
                drawBalloon(200);
                glPopMatrix();
                if (updateGeom)
                {
                    x3 = x3 + 1.0;
                    yC3 = yC3 - 0.5;
                }
                sleep(40);
                glPopMatrix();
            }
            if (x3 >= 350.0)
            {
                manheadflag = 0;
                glPushMatrix();
                glTranslatef(xman, 0.0, 0.0);
                manjump();
                glPopMatrix();
                xman = xman - 5.0;
            }
            if (x3 >= 375.0)
               end();
        }
    glutPostRedisplay();
    glutSwapBuffers();
    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(900, 700);
    glutCreateWindow("Hot Air Balloon");
    glutDisplayFunc(mydisplay);
    glutCreateMenu(top_menu);
    glutAddMenuEntry("RED", 1);
    glutAddMenuEntry("ORANGE", 2);
    glutAddMenuEntry("YELLOW", 3);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutKeyboardFunc(myKeyboard);
    myinit();
    glutMainLoop();
    return 0;
}
