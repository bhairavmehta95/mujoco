#ifndef _RENDER_H
#define _RENDER_H

#include "mujoco.h"
#include "glfw3.h"

typedef struct render_context_t {
  mjModel* m;
  mjData* d;
	mjvScene scn;
	mjrContext con;
	mjvCamera cam;
	mjvOption opt;
	int lastx;
	int lasty;
} RenderContext;

GLFWwindow *initGlfw();
mjModel *loadModel(const char *filepath);
int initMujoco(RenderContext * context);
int renderOffscreen(int camid, unsigned char *rgb, 
    int height, int width, RenderContext *);
int renderOnscreen(int camid, GLFWwindow * window, RenderContext * context);
int closeMujoco(RenderContext * context);

#endif
