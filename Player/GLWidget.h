#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>
#include "YUVLib.hpp"

class GLWidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit GLWidget(QWidget *parent = nullptr);
    ~GLWidget();

signals:

public:
    void CreateFrame(const YUVLib::YUVFormat format, const uint32_t width, const uint32_t height);
    YUVLib::YUVFrame *CurrentFrame(){
        return currentFrame;
    }
    void ApplyCurentFrame();
    void DeleteFrame();
protected:
    GLuint texture;
    YUVLib::YUVFrame * currentFrame;
    YUVLib::Bitmap *currentBitmap;

    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);

};

#endif // GLWIDGET_H
