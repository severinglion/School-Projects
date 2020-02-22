
#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#endif

        /* world size and storage array */
#define WORLDX 100
#define WORLDY 50
#define WORLDZ 100

#ifdef __cplusplus
extern "C" {
#endif

	/* functions draw 2D images */
void  draw2Dline(int, int, int, int, int);
void  draw2Dbox(int, int, int, int);
void  draw2Dtriangle(int, int, int, int, int, int);
void  set2Dcolour(float []);

#ifdef __cplusplus
}
#endif

	/* list of cubes to draw with each screen update */
#define MAX_DISPLAY_LIST 500000

	/* maximum number of user defined colours */
#define NUMBERCOLOURS 100

