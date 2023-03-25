// OglApp1.cpp : �������̨Ӧ�ó������ڵ㡣
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
	glutInit(&argc, argv); //GLUT��ĳ�ʼ������
    glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE); //���ô�����ʾģʽ����������ɫģʽ�������洰��
    glutInitWindowPosition(100, 0); //���ô����������Ļ��λ��
    glutInitWindowSize(700, 700); //���ô��ڴ�С
    glutCreateWindow("OpenGLͼ�λ���"); //�������ڲ����ô�������
    Init();
    LightInit();
    glutReshapeFunc(reshape);
    glutDisplayFunc(DrawObject); //���ڻ��ƺ������������Ϊ�Զ���Ļ��Ʒ���
    //�����¼�����ѭ��
    //ע�����˴˴�֮��ֻ�ܴ���GLUT�¼�����ѭ���޷����أ��൱����ѭ��
    glutMainLoop();
    return 0;
}
//������
void drawTable()
{
    //���ò���
    GLfloat defaultAmbient[] = { 0.7, 0.7, 0.7, 1.0f };
    glMaterialfv(GL_FRONT, GL_AMBIENT, defaultAmbient);
    GLfloat defaultDiffuse[] = { 0.2f, 0.2f, 0.2f, 1.0f };
    glMaterialfv(GL_FRONT, GL_DIFFUSE, defaultDiffuse);
    //������
    glBindTexture(GL_TEXTURE_2D, texture_table);
    //����
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
//��һ��ľ��
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
//��ȫ��ľ��
void drawWoodenFrames()
{
    //���ò���
    GLfloat defaultAmbient[] = { 0.7, 0.7, 0.7, 1.0f };
    glMaterialfv(GL_FRONT, GL_AMBIENT, defaultAmbient);
    GLfloat defaultDiffuse[] = { 0.2f, 0.2f, 0.2f, 1.0f };
    glMaterialfv(GL_FRONT, GL_DIFFUSE, defaultDiffuse);
    //������
    glBindTexture(GL_TEXTURE_2D, texture_wood);
    //�ֱ𻭳��ĸ�ľ��
    //��һ��
    glPushMatrix();
    glTranslatef(-0.55,-0.03, 0.0);
    glScalef(0.2,0.2,1.0);
    glRotatef(90, 0, 1, 0);
    drawWoodenFrame();
    glPopMatrix();
    //�ڶ���
    glPushMatrix();
    glTranslatef(0.55, -0.03, 0.0);
    glScalef(0.2, 0.2, 1.0);
    glRotatef(90, 0, 1, 0);
    drawWoodenFrame();
    glPopMatrix();
    //������
    glPushMatrix();
    glTranslatef(0.0, -0.03, 1.0);
    glScalef(0.59, 0.2, 0.2);
    glRotatef(0, 0, 1, 0);
    drawWoodenFrame();
    glPopMatrix();
    //���ĸ�
    glPushMatrix();
    glTranslatef(0.0, -0.03, -1.0);
    glScalef(0.59, 0.2, 0.2);
    glRotatef(0, 0, 1, 0);
    drawWoodenFrame();
    glPopMatrix();
}
//��һ�����ȣ�Բ����
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
//��ȫ������
void drawTableLegs()
{
    //���ò���
    GLfloat obsidian_ambient[] = { 0.05375f, 0.05f, 0.06625f, 1.0f };
    GLfloat obsidian_diffuse[] = { 0.18275f, 0.17f, 0.22525f, 1.0f };
    GLfloat obsidian_specular[] = { 0.332741f, 0.328634f, 0.346435f, 1.0f };
    GLfloat obsidian_shininess = 38.4f;
    glMaterialfv(GL_FRONT, GL_AMBIENT, obsidian_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, obsidian_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, obsidian_specular);
    glMaterialf(GL_FRONT, GL_SHININESS, obsidian_shininess);
    glBindTexture(GL_TEXTURE_2D, texture_metal);

    //�ֱ�����ĸ�����
    //��һ��
    glPushMatrix();
    glTranslatef(-0.5, -0.1, 0.95);
    glScalef(0.5, 3.5, 0.5);
    glRotatef(90,1, 0, 0);
    drawCylinder(0.1, 0.5, 50);
    glPopMatrix();
    //�ڶ���
    glPushMatrix();
    glTranslatef(0.5, -0.1, 0.95);
    glScalef(0.5, 3.5, 0.5);
    glRotatef(90, 1, 0, 0);
    drawCylinder(0.1, 0.5, 50);
    glPopMatrix();
    //������
    glPushMatrix();
    glTranslatef(-0.5, -0.1, -0.95);
    glScalef(0.5, 3.5, 0.5);
    glRotatef(90, 1, 0, 0);
    drawCylinder(0.1, 0.5, 50);
    glPopMatrix();
    //���ĸ�
    glPushMatrix();
    glTranslatef(0.5, -0.1, -0.95);
    glScalef(0.5, 3.5, 0.5);
    glRotatef(90, 1, 0, 0);
    drawCylinder(0.1, 0.5, 50);
    glPopMatrix();
}
//������̨��
void drawBall(float x,float y,float z,float r,GLfloat material[2][4],GLfloat shininess)
{
    //��������������������
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material[0]);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material[1]);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material[2]);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shininess);
    glutSolidSphere(r, 100, 100);
}
//��ȫ��̨��
void drawBalls()
{
    //̨��뾶
    const float R = 0.03;
    //̨������
    const int Num_Balls = 16;
    //̨��λ����Ϣ��x��z���꣩
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
    //̨�������Ϣ
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
    //ѭ������
    for (int i = 0; i < Num_Balls; i++) {
        glPushMatrix();
        glTranslated(pos[i][0], R, pos[i][1]);
        GLfloat shininess = 16;
        //���û��Ƶ���̨��ĺ���
        //�����ֱ�Ϊx��y��z���꣬�뾶�����ʺ;��淴��ϵ��
        drawBall(0, 0, 0, R, materials[i], 64);
        glPopMatrix();
    }
}

