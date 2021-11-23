
#include <iostream>
#include <QSlider>
#include <cmath>
#include <GL/glu.h>
#include <GL/glut.h>
#include <QGLWidget>
#include "AlienWidget.h"


GLfloat white[] = {1.0, 1.0, 1.0, 1.0};
GLfloat red[] = {0.5, 0.0, 0.0, 0.0};
GLfloat black[] = {0.0, 0.0, 0.0, 0.0};
GLfloat blue[] = {0.73, 0.16, 0.96, 0.0};
GLfloat purple[] = {1.0, 0.0, 1.0, 0.0};
GLfloat cyan[] = {0.0, 1.0, 1.0, 0.0};
GLfloat gyellow[] = {0.5, 1.0, 0.0, 0.0};
GLfloat green[] = {0.0, 1.0, 0.0, 0.0};
GLfloat orange[] = {1.0, 0.5, 0.0, 0.0};
// Setting up material properties
typedef struct materialStruct {
  GLfloat ambient[4];
  GLfloat diffuse[4];
  GLfloat specular[4];
  GLfloat shininess;
} materialStruct;

static materialStruct turqMaterials = {
  { 0.1, 0.18725, 0.1745, 0.8 },
  {0.396, 0.74151, 0.69102, 0.8 },
  {0.297254, 0.30829, 0.306678, 0.8},
  12.8
};

static materialStruct emeraldMaterials = {
  { 0.22, 0.17, 0.22, 55.0},
  { 0.076, 0.61, 0.76, 1.0},
  { 0.63, 0.73, 0.63, 55.0},
  27.8
};

static materialStruct rubyMaterials = {
  { 0.22, 0.17, 0.22, 55.0},
  { 0.076, 0.61, 0.76, 1.0},
  { 0.63, 0.73, 0.63, 55.0},
  27.8
};

static materialStruct jadeMaterials = {
  {0.1745,   0.01175,  0.01175,   1.0},
  { 0.61424,  0.04136,  0.04136,   1.0},
  {0.727811, 0.626959, 0.626959,  1.0},
  76.8
};



static materialStruct brassMaterials = {
  { 0.33, 0.22, 0.03, 1.0},
  { 0.78, 0.57, 0.11, 1.0},
  { 0.99, 0.91, 0.81, 1.0},
  27.8
};

static materialStruct whiteShinyMaterials = {
  { 1.0, 1.0, 1.0, 1.0},
  { 1.0, 1.0, 1.0, 1.0},
  { 1.0, 1.0, 1.0, 1.0},
  100.0
};



// constructor
AlienWidget::AlienWidget(QWidget *parent):
  QGLWidget(parent),
  angle(0.0),
  flying(0),
  _image("./floor.PPM"),
  _image2("./ball3.jpg"),
  _image3("./Moi.ppm"),
  _image4("./earth.ppm"),
  _image5("./wall.jpg")
	{ // constructor
    pdiscoball = gluNewQuadric();
    prod = gluNewQuadric();
    peye = gluNewQuadric();
    pbody = gluNewQuadric();
    pantenna = gluNewQuadric();
    pspaceship = gluNewQuadric();
    ptop = gluNewQuadric();
    pdiscorod = gluNewQuadric();


	} // constructor


// called when OpenGL context is set up
void AlienWidget::initializeGL()
	{ // initializeGL()
	// set the widget background colour
	glClearColor(0.0, 0.0, 0.0, 1.0);

	} // initializeGL()

  AlienWidget::~AlienWidget()
  {
    gluDeleteQuadric(pdiscoball);
    gluDeleteQuadric(prod);
    gluDeleteQuadric(peye);
    gluDeleteQuadric(pbody);
    gluDeleteQuadric(pantenna);
    gluDeleteQuadric(pspaceship);
    gluDeleteQuadric(ptop);
    gluDeleteQuadric(pdiscorod);
  }

  void AlienWidget::updateAngle(){
    angle += 2.5;
    this->repaint();
  }

  void AlienWidget::updateFlying(int i){
    flying = i;
    this->repaint();
  }


