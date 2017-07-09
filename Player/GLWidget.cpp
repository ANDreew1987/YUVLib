#include <QtWidgets>
#include <QtOpenGL>

#include "GLWidget.h"

GLWidget::GLWidget(QWidget *parent)
    : QGLWidget(QGLFormat(QGL::SampleBuffers), parent){
    currentFrame = nullptr;
    currentBitmap = nullptr;
}

GLWidget::~GLWidget(){
    DeleteFrame();
}

void GLWidget::CreateFrame(const YUVLib::YUVFormat format, const uint32_t width, const uint32_t height){
    switch(format){
    case YUVLib::YUVFormat::YUV_FORMAT_YUV420:
        currentFrame = new YUVLib::YUV420Frame();
        break;
    }
    currentFrame->Create(width, height);
    currentBitmap = new YUVLib::Bitmap();
    currentBitmap->Create(width, height);
}

void GLWidget::ApplyCurentFrame(){
    YUVLib::YUV420ToRGB_BT601_STD_ST(currentFrame, currentBitmap);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexImage2D(
                GL_TEXTURE_2D,
                0,
                GL_RGBA,
                currentBitmap->GetWidth(),
                currentBitmap->GetHeight(),
                0,
                GL_RGBA,
                GL_UNSIGNED_BYTE,
                currentBitmap->Data()
    );
}

void GLWidget::DeleteFrame(){
    if(currentFrame != nullptr){
        delete currentFrame;
        currentFrame = nullptr;
    }
    if(currentBitmap != nullptr){
        delete currentBitmap;
        currentBitmap = nullptr;
    }
}

void GLWidget::initializeGL(){
    glClearColor(0.9375f, 0.9375f, 0.9375f, 1.0f);
    glEnable(GL_TEXTURE_2D);
    glGenTextures( 2, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
}

void GLWidget::paintGL(){
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -10.0);
    glBindTexture( GL_TEXTURE_2D, texture);
    glBegin(GL_QUADS);

    glTexCoord2f( 0.f, 1.f );
    glVertex3f(-1.0, -1.0, 0.0);

    glTexCoord2f( 0.f, 0.f );
    glVertex3f(-1.0, 1.0, 0.0);

    glTexCoord2f( 1.f, 0.f );
    glVertex3f( 1.0, 1.0, 0.0);

    glTexCoord2f( 1.f, 1.f );
    glVertex3f( 1.0, -1.0, 0.0);
    glEnd();
}

void GLWidget::resizeGL(int width, int height){
    float kBmp = width / height;
    if(currentBitmap != nullptr && currentBitmap->GetWidth() > 0 && currentBitmap->GetHeight() > 0){
        kBmp = (float)currentBitmap->GetWidth() / (float)currentBitmap->GetHeight();
    }
    float kWin = width / height;
    if(kWin >= kBmp){
        float wBmp = height * kBmp;
        glViewport((width - wBmp) / 2.0f, 0, wBmp, height);
    }
    else{
        float hBmp = width / kBmp;
        glViewport(0, (height - hBmp) / 2.0f, width, hBmp);
    }

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, +1.0, -1.0, +1.0, 1.0, 15.0);
    glMatrixMode(GL_MODELVIEW);
}
