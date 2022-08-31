#include <windows.h>
#include <GL/glut.h>
#include<math.h>

GLfloat cx1,cx2,cx3,cx4,cy1,cy2,cy3,cy4;   //these are cloud coordinates
GLfloat cs=0.02f,px1=0.0,py1=0.0;  //These are used to move clouds
GLfloat ss=0.01f, sx1=0.0, sy1=0.0f;   //sun move
GLfloat ms=0.0f, mx1=0.0, my1=0.0f;                      //These are used to move moon
GLfloat bs=0.01f, bx1=0.0, by1=0.0f,bx2=0.0,by2=0.0;    //These are used to move boat
int day=1;
GLfloat angle=0.0f;


void circle(GLfloat x, GLfloat y, GLfloat r)
{
    int tc=100;

    GLfloat tpi=2.0f *3.141592653589793238;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);

    for(int i=0; i<=tc; i++)
    {
        glVertex2f(x+ (r*cos( (i*tpi)/tc)), y+ (r*sin( (i*tpi)/tc)));
    }
    glEnd();
}

void Daysky()
{
    glBegin(GL_POLYGON);

    glColor3f(0.68f, 0.93f, 0.93f);
    glVertex2f(100, 100);
    glVertex2f(100, 0.3);
    glVertex2f(-100, 0.3);
    glVertex2f(-100, 100);

    glEnd();
}

void ground()
{
    glBegin(GL_POLYGON);

    glColor3f(0.60f, 0.80f, 0.19f);
    glVertex2f(100, 0.3);
    glVertex2f(100, -100);
    glVertex2f(-100, -100);
    glVertex2f(-100, 0.3);

    glEnd();
}

void sun()
{
    glPushMatrix();
    glTranslatef(sx1,sy1, 0.0f);
    glColor3f(1.0f, 1.0f, 0.0f);
    circle(-0.8, 0.9, 0.07);
    glPopMatrix();
}

