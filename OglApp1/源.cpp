#include "stdafx.h"
#include "windows.h"
#include "glut.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
unsigned int texture1;
void DrawObject();
void LightInit();
void Init();
int main(int argc, char* argv[])
{

    glutInit(&argc, argv); //GLUT库的初始化函数
    glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE); //设置窗口显示模式：这里是颜色模式、单缓存窗口
    glutInitWindowPosition(100, 0); //设置窗口相对于屏幕的位置
    glutInitWindowSize(600, 600); //设置窗口大小
    glutCreateWindow("OpenGL图形绘制"); //创建窗口并设置窗口名称
    Init();
    LightInit();
    glutDisplayFunc(DrawObject); //窗口绘制函数，传入参数为自定义的绘制方法
    //进入事件处理循环
    //注：到了此处之后只能处理GLUT事件，该循环无法返回，相当于死循环
    glutMainLoop();
    return 0;
}

void DrawObject(void) {
    //坐标复位
    //glLoadIdentity();
    //将初始的背景色设置为黑色
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    //清除颜色缓存和深度缓存
    glEnable(GL_DEPTH_TEST);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //投影矩阵
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, 1, 0.1, 400);

    //MV矩阵
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0, 0, 3, 0, 0, 0, 0, 1, 0);

    glBindTexture(GL_TEXTURE_2D, texture1);
    glBegin(GL_POLYGON);
    glTexCoord2f(0.0, 0.0);
    glVertex3f(-1, -1, 1);
    glTexCoord2f(0.0, 1.0);
    glVertex3f(-1, 1, -1);
    glTexCoord2f(1.0, 1.0);
    glVertex3f(1, 1, -1);
    glTexCoord2f(1.0, 0.0);
    glVertex3f(1, -1, 1);
    glEnd();
    //图形绘制到窗口
    glFlush();
}
void Init()
{

    glGenTextures(1, &texture1);
    glBindTexture(GL_TEXTURE_2D, texture1);
    // 设置纹理参数
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    int width, height, channels;
    stbi_set_flip_vertically_on_load(true);
    unsigned char* data = stbi_load("3.png", &width, &height, &channels, 0);
    if (data) {
        glTexImage2D(
            GL_TEXTURE_2D,
            0,
            GL_RGB,
            width,
            height,
            0,
            GL_RGB,
            GL_UNSIGNED_BYTE,
            data
        );
    }
    stbi_image_free(data);
}
void LightInit() {
    //光源位置 {x, y, z, w}
    //w=0.0时，为定向光源，即平行光
    //w=1.0时，为定点光源，
    GLfloat sun_light_position[] = { 0.0f, 0.0f, 2.0f, 1.0f };
    //环境光、漫反射光、镜面反射光 {R, G, B, A}
    GLfloat sun_light_ambient[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    GLfloat sun_light_diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    GLfloat sun_light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    //设置光源属性
    glLightfv(GL_LIGHT0, GL_POSITION, sun_light_position);
    glLightfv(GL_LIGHT0, GL_AMBIENT, sun_light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, sun_light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, sun_light_specular);
    //打开光照
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
}