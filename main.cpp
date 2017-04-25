#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <iostream>
#include <math.h>
#include <stdlib.h>

using namespace std;

#define NP 4000
#define AGE 200

//DECLARACION DE VARIABLES A UTILIZAR
float winWid,winHeight;
float rx,ry; // variables que representan las coordenadas
int vf[5]={2}; // venctor donde almacenaremos el id de la imagen a imprimir


//METODO QUE PERMITE IMPRIMIR LA IMAGEN A MOSTRAR
void menu(int opc){
    vf[1]=opc; // En el vector VF, en su campo 1, se almacenara el id de la imagen
    glPushMatrix();
    //glColor3f(1.0,1.0,0.0); 
    glTranslated((rx*0.001),(ry*0.001),0.0); // ubicando la posicion donde se imprimira la imagen
    // rx, ry, se multiplica por 0.001, porque sus valores son centenas y al hacer esa operacion
    // permite obtener su valor en decimal ("0.000")
    GLfloat mat_ambient[] = { 0.329412f, 0.723529f, 0.127451f,1.0f };
    GLfloat mat_diffuse[] = { 0.180392f, 0.768627f, 0.113725f, 1.0f };
    GLfloat mat_specular[] = { 0.992157f, 0.41176f, 0.207843f, 1.0f };
    GLfloat shine[] = {29.8974f};
    
     //setMaterial
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, shine);
    
    switch(opc){ // checando la imagen elegida para mostrar
       case 1:
           cerr << "Esfera\n";
           glRotatef (40,0.1,0.1,0.0);
           glutSolidSphere(0.2,8,8);
           break;

       case 2:
           cerr << "Cubo\n";
           glRotatef (60,0.1,0.1,0.0);
           glutSolidCube(0.18);
           break;
       case 3:
           cerr << "Cono\n";
           glRotatef (60,0.1,0.1,0.0);
           glutSolidCone(0.1,0.2,6,6);
           break;
       case 4:
           cerr << "Tetera\n";
           glutSolidTeapot(0.1);
           break;
       case 5:
           cerr << "Tetrahedro \n";
           glScalef(0.13, 0.13, 0.0);
           glRotatef(60,0.1,0.1,0.0);
           glutSolidTetrahedron();
           break;
       case 6:
           cerr << "Octahedro \n";
           glScalef(0.13, 0.13, 0.0);
           glRotatef(60,0.1,0.1,0.0);
           glutSolidOctahedron();

        break;
       case 7:
           cerr << "Dodecahedro \n";
           glScalef(0.13, 0.13, 0.0);
           glRotatef(60,0.1,0.1,0.0);
           glutSolidDodecahedron();
            break;
       case 8:
           cerr << "Icosahedro \n";
           glScalef(0.13, 0.13, 0.0);
           glRotatef(60,0.1,0.1,0.0);
           glutSolidIcosahedron();
           break;
       case 9:
           cerr << "Torus \n";
           glScalef(0.13, 0.13, 0.0);
           glRotatef(60,0.1,0.1,0.0);
           glutSolidTorus(0.5,0.4,5,2);
           break;
   }

   glPopMatrix();
   glFlush();
}

// METODO QUE REPINTA LA PANTALLA
void redraw( void ){
    //Limpiando la pantalla
    glClear(GL_COLOR_BUFFER_BIT);
    // Haciendo uso del metodo menu, pasandoles como paramentro el id
    // de la figura que se eligio, así pues cada vez que se pueda el cursor
    // dicha imagen se repintara
     menu(vf[1]);
    glutSwapBuffers();
}

// OBTENIENDO EL LA POSICION DEL RATON AL HACER CLICK REDECHO
void motion(int x, int y){
    //cerr << "motion. x:" << x << ", y:" << y << " \n";
     rx = float(x);
     ry = winHeight - float(y);

}

// OBTENIENDO EL LA POSICION DEL RATON AL HACER MOVER EL CURSO Y PRESIONAR EL CLICK DERECHO
void mousebutton(int button, int state, int x, int y){

    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
        rx = float(x);
        ry = winHeight - float(y);
       //	 redraw();
    }
}

void init(void)
{
// Ubicamos la fuente de luz en el punto
    GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
	GLfloat luz_ambiental[] = { 0.2, 0.2, 0.2, 1.0 };


// Activamos la fuente de luz
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glDepthFunc(GL_LESS);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE);
    glShadeModel(GL_SMOOTH);
    glDisable(GL_COLOR_MATERIAL);

	glLightfv(GL_LIGHT0,GL_POSITION,light_position);
// Queremos que se dibujen las caras frontales
// y con un color solido de relleno.
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

}


int main(int argc, char *argv[]){
    winWid = 600.0;
    winHeight = 400.0;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
    glutCreateWindow(" ");
    glutPositionWindow(200,100);
    glutReshapeWindow(int(winWid),int(winHeight));


    // CREACION DEL MENU PARA ELEGIR ALGUNA IMAGEN
    glutCreateMenu(menu);
      glutAddMenuEntry("ESFERA",1);
      glutAddMenuEntry("CUBO",2);
      glutAddMenuEntry("CONO",3);
      glutAddMenuEntry("TETERA",4);
      glutAddMenuEntry("TETRAHEDRO",5);
      glutAddMenuEntry("OCTAHEDRO",6);
      glutAddMenuEntry("DODECAHEDRO",7);
      glutAddMenuEntry("ICOSAHEDRO",8);
      glutAddMenuEntry("TORUS",9);
      glutAttachMenu(GLUT_RIGHT_BUTTON); // Eligiendo con el click derecho del raton

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    init();
    glutDisplayFunc(redraw);
    glutIdleFunc(redraw);
    glutMotionFunc(motion);
    glutMouseFunc(mousebutton);
    glutMainLoop();

    return 0;
}