void moon()
{
    glPushMatrix();
    glTranslatef(mx1,my1, 0.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    circle(-0.8, 0.9, 0.07);
    glPopMatrix();
}

void cloud1()
{
    glPushMatrix();
    glTranslatef(px1,py1, 0.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    circle(-1.0f, 0.7f, 0.05f);
    circle(-0.9f, 0.7f, 0.05f);
    circle(-0.95f, 0.73f, 0.05f);
    circle(-0.95f, 0.68f, 0.05f);
    glPopMatrix();
}

void cloud2()
{
    glPushMatrix();
    glTranslatef(px1,py1, 0.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    circle(-0.7f, 0.7f, 0.05f);
    circle(-0.6f, 0.7f, 0.05f);
    circle(-0.65f, 0.73f, 0.05f);
    circle(-0.65f, 0.68f, 0.05f);
    glPopMatrix();
}

void house()
{
    glBegin(GL_TRIANGLES);//roof
    glColor3f(0.54f,0.27f,0.07f);

    glVertex2f(-0.9f,-0.10f);
    glVertex2f(-0.6f,-0.10f);
    glVertex2f(-0.75f,0.1f);

    glEnd();

    glBegin(GL_QUADS);//outer part
    glColor3f(0.95f,0.64f,0.37f);

    glVertex2f(-0.9f,-0.10f);
    glVertex2f(-0.9f,-0.4f);
    glVertex2f(-0.6f,-0.4f);
    glVertex2f(-0.6f,-0.10f);

    glEnd();

    if(day==1)
    {
        glBegin(GL_QUADS);//window1
        glColor3f(0.77f,0.77f,0.77f);
        glVertex2f(-0.85,-0.25f);
        glVertex2f(-0.85,-0.15f);
        glVertex2f(-0.75f,-0.15f);
        glVertex2f(-0.75f,-0.25f);

        glEnd();


        glBegin(GL_QUADS);//window 2
        glColor3f(0.77f,0.77f,0.77f);

        glVertex2f(-0.72f,-0.15f);
        glVertex2f(-0.72f,-0.25f);
        glVertex2f(-0.62f,-0.25f);
        glVertex2f(-0.62f,-0.15f);

        glEnd();
    }
    else
    {
        glBegin(GL_QUADS);//window1
        glColor3f(1.0f,1.0f,1.0f);
        glVertex2f(-0.85,-0.25f);
        glVertex2f(-0.85,-0.15f);
        glVertex2f(-0.75f,-0.15f);
        glVertex2f(-0.75f,-0.25f);

        glEnd();


        glBegin(GL_QUADS);//window 2
        glColor3f(1.0f,1.0f,1.0f);

        glVertex2f(-0.72f,-0.15f);
        glVertex2f(-0.72f,-0.25f);
        glVertex2f(-0.62f,-0.25f);
        glVertex2f(-0.62f,-0.15f);

        glEnd();
    }

    glBegin(GL_QUADS);//door
    glColor3f(0.77f,0.77f,0.77f);
    glVertex2f(-0.7f,-0.27f);
    glVertex2f(-0.7f,-0.40f);
    glVertex2f(-0.8f,-0.40f);
    glVertex2f(-0.8f,-0.27f);

    glEnd();
}

void hill()
{
    glBegin(GL_TRIANGLES);

    glColor3f(0, 0.6f, 0.2f);

    glVertex2f(1.0, 0.3);
    glVertex2f(0.8, 0.5);
    glVertex2f(0.6, 0.3);

    glVertex2f(0.6, 0.3);
    glVertex2f(0.4, 0.5);
    glVertex2f(0.2, 0.3);

    glVertex2f(0.5, 0.3);
    glVertex2f(0.7, 0.3);
    glVertex2f(0.6, 0.4);

    glEnd();
}

void tree()
{
    glBegin(GL_TRIANGLES);

    glColor3f(0.13f, 0.55f, 0.13f);
    glVertex2f(-0.3,-0.1);
    glVertex2f(-0.4,-0.1);
    glVertex2f(-0.35,0.1);
    glVertex2f(-0.2,-0.1);
    glVertex2f(-0.1,-0.1);
    glVertex2f(-0.15,0.1);

    glEnd();
}
void treepp()
{
    glBegin(GL_QUADS);

    glColor3f(0.55f, 0.27f, 0.07f);
    glVertex2f(-0.34, -0.1);
    glVertex2f(-0.36, -0.1);
    glVertex2f(-0.36, -0.2);
    glVertex2f(-0.34, -0.2);
    glVertex2f(-0.14, -0.1);
    glVertex2f(-0.16, -0.1);
    glVertex2f(-0.16, -0.2);
    glVertex2f(-0.14, -0.2);

    glEnd();
}

void dayTime()
{
    //sun();
    Daysky();
}

void Nightsky()
{
    glBegin(GL_POLYGON);

    glColor3f(0.19f, 0.31f, 0.31f);
    //glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(100, 100);
    glVertex2f(100, 0.3);
    glVertex2f(-100, 0.3);
    glVertex2f(-100, 100);

    glEnd();

    glPointSize(2.0);
    glBegin(GL_POINTS);

    glColor3f(1.0f, 1.0f, 1.0f);

    GLfloat x=-1.0f, y=0.0f;

    while(x<=-0.5f && y<=0.5)
    {
        for(GLfloat i=0; i<=3.0; i+=0.1)
        {
            for(GLfloat j=0; j<=2.0; j+=0.1)
            {
                glVertex2f(i+x, y+j);
            }
        }

        x+=0.05;
        y+=0.05;
    }
    glEnd();
}

void nightTime()
{
    Nightsky();
}

void road()
{
    glBegin(GL_QUADS);//outer part
    glColor3f(0.80f,0.52f,0.24f);  //1

    glVertex2f(-0.2f,0.0f);
    glVertex2f(0.0f,0.3f);
    glVertex2f(0.4f,0.3f);
    glVertex2f(0.2f,0.0f);

    glEnd();
    glBegin(GL_QUADS);//outer part
    glColor3f(0.80f,0.52f,0.24f);    //2

    glVertex2f(-0.2f,0.0f);
    glVertex2f(0.0f,-0.3f);
    glVertex2f(0.4f,-0.3f);
    glVertex2f(0.2f,0.0f);

    glEnd();

    glBegin(GL_QUADS);//3
    glColor3f(0.80f,0.52f,0.24f);
    glVertex2f(0.4f,-0.3f);
    glVertex2f(0.0f,-0.3f);
    glVertex2f(-0.2f,-0.6f);
    glVertex2f(0.2f,-0.6f);

    glEnd();
    glBegin(GL_QUADS);//4
    glColor3f(0.80f,0.52f,0.24f);

    glVertex2f(-0.2f,-0.6f);
    glVertex2f(0.2f,-0.6f);
    glVertex2f(0.4f,-1.0f);
    glVertex2f(0.0f,-1.0f);

    glEnd();
}

void river()
{
    glBegin(GL_POLYGON);

    glColor3f(0.0f,0.75f,1.0f);
    glVertex2f(0.4f,0.3f);
    glVertex2f(0.2f,0.0f);
    glVertex2f(0.4f,-0.3f);
    glVertex2f(0.2f,-0.6f);
    glVertex2f(0.4f,-1.0f);
    glVertex2f(1.0f,-1.0f);
    glVertex2f(1.0f,0.3f);

    glEnd();
}

void boat1()
{
    glPushMatrix();
    glTranslatef(bx1,by1, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.54f,0.27f,0.07f);
    glVertex2f(0.3f,0.0f);
    glVertex2f(0.5f,0.0f);
    glVertex2f(0.45f,-0.04f);
    glVertex2f(0.35f,-0.04f);
    glEnd();

    glPopMatrix();
}

void boat2()
{
    glPushMatrix();
    glTranslatef(bx2,by2, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.38f,0.38f,0.38f);
    glVertex2f(0.8f,-0.6f);
    glVertex2f(1.0f,-0.6f);
    glVertex2f(0.95f,-0.64f);
    glVertex2f(0.85f,-0.64f);
    glEnd();

    glPopMatrix();
}


void display()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);


    if(day==1)
    {
        dayTime();
        sun();
    }
    else
    {
        nightTime();
        moon();
    }

    ground();
    cloud1();
    cloud2();
    house();
    hill();
    road();
    tree();
    river();
    treepp();
    boat1();
    boat2();

    glFlush();
}


void Resize(int width, int height)
{
    // we ignore the params and do:
    glutReshapeWindow( width, height);
}


void cloud_move(int value)
{
    if(px1>=2.0f)
        px1=-1.0f;
    else
        px1+=cs;
    glutPostRedisplay();
    glutTimerFunc(100, cloud_move, 0);
}

void sun_move(int value)
{
    if(sy1<=-0.49)
    {
        sy1=0.0f;
        ss=0.0f;
        ms=0.01f;
        day=0;
    }
    else
        sy1-=ss;
    glutPostRedisplay();
    glutTimerFunc(100, sun_move, 0);
}


void moon_move(int value)
{
    if(my1<=-0.49)
    {
        my1=0.0f;
        ms=0.0f;
        ss=0.01f;
        day=1;
    }
    else
        my1-=ms;
    glutPostRedisplay();
    glutTimerFunc(100, moon_move, 0);
}

void boat_move1(int value)
{
    if(bx1>=0.8f)
    {
        bx1=0.0f;
    }
    else
        bx1+=bs;
    glutPostRedisplay();
    glutTimerFunc(100, boat_move1, 0);
}

void boat_move2(int value)
{
    if(bx2<=-0.5)
    {
        bx2=0.0f;
    }
    else
        bx2-=bs;
    glutPostRedisplay();
    glutTimerFunc(100, boat_move2, 0);
}

void Idle()
{
    glutPostRedisplay();
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutCreateWindow("Village Scenario");
    glutInitWindowSize(320, 320);

    Resize(900,900);

    glutDisplayFunc(display);
    glutTimerFunc(100, cloud_move, 0);
    glutTimerFunc(100, sun_move, 0);
    glutTimerFunc(100, moon_move, 0);
    glutTimerFunc(100, boat_move1, 0);
    glutTimerFunc(100, boat_move2, 0);
    glutIdleFunc(Idle);
    glutMainLoop();
    return 0;
}