// called every time the widget is resized
void AlienWidget::resizeGL(int w, int h)
	{ // resizeGL()
	// set the viewport to the entire widget
	glViewport(0, 0, w, h);
	GLfloat light_pos[] = {0., 0., 1., 0.};

	glEnable(GL_LIGHTING); // enable lighting in general
        glEnable(GL_LIGHT0);   // each light source must also be enabled
       	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
	glLightf (GL_LIGHT0, GL_SPOT_CUTOFF,180.);


        // glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, _image.Width(), _image.Height(), 0, GL_RGB, GL_UNSIGNED_BYTE, _image.imageField());

  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
  // glDisable(GL_TEXTURE_2D);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-3.0, 3.0, -3.0, 3.0, -3.0, 3.0);

	} // resizeGL()

void AlienWidget::discoball(){
  glEnable(GL_TEXTURE_2D);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, _image2.Width(), _image2.Height(), 0, GL_RGB, GL_UNSIGNED_BYTE, _image2.imageField());
  gluQuadricTexture(pdiscoball, GL_TRUE);
  gluQuadricNormals(pdiscoball, GL_SMOOTH);
  gluSphere(pdiscoball,0.5,8,8);

  glDisable(GL_TEXTURE_2D);
  }

  void AlienWidget::rod() {
    gluCylinder(prod, 0.05, 0.05, 4.0, 16.0, 1.0);
}



void AlienWidget::floor(){
  // Here are the normals, correctly calculated for the floor and wall faces
  GLfloat normals[][3] = { {1., 0. ,0.}, {-1., 0., 0.}, {0., 0., 1.}, {0., 0., -1.}, {0, 1, 0}, {0, -1, 0} };
  glEnable(GL_TEXTURE_2D);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, _image.Width(), _image.Height(), 0, GL_RGB, GL_UNSIGNED_BYTE, _image.imageField());

  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
  glNormal3fv(normals[4]);
  glBegin(GL_POLYGON);
    glTexCoord2f(0.0, 0.0);
    glVertex3f(  1.0,  -1.0,  1.0);
    glTexCoord2f(1.0, 0.0);
    glVertex3f(  1.0,  -1.0, -1.0);
    glTexCoord2f(1.0, 1.0);
    glVertex3f( -1.0,  -1.0, -1.0);
    glTexCoord2f(0.0, 1.0);
    glVertex3f( -1.0,  -1.0,  1.0);
    // glDisable(GL_TEXTURE_2D);
  glEnd();
  glDisable(GL_TEXTURE_2D);
}

void AlienWidget::wall(){
  glEnable(GL_TEXTURE_2D);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, _image5.Width(), _image5.Height(), 0, GL_RGB, GL_UNSIGNED_BYTE, _image5.imageField());
glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
  glNormal3f(0.0,0.0,1.0);
  // glPolygonMode(GL_FRONT, GL_FILL);
  glBegin(GL_POLYGON);
    glTexCoord2f(0.0, 0.0);
    glVertex3f(-1.0, -1.0, -1.0);
    glTexCoord2f(1.0, 0.0);
    glVertex3f( 1.0, -1.0, -1.0);
    glTexCoord2f(1.0, 1.0);
    glVertex3f( 1.0,  1.0, -1.0);
    glTexCoord2f(0.0, 1.0);
    glVertex3f(-1.0,  1.0, -1.0);
  glEnd();
  glDisable(GL_TEXTURE_2D);

}

void AlienWidget::walltext1(){
  glEnable(GL_TEXTURE_2D);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, _image4.Width(), _image4.Height(), 0, GL_RGB, GL_UNSIGNED_BYTE, _image4.imageField());

  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
  glNormal3f(0.0,0.0,1.0);
  glBegin(GL_POLYGON);
    glTexCoord2f(0.0, 0.0);
    glVertex3f( -1.0, -1.0,  1.0);
    glTexCoord2f(1.0, 0.0);
    glVertex3f( -1.0, -1.0, -1.0);
    glTexCoord2f(1.0, 1.0);
    glVertex3f( -1.0,  1.0, -1.0);
    glTexCoord2f(0.0, 1.0);
    glVertex3f( -1.0,  1.0,  1.0);
  glEnd();
  glDisable(GL_TEXTURE_2D);
}

