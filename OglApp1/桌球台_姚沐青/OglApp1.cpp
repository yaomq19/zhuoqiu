// OglApp1.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "windows.h"
#include "glut.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
using namespace std;
#define M_PI (3.14159265)
unsigned int texture_table;
unsigned int texture_wood;
unsigned int texture_metal;
void DrawObject();
void LightInit();
void Init();
void reshape(int width, int height);

int main(int argc, char* argv[])
{
	glutInit(&argc, argv); //GLUT库的初始化函数
    glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE); //设置窗口显示模式：这里是颜色模式、单缓存窗口
    glutInitWindowPosition(100, 0); //设置窗口相对于屏幕的位置
    glutInitWindowSize(700, 700); //设置窗口大小
    glutCreateWindow("OpenGL图形绘制"); //创建窗口并设置窗口名称
    Init();
    LightInit();
    glutReshapeFunc(reshape);
    glutDisplayFunc(DrawObject); //窗口绘制函数，传入参数为自定义的绘制方法
    //进入事件处理循环
    //注：到了此处之后只能处理GLUT事件，该循环无法返回，相当于死循环
    glutMainLoop();
    return 0;
}
//画桌面
void drawTable()
{
    //设置材质
    GLfloat defaultAmbient[] = { 0.7, 0.7, 0.7, 1.0f };
    glMaterialfv(GL_FRONT, GL_AMBIENT, defaultAmbient);
    GLfloat defaultDiffuse[] = { 0.2f, 0.2f, 0.2f, 1.0f };
    glMaterialfv(GL_FRONT, GL_DIFFUSE, defaultDiffuse);
    //绑定纹理
    glBindTexture(GL_TEXTURE_2D, texture_table);
    //绘制
    glPushMatrix();
    glRotatef(90, 0, 1, 0);
    glBegin(GL_POLYGON);
    glTexCoord2f(0, 0); glVertex3f(-1, 0, 0.5);
    glTexCoord2f(0, 1); glVertex3f(-1, 0, -0.5);
    glTexCoord2f(1, 1); glVertex3f(1, 0, -0.5);
    glTexCoord2f(1, 0); glVertex3f(1, 0, 0.5);
    glEnd();
    glPopMatrix();
}
//画一根木框
void drawWoodenFrame()
{
    glBegin(GL_POLYGON);
    glTexCoord2f(0, 0); glVertex3f(-1, 0.2, 0.2);
    glTexCoord2f(0, 1); glVertex3f(-1, 0.2, -0.2);
    glTexCoord2f(1, 1); glVertex3f(1, 0.2, -0.2);
    glTexCoord2f(1, 0); glVertex3f(1, 0.2, 0.2);

    glTexCoord2f(0, 0); glVertex3f(-1, 0.2, 0.2);
    glTexCoord2f(0, 1); glVertex3f(-1, 0.2, -0.2);
    glTexCoord2f(1, 1); glVertex3f(-1, -0.2, -0.2);
    glTexCoord2f(1, 0); glVertex3f(-1, -0.2, 0.2);

    glTexCoord2f(0, 0); glVertex3f(-1, 0.2, 0.2);
    glTexCoord2f(0, 1); glVertex3f(1, 0.2, 0.2);
    glTexCoord2f(1, 1); glVertex3f(1, -0.2, 0.2);
    glTexCoord2f(1, 0); glVertex3f(-1, -0.2, 0.2);

    glTexCoord2f(0, 0); glVertex3f(-1, -0.2, 0.2);
    glTexCoord2f(0, 1); glVertex3f(1, -0.2, 0.2);
    glTexCoord2f(1, 1); glVertex3f(1, -0.2, -0.2);
    glTexCoord2f(1, 0); glVertex3f(-1, -0.2, -0.2);

    glTexCoord2f(0, 0); glVertex3f(-1, -0.2, -0.2);
    glTexCoord2f(0, 1); glVertex3f(1, -0.2, -0.2);
    glTexCoord2f(1, 1); glVertex3f(1, 0.2, -0.2);
    glTexCoord2f(1, 0); glVertex3f(-1, 0.2, -0.2);

    glTexCoord2f(0, 0); glVertex3f(1, 0.2, 0.2);
    glTexCoord2f(0, 1); glVertex3f(1, 0.2, -0.2);
    glTexCoord2f(1, 1); glVertex3f(1, -0.2, -0.2);
    glTexCoord2f(1, 0); glVertex3f(1, -0.2, 0.2);
    glEnd();
}
//画全部木框
void drawWoodenFrames()
{
    //设置材质
    GLfloat defaultAmbient[] = { 0.7, 0.7, 0.7, 1.0f };
    glMaterialfv(GL_FRONT, GL_AMBIENT, defaultAmbient);
    GLfloat defaultDiffuse[] = { 0.2f, 0.2f, 0.2f, 1.0f };
    glMaterialfv(GL_FRONT, GL_DIFFUSE, defaultDiffuse);
    //绑定纹理
    glBindTexture(GL_TEXTURE_2D, texture_wood);
    //分别画出四根木框
    //第一根
    glPushMatrix();
    glTranslatef(-0.55,-0.03, 0.0);
    glScalef(0.2,0.2,1.0);
    glRotatef(90, 0, 1, 0);
    drawWoodenFrame();
    glPopMatrix();
    //第二根
    glPushMatrix();
    glTranslatef(0.55, -0.03, 0.0);
    glScalef(0.2, 0.2, 1.0);
    glRotatef(90, 0, 1, 0);
    drawWoodenFrame();
    glPopMatrix();
    //第三根
    glPushMatrix();
    glTranslatef(0.0, -0.03, 1.0);
    glScalef(0.59, 0.2, 0.2);
    glRotatef(0, 0, 1, 0);
    drawWoodenFrame();
    glPopMatrix();
    //第四根
    glPushMatrix();
    glTranslatef(0.0, -0.03, -1.0);
    glScalef(0.59, 0.2, 0.2);
    glRotatef(0, 0, 1, 0);
    drawWoodenFrame();
    glPopMatrix();
}
//画一根桌腿（圆柱）
void drawCylinder(float radius, float height, int segments) {
    float x, y, z;
    float angle;
    float step = 2 * M_PI / segments;

    glBegin(GL_TRIANGLE_STRIP);
    for (int i = 0; i <= segments; ++i) {
        angle = i * step;
        x = radius * cos(angle);
        y = radius * sin(angle);
        z = 0;
        glVertex3f(x, y, z);
        glVertex3f(x, y, z + height);
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(0, 0, 0);
    for (int i = 0; i <= segments; ++i) {
        angle = i * step;
        x = radius * cos(angle);
        y = radius * sin(angle);
        z = 0;
        glVertex3f(x, y, z);
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(0, 0, height);
    for (int i = 0; i <= segments; ++i) {
        angle = i * step;
        x = radius * cos(angle);
        y = radius * sin(angle);
        z = height;
        glVertex3f(x, y, z);
    }
    glEnd();
}
//画全部桌腿
void drawTableLegs()
{
    //设置材质
    GLfloat obsidian_ambient[] = { 0.05375f, 0.05f, 0.06625f, 1.0f };
    GLfloat obsidian_diffuse[] = { 0.18275f, 0.17f, 0.22525f, 1.0f };
    GLfloat obsidian_specular[] = { 0.332741f, 0.328634f, 0.346435f, 1.0f };
    GLfloat obsidian_shininess = 38.4f;
    glMaterialfv(GL_FRONT, GL_AMBIENT, obsidian_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, obsidian_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, obsidian_specular);
    glMaterialf(GL_FRONT, GL_SHININESS, obsidian_shininess);
    glBindTexture(GL_TEXTURE_2D, texture_metal);

    //分别绘制四根桌腿
    //第一根
    glPushMatrix();
    glTranslatef(-0.5, -0.1, 0.95);
    glScalef(0.5, 3.5, 0.5);
    glRotatef(90,1, 0, 0);
    drawCylinder(0.1, 0.5, 50);
    glPopMatrix();
    //第二根
    glPushMatrix();
    glTranslatef(0.5, -0.1, 0.95);
    glScalef(0.5, 3.5, 0.5);
    glRotatef(90, 1, 0, 0);
    drawCylinder(0.1, 0.5, 50);
    glPopMatrix();
    //第三根
    glPushMatrix();
    glTranslatef(-0.5, -0.1, -0.95);
    glScalef(0.5, 3.5, 0.5);
    glRotatef(90, 1, 0, 0);
    drawCylinder(0.1, 0.5, 50);
    glPopMatrix();
    //第四根
    glPushMatrix();
    glTranslatef(0.5, -0.1, -0.95);
    glScalef(0.5, 3.5, 0.5);
    glRotatef(90, 1, 0, 0);
    drawCylinder(0.1, 0.5, 50);
    glPopMatrix();
}
//画单个台球
void drawBall(float x,float y,float z,float r,GLfloat material[2][4],GLfloat shininess)
{
    //根据所传参数绘制球体
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material[0]);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material[1]);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material[2]);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shininess);
    glutSolidSphere(r, 100, 100);
}
//画全部台球
void drawBalls()
{
    //台球半径
    const float R = 0.03;
    //台球总数
    const int Num_Balls = 16;
    //台球位置信息（x，z坐标）
    const float pos[Num_Balls][2] = {
        0,          -0.5,
        0,          0.55,
        0 - R,      0.55 + 2 * R,
        0 + R,      0.55 + 2 * R,
        0 - 2 * R,  0.55 + 4 * R,
        0,          0.55 + 4 * R,
        0 + 2 * R,  0.55 + 4 * R,
        0 - 3 * R,  0.55 + 6 * R,
        0 - R,      0.55 + 6 * R,
        0 + R,      0.55 + 6 * R,
        0 + 3 * R,  0.55 + 6 * R,
        0 - 4 * R,  0.55 + 8 * R,
        0 - 2 * R,  0.55 + 8 * R,
        0 ,         0.55 + 8 * R,
        0 + 2 * R,  0.55 + 8 * R,
        0 + 4 * R,  0.55 + 8 * R
    };
    //台球材质信息
    GLfloat materials[Num_Balls][3][4] = {
        0.3, 0.3, 0.3, 0.3,
        1.0, 1.0, 1.0, 1.0,
        1.0, 1.0, 1.0, 1.0,

        255.0 / 255.0 * 0.5,    0.0 / 255.0 * 0.5,      0.0 / 255.0 * 0.5,      1.0,
        255.0 / 255.0,          0.0 / 255.0,            0.0 / 255.0,            1.0,
        1.0, 1.0, 1.0, 1.0,

        255.0 / 255.0 * 0.5,    153.0 / 255.0 * 0.5,    0.0 / 255.0,            1.0,
        255.0 / 255.0,          153.0 / 255.0,          0.0 / 255.0,            1.0,
        1.0, 1.0, 1.0, 1.0,

        17.0 / 255.0 * 0.5,     101.0 / 255.0 * 0.5,    154.0 / 255.0 * 0.5,    1.0,
        17.0 / 255.0,           101.0 / 255.0,          154.0 / 255.0,          1.0,
        1.0, 1.0, 1.0, 1.0,

        250.0 / 255.0 * 0.5,    101.0 / 255.0 * 0.5,    36.0 / 255.0 * 0.5,     1.0,
        250.0 / 255.0,          101.0 / 255.0,          36.0 / 255.0,           1.0,
        1.0, 1.0, 1.0, 1.0,

        0.1f, 0.1f, 0.1f, 1.0f,
        0.0, 0.0, 0.0, 1.0,
        1.0, 1.0, 1.0, 1.0,

        26.0 / 255.0 * 0.5,    104.0 / 255.0 * 0.5,    64.0 / 255.0 * 0.5,     1.0,
        26.0 / 255.0,          104.0 / 255.0,          64.0 / 255.0,           1.0,
        1.0, 1.0, 1.0, 1.0,

        245.0 / 255.0 * 0.5,    57.0 / 255.0 * 0.5,    28.0 / 255.0 * 0.5,     1.0,
        245.0 / 255.0,          57.0 / 255.0,          28.0 / 255.0,           1.0,
        1.0, 1.0, 1.0, 1.0,

        69.0 / 255.0 * 0.5,    183.0 / 255.0 * 0.5,    135.0 / 255.0 * 0.5,     1.0,
        69.0 / 255.0,          183.0 / 255.0,          135.0 / 255.0,           1.0,
        1.0, 1.0, 1.0, 1.0,

        71.0 / 255.0 * 0.5,    75.0 / 255.0 * 0.5,    76.0 / 255.0 * 0.5,     1.0,
        71.0 / 255.0,          75.0 / 255.0,          76.0 / 255.0,           1.0,
        1.0, 1.0, 1.0, 1.0,

        155.0 / 255.0 * 0.5,    30.0 / 255.0 * 0.5,    100.0 / 255.0 * 0.5,     1.0,
        155.0 / 255.0,          30.0 / 255.0,          100.0 / 255.0,           1.0,
        1.0, 1.0, 1.0, 1.0,

        41.0 / 255.0 * 0.5,    183.0 / 255.0 * 0.5,    203.0 / 255.0 * 0.5,     1.0,
        41.0 / 255.0,          183.0 / 255.0,          203.0 / 255.0,           1.0,
        1.0, 1.0, 1.0, 1.0,

        150.0 / 255.0 * 0.5,    194.0 / 255.0 * 0.5,    78.0 / 255.0 * 0.5,     1.0,
        150.0 / 255.0,          194.0 / 255.0,          78.0 / 255.0,           1.0,
        1.0, 1.0, 1.0, 1.0,

        231.0 / 255.0 * 0.5,    162.0 / 255.0 * 0.5,    63.0 / 255.0 * 0.5,     1.0,
        231.0 / 255.0,          162.0 / 255.0,          63.0 / 255.0,           1.0,
        1.0, 1.0, 1.0, 1.0,

        209.0 / 255.0 * 0.5,    26.0 / 255.0 * 0.5,    45.0 / 255.0 * 0.5,     1.0,
        209.0 / 255.0,          26.0 / 255.0,          45.0 / 255.0,           1.0,
        1.0, 1.0, 1.0, 1.0,

        26.0 / 255.0 * 0.5,    59.0 / 255.0 * 0.5,    50.0 / 255.0 * 0.5,     1.0,
        26.0 / 255.0,          59.0 / 255.0,          50.0 / 255.0,           1.0,
        1.0, 1.0, 1.0, 1.0,
    };
    //循环绘制
    for (int i = 0; i < Num_Balls; i++) {
        glPushMatrix();
        glTranslated(pos[i][0], R, pos[i][1]);
        GLfloat shininess = 16;
        //调用绘制单个台球的函数
        //参数分别为x，y，z坐标，半径，材质和镜面反射系数
        drawBall(0, 0, 0, R, materials[i], 64);
        glPopMatrix();
    }
}

