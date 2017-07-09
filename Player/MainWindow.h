#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ChangeParams.h"
#include "YUVLib.hpp"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    ChangeParams *settings;
    QTimer *timer;
    YUVLib::YUVReader reader;
    uint32_t currentFrameN;
public slots:
    void OpenFile();
    void PlayVideo();
    void PauseVideo();
    void StopVideo();
    void RenderFrame();
    void MoveToFrame();
    void GetSettingsWindow();
    void SetSettings(const uint32_t width, const uint32_t height, const YUVLib::YUVFormat format, const uint32_t fps);
};

#endif // MAINWINDOW_H