void AlienWidget::walltext2(){
  glEnable(GL_TEXTURE_2D);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, _image3.Width(), _image3.Height(), 0, GL_RGB, GL_UNSIGNED_BYTE, _image3.imageField());

glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
  glNormal3f(0.0,0.0,1.0);
  // glPolygonMode(GL_FRONT, GL_FILL);
// glPolygonMode(GL_FRONT, GL_FILL);
  glBegin(GL_POLYGON);
    glTexCoord2f(0.0, 0.0);
    glVertex3f( -1.0, -1.0,  1.0);
    glTexCoord2f(1.0, 0.0);
    glVertex3f( -1.0, -1.0, -1.0);
    glTexCoord2f(1.0, 1.0);
    glVertex3f( -1.0,  1.0, -1.0);
    glTexCoord2f(0.0, 1.0);
    glVertex3f( -1.0,  1.0,  1.0);
  glEnd();
  glDisable(GL_TEXTURE_2D);

}

void AlienWidget::text(){
  char buff[80];
      strcpy(buff,"PLANET EARTH '' DISCO ''");
      int len;
      len = strlen(buff);


      glMatrixMode( GL_PROJECTION );
      glPushMatrix();
      glLoadIdentity();

      gluOrtho2D( 0,300, 0, 300);

      glMatrixMode( GL_MODELVIEW );
      glPushMatrix();

      glLoadIdentity();
      glTranslatef(175.0,260.0,1.0);
      // glRotatef(20.,0.,1.,0.);
      glScalef(0.08,0.08,0.08);
      glRotatef(-30.,0.,0.,1.);
      // glRotatef(90.,0.,1.,0.);

      // glRasterPos3i(50,230,1);
      for ( int i = 0; i < len; ++i )
    {
        glutStrokeCharacter(GLUT_STROKE_ROMAN, buff[i]);
    }


    glPopMatrix();

    glMatrixMode( GL_PROJECTION );
    glPopMatrix();
    glMatrixMode( GL_MODELVIEW );
}

void AlienWidget::text2(){
  char buff2[80];
      strcpy(buff2, "\nft. DJ MARC :)");
      int len2;
      len2 = strlen(buff2);



      glMatrixMode( GL_PROJECTION );
      glPushMatrix();
      glLoadIdentity();

      gluOrtho2D( 0,300, 0, 300);

      glMatrixMode( GL_MODELVIEW );
      glPushMatrix();

      glLoadIdentity();

      glTranslatef(185.0,230.0,1.0);
      // glRotatef(20.,0.,1.,0.);
      glScalef(0.08,0.08,0.08);
      glRotatef(-30.,0.,0.,1.);
      // glRotatef(90.,0.,1.,0.);

      // glRasterPos3i(50,230,1);

    for ( int i = 0; i < len2; ++i )
  {
      glutStrokeCharacter(GLUT_STROKE_ROMAN, buff2[i]);
  }

    glPopMatrix();

    glMatrixMode( GL_PROJECTION );
    glPopMatrix();
    glMatrixMode( GL_MODELVIEW );
}


void AlienWidget::wall2(){

  glEnable(GL_TEXTURE_2D);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, _image5.Width(), _image5.Height(), 0, GL_RGB, GL_UNSIGNED_BYTE, _image5.imageField());
glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glNormal3f(0.0,0.0,1.0);
  // glPolygonMode(GL_FRONT, GL_FILL);
  glBegin(GL_POLYGON);
  glTexCoord2f(0.0, 0.0);
    glVertex3f( -1.0, -1.0,  1.0);
    glTexCoord2f(1.0, 0.0);
    glVertex3f( -1.0, -1.0, -1.0);
    glTexCoord2f(1.0, 1.0);
    glVertex3f( -1.0,  1.0, -1.0);
    glTexCoord2f(0.0, 1.0);
    glVertex3f( -1.0,  1.0,  1.0);
  glEnd();
  glDisable(GL_TEXTURE_2D);

}