void DrawObject(void) {
    //将初始的背景色设置为黑色
    glClearColor(0.0f, 0.5f, 0.5f, 1.0f);
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
    gluLookAt(0, 1, 2.3, 0, 0, 0, 0, 1, 0);
    
    //画桌面
    drawTable();
    //画木框
    drawWoodenFrames();
    //画桌腿
    drawTableLegs();
    //画球体
    drawBalls();
    //图形绘制到窗口
    glFlush();
}
void loadtexture()
{
    //垂直翻转
    stbi_set_flip_vertically_on_load(true);
    int width, height, channels;
    unsigned char* data;
    //生成纹理
    glGenTextures(1, &texture_table);
    glGenTextures(1, &texture_wood);
    //加载桌面纹理
    glBindTexture(GL_TEXTURE_2D, texture_table);
    // 设置纹理参数
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    data = stbi_load("./image/table.jpg", &width, &height, &channels, 0);
    if (data) {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    }
    stbi_image_free(data);
    data = NULL;
    //加载木纹理
    glBindTexture(GL_TEXTURE_2D, texture_wood);
    // 设置纹理参数
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    data = stbi_load("./image/wood.jpg", &width, &height, &channels, 0);
    if (data) {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    }
    stbi_image_free(data);
    data = NULL;
}
void Init()
{
    //开启纹理功能
    glEnable(GL_TEXTURE_2D);
    //加载纹理
    loadtexture();
}
void LightInit() {
    //光源位置 {x, y, z, w}
    //w=0.0时，为定向光源，即平行光
    //w=1.0时，为定点光源，
    GLfloat sun_light_position[] = { 0.0f, 1, -1, 1.0f };
    //环境光、漫反射光、镜面反射光 {R, G, B, A}
    GLfloat sun_light_ambient[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat sun_light_diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    GLfloat sun_light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    //设置光源属性
    glLightfv(GL_LIGHT0, GL_POSITION, sun_light_position);
    glLightfv(GL_LIGHT0, GL_AMBIENT, sun_light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, sun_light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, sun_light_specular);
    
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
}

void reshape(int width, int height)
{
    // 更新视口大小
    glViewport(0, 0, width, height);
}