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

    glutInit(&argc, argv); //GLUT��ĳ�ʼ������
    glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE); //���ô�����ʾģʽ����������ɫģʽ�������洰��
    glutInitWindowPosition(100, 0); //���ô����������Ļ��λ��
    glutInitWindowSize(600, 600); //���ô��ڴ�С
    glutCreateWindow("OpenGLͼ�λ���"); //�������ڲ����ô�������
    Init();
    LightInit();
    glutDisplayFunc(DrawObject); //���ڻ��ƺ������������Ϊ�Զ���Ļ��Ʒ���
    //�����¼�����ѭ��
    //ע�����˴˴�֮��ֻ�ܴ���GLUT�¼�����ѭ���޷����أ��൱����ѭ��
    glutMainLoop();
    return 0;
}

void DrawObject(void) {
    //���긴λ
    //glLoadIdentity();
    //����ʼ�ı���ɫ����Ϊ��ɫ
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
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
    //ͼ�λ��Ƶ�����
    glFlush();
}
void Init()
{

    glGenTextures(1, &texture1);
    glBindTexture(GL_TEXTURE_2D, texture1);
    // �����������
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
    //��Դλ�� {x, y, z, w}
    //w=0.0ʱ��Ϊ�����Դ����ƽ�й�
    //w=1.0ʱ��Ϊ�����Դ��
    GLfloat sun_light_position[] = { 0.0f, 0.0f, 2.0f, 1.0f };
    //�����⡢������⡢���淴��� {R, G, B, A}
    GLfloat sun_light_ambient[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    GLfloat sun_light_diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    GLfloat sun_light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    //���ù�Դ����
    glLightfv(GL_LIGHT0, GL_POSITION, sun_light_position);
    glLightfv(GL_LIGHT0, GL_AMBIENT, sun_light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, sun_light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, sun_light_specular);
    //�򿪹���
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
}