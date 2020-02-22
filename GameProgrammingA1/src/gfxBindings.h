#ifndef __GFX_BINDINGS_H__
#define __GFX_BINDINGS_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "graphics.h"

enum colour {GREEN = 1, BLUE, RED, BLACK, WHITE, PURPLE, ORANGE, YELLOW, BROWN = 9, GREY, CLOUD_WHITE, CLOUD_GREY, GRASS_GREEN};

// Function declarations for gfx c file
extern GLubyte world[WORLDX][WORLDY][WORLDZ];
	/* flag which is set to 1 when flying behaviour is desired */
extern int flycontrol;
	/* flag used to indicate that the test world should be used */
extern int testWorld;
	/* flag to print out frames per second */
extern int fps;
	/* flag to indicate the space bar has been pressed */
extern int space;
	/* flag indicates the program is a client when set = 1 */
extern int netClient;
	/* flag indicates the program is a server when set = 1 */
extern int netServer; 
	/* size of the window in pixels */
extern int screenWidth, screenHeight;
	/* flag indicates if map is to be printed */
extern int displayMap;
	/* flag indicates use of a fixed viewpoint */
extern int fixedVP;

	/* frustum corner coordinates, used for visibility determination  */
extern float corners[4][3];


void createPlayer(int number, float x, float y, float z, float playerroty);
void setPlayerPosition(int number, float x, float y, float z, float playerroty);
void hidePlayer(int number);
void showPlayer(int number);
void initMobArray();
void createMob(int number, float x, float y, float z, float mobroty);
void setMobPosition(int number, float x, float y, float z, float mobroty);
void hideMob(int number);
void showMob(int number);
void initTubeArray();
void createTube(int number, float bx, float by, float bz,
	float ex, float ey, float ez, int colour);
void hideTube(int number);
void showTube(int number);
void setLightPosition(GLfloat x, GLfloat y, GLfloat z);
GLfloat* getLightPosition();
void getViewPosition(float *x, float *y, float *z);
void setViewPosition(float x, float y, float z);
void getOldViewPosition(float *x, float *y, float *z);
void setOldViewPosition(float x, float y, float z);
void setViewOrientation(float xaxis, float yaxis, float zaxis);
void getViewOrientation(float *xaxis, float *yaxis, float *zaxis);
void addDisplayList(int x, int y, int z);
void init (void);
void setObjectColour(int colourID);
void drawCube(int i, int j, int k);
void display (void);
void reshape(int w, int h);
void keyboard(unsigned char key, int x, int y);
void loadTexture();
void motion(int x, int y);
void passivemotion(int x, int y);
void graphicsInit(int *argc, char **argv);
int setUserColour(int id, GLfloat ambRed, GLfloat ambGreen, GLfloat ambBlue,
  GLfloat ambAlpha, GLfloat difRed, GLfloat difGreen, GLfloat difBlue,
  GLfloat difAlpha);
void unsetUserColour(int id);
void getUserColour(int id, GLfloat *ambRed, GLfloat *ambGreen, GLfloat *ambBlue,
  GLfloat *ambAlpha, GLfloat *difRed, GLfloat *difGreen, GLfloat *difBlue,
  GLfloat *difAlpha);


#ifdef __cplusplus
}
#endif

#endif //__GFX_BINDINGS_H__