void DrawObject(void) {
    //����ʼ�ı���ɫ����Ϊ��ɫ
    glClearColor(0.0f, 0.5f, 0.5f, 1.0f);
    //�����ɫ�������Ȼ���
    glEnable(GL_DEPTH_TEST);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //ͶӰ����
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, 1, 0.1, 400);
    //MV����
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0, 1, 2.3, 0, 0, 0, 0, 1, 0);
    
    //������
    drawTable();
    //��ľ��
    drawWoodenFrames();
    //������
    drawTableLegs();
    //������
    drawBalls();
    //ͼ�λ��Ƶ�����
    glFlush();
}
void loadtexture()
{
    //��ֱ��ת
    stbi_set_flip_vertically_on_load(true);
    int width, height, channels;
    unsigned char* data;
    //��������
    glGenTextures(1, &texture_table);
    glGenTextures(1, &texture_wood);
    //������������
    glBindTexture(GL_TEXTURE_2D, texture_table);
    // �����������
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
    //����ľ����
    glBindTexture(GL_TEXTURE_2D, texture_wood);
    // �����������
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
    //����������
    glEnable(GL_TEXTURE_2D);
    //��������
    loadtexture();
}
void LightInit() {
    //��Դλ�� {x, y, z, w}
    //w=0.0ʱ��Ϊ�����Դ����ƽ�й�
    //w=1.0ʱ��Ϊ�����Դ��
    GLfloat sun_light_position[] = { 0.0f, 1, -1, 1.0f };
    //�����⡢������⡢���淴��� {R, G, B, A}
    GLfloat sun_light_ambient[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat sun_light_diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    GLfloat sun_light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    //���ù�Դ����
    glLightfv(GL_LIGHT0, GL_POSITION, sun_light_position);
    glLightfv(GL_LIGHT0, GL_AMBIENT, sun_light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, sun_light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, sun_light_specular);
    
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
}

void reshape(int width, int height)
{
    // �����ӿڴ�С
    glViewport(0, 0, width, height);
}