void AlienWidget::body(){
  gluQuadricNormals(pbody, GL_SMOOTH);
  gluSphere(pbody,0.3,60.0,60.0);
}

void AlienWidget::antenna() {
  gluQuadricNormals(pantenna, GL_SMOOTH);
  gluCylinder(pantenna, 0.05, 0.05, 0.1, 16.0, 1.0);
}

void AlienWidget::eye() {
  gluQuadricNormals(peye, GL_SMOOTH);
  gluSphere(peye,0.08,60.0,60.0);
}




void AlienWidget::spaceship() {
  gluQuadricNormals(pspaceship, GL_SMOOTH);
  gluCylinder(pspaceship,0.5,0.6,0.9,60.0,60.0);
}

void AlienWidget::top() {
  gluQuadricNormals(ptop, GL_SMOOTH);
  gluCylinder(ptop,0.001,0.6,0.9,60.0,60.0);
}

void AlienWidget::discorod() {
gluCylinder(pdiscorod, 0.035, 0.035, 4.0, 16.0, 1.0);
}

// called every time the widget needs painting
void AlienWidget::paintGL()
	{ // paintGL()
	// clear the widget
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glEnable(GL_TEXTURE_2D);

  glShadeModel(GL_FLAT);
	// You must set the matrix mode to model view directly before enabling the depth test
  glMatrixMode(GL_MODELVIEW);

  glMaterialfv(GL_FRONT, GL_AMBIENT,   white);
  glMaterialfv(GL_FRONT, GL_DIFFUSE,   white);
  glMaterialfv(GL_FRONT, GL_SPECULAR,   white);
  glMaterialf(GL_FRONT, GL_SHININESS,   1);

  glPushMatrix();
    glTranslatef(2.0,2.0,2.0);
    glScalef(2.0,2.0,2.0);
    this->floor();
  glPopMatrix();

  materialStruct* p_front = &whiteShinyMaterials;

  glMaterialfv(GL_FRONT, GL_AMBIENT,    p_front->ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE,    p_front->diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR,   p_front->specular);
	glMaterialf(GL_FRONT, GL_SHININESS,   p_front->shininess);

// glutSolidTorus(2.0,2.0,1.0,1.0);
	glPushMatrix(); // save the global rotation state
	glTranslatef(1.4, 4.33, 1.6);
          glRotatef((double)angle,0.,1.,0.);
	this->discoball();
	glPopMatrix();  // restore the original matrix


  glPushMatrix();
  glTranslatef(0.9,2.6,2.8);
  glScalef(0.5,1.0,1.5);
  glRotatef(90.1,0.,0.,0.);
  // glRotatef((double)angle,1.,0.,0.);
  this->walltext1();
  glPopMatrix();


  glMaterialfv(GL_FRONT, GL_AMBIENT,   red);
	glMaterialfv(GL_FRONT, GL_DIFFUSE,   red);
	glMaterialfv(GL_FRONT, GL_SPECULAR,  red);
	glMaterialf(GL_FRONT, GL_SHININESS,  128);

	// glMaterialfv(GL_FRONT, GL_DIFFUSE, black);
  glPushMatrix();
  glTranslatef(1.4,8.92, 1.6);
  glRotatef(90.,1.,0.,0.);
  this->discorod();
  glPopMatrix();


  p_front = &jadeMaterials;

  glMaterialfv(GL_FRONT, GL_AMBIENT,    red);
  glMaterialfv(GL_FRONT, GL_DIFFUSE,  p_front->diffuse);
  glMaterialfv(GL_FRONT, GL_SPECULAR,   p_front->specular);
  glMaterialf(GL_FRONT, GL_SHININESS,   1);


  glPushMatrix();
  // glDisable(GL_TEXTURE_2D);
    glTranslatef(2.0,2.0,2.0);
    glScalef(2.5,2.0,2.0);
    // glutSolidTorus(0.4,0.8,5.0,50.0);
    this->wall();
      // this->text();
  glPopMatrix();


  glPushMatrix();
  glTranslatef(2.0,2.0,2.0);
  glScalef(2.0,2.0,2.5);
  this->wall2();
    glPopMatrix();

    glPushMatrix();
      this->text();
      this->text2();
      glPopMatrix();

      glPushMatrix();
      glTranslatef(1.25,2.2,4.25);
      glRotatef(90.,1.,0.,0.);
      this->antenna();
      glPopMatrix();

      glPushMatrix();
      glTranslatef(1.2,2.2,4.42);
      glRotatef(90.,1.,0.,0.);
      this->antenna();
      glPopMatrix();

    glPushMatrix();
      glTranslatef(2.5,0.0,2.5);
      glRotatef((double)angle,0.,1.,0.);
      glTranslatef(-2.5,-0.0,-2.0);

      glPushMatrix();
  // glScalef(0.2,0.5,0.2);
        glTranslatef(3.1,1.0,2.1);
        glScalef(1.0,1.0,1.5);
        this->body();
        glPopMatrix();



glMaterialfv(GL_FRONT, GL_AMBIENT,    blue);
glMaterialfv(GL_FRONT, GL_DIFFUSE,  blue);
glMaterialfv(GL_FRONT, GL_SPECULAR,  blue);
glMaterialf(GL_FRONT, GL_SHININESS,   1);

  glPushMatrix();
    glScalef(0.2,0.9,0.2);
    glTranslatef(15.9,0.6,10.0);
    glRotatef((double)angle,0.,1.,0.);
    glutSolidCube(0.5);
  glPopMatrix();

glPushMatrix();
  glScalef(0.2,0.9,0.2);
  glTranslatef(15.9,0.6,11.0);
  glRotatef((double)angle,0.,1.,0.);
  // glTranslatef(8.0,0.6,11.0);
  glutSolidCube(0.5);
glPopMatrix();

glPushMatrix();


glMaterialfv(GL_FRONT, GL_AMBIENT,  black );
glMaterialfv(GL_FRONT, GL_DIFFUSE,   black);
glMaterialfv(GL_FRONT, GL_SPECULAR,  black);
glMaterialf(GL_FRONT, GL_SHININESS,   1);

glPushMatrix();
glTranslatef(3.3,1.1,2.3);
// glScalef(1.0,1.0,1.5);
this->eye();
glPopMatrix();

glPushMatrix();
glTranslatef(3.34,1.1,2.0);
// glScalef(1.0,1.0,1.5);
this->eye();
glPopMatrix();


glMaterialfv(GL_FRONT, GL_AMBIENT,    cyan);
glMaterialfv(GL_FRONT, GL_DIFFUSE,  cyan);
glMaterialfv(GL_FRONT, GL_SPECULAR,   cyan);
glMaterialf(GL_FRONT, GL_SHININESS,   128);



glTranslatef(3.1,1.4,2.2);
glRotatef(90.,1.,0.,0.);
this->antenna();
glPopMatrix();

glTranslatef(3.1,1.4,2.0);
glRotatef(90.,1.,0.,0.);
this->antenna();
glPopMatrix();

glPopMatrix();
/////////////////////////


glPushMatrix();

  glTranslatef(1.2,1.8,4.3);
  glScalef(1.0,1.0,1.5);
  // glRotatef((double)angle,0.,1.,0.);
  // glRotatef((double)angle,0.,0.,1.);
  this->body();
glPopMatrix();

glMaterialfv(GL_FRONT, GL_AMBIENT,   blue);
glMaterialfv(GL_FRONT, GL_DIFFUSE,  blue);
glMaterialfv(GL_FRONT, GL_SPECULAR, blue);
glMaterialf(GL_FRONT, GL_SHININESS,   1);

glPushMatrix();
  glScalef(0.2,0.9,0.2);
  glTranslatef(1.0,0.4,15.5);
  glRotatef((double)angle,0.,1.,0.);
  // glRotatef((double)angle,0.,1.,0.);
  // glRotatef((double)angle,1.,0.,0.);
  glutSolidCube(0.5);
glPopMatrix();

glPushMatrix();
  glScalef(0.2,0.9,0.2);
  glTranslatef(1.0,0.4,16.5);
  glRotatef((double)angle,0.,1.,0.);
  // glTranslatef(8.0,0.6,11.0);
  glutSolidCube(0.5);
glPopMatrix();

glMaterialfv(GL_FRONT, GL_AMBIENT,  black );
glMaterialfv(GL_FRONT, GL_DIFFUSE,   black);
glMaterialfv(GL_FRONT, GL_SPECULAR,  black);
glMaterialf(GL_FRONT, GL_SHININESS,   1);

glPushMatrix();
glTranslatef(1.465,1.9,4.25);
// glScalef(1.0,1.0,1.5);
this->eye();
glPopMatrix();

glPushMatrix();
glTranslatef(1.445,1.9,4.5);
// glScalef(1.0,1.0,1.5);
this->eye();
glPopMatrix();

  glPushMatrix();
    glTranslatef(0.0, 0.05*flying, 0.0);

    p_front = &emeraldMaterials;
    glMaterialfv(GL_FRONT, GL_AMBIENT,  p_front->ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,  green);
    glMaterialfv(GL_FRONT, GL_SPECULAR, p_front->specular);
    glMaterialf(GL_FRONT, GL_SHININESS,   1);
//
//
glPushMatrix();
glTranslatef(1.0,1.2, 0.8);
glRotatef(90.,1.,0.,0.);
this->spaceship();
glPopMatrix();

glMaterialfv(GL_FRONT, GL_AMBIENT,  purple);
glMaterialfv(GL_FRONT, GL_DIFFUSE,  purple);
glMaterialfv(GL_FRONT, GL_SPECULAR, purple);
glMaterialf(GL_FRONT, GL_SHININESS,   1);

glPushMatrix();
glTranslatef(1.0,2.0, 0.8);
glRotatef(90.,1.,0.,0.);
this->top();
glPopMatrix();

glPushMatrix();
  glScalef(0.3,1.0,0.4);
  glTranslatef(5.8,0.4,1.5);
  glutSolidCube(0.5);
glPopMatrix();

glPushMatrix();
  glScalef(0.3,1.0,0.3);
  glTranslatef(1.1,0.4,3.9);
  glutSolidCube(0.5);
glPopMatrix();

glPushMatrix();
  glTranslatef(1.99,1.0,0.95);
    glRotatef(90.,0.,0.,1.);
    glScalef(0.3,0.8,0.3);
  // glRotatef(45.,1.,0.,0.);
  glutSolidCube(0.5);
glPopMatrix();

glPushMatrix();
  glTranslatef(0.6,0.8,1.3);
    glRotatef(90.,0.,0.,1.);
    glScalef(0.3,0.5,0.3);
  // glRotatef(45.,1.,0.,0.);
  glutSolidCube(0.5);
glPopMatrix();

p_front = &whiteShinyMaterials;

glMaterialfv(GL_FRONT, GL_AMBIENT,    p_front->ambient);
glMaterialfv(GL_FRONT, GL_DIFFUSE,    p_front->diffuse);
glMaterialfv(GL_FRONT, GL_SPECULAR,   p_front->specular);
glMaterialf(GL_FRONT, GL_SHININESS,   p_front->shininess);

glPushMatrix();
glTranslatef(1.4,0.9,0.8);
glScalef(0.259,0.259,0.659);
glRotatef(100.0,0.,1.,0.);
// glRotatef((double)angle,1.,0.,0.);
this->walltext2();
glPopMatrix();

glPopMatrix();



	glLoadIdentity();
       	gluLookAt(1.,1.,1., 0.0,0.0,0.0, 0.0,1.0,0.0);


	// flush to screen
	glFlush();

	} // paintGL()
