#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QOpenGLFunctions>
#include <QFileDialog>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow){
    ui->setupUi(this);
    timer = new QTimer();
    settings = new ChangeParams(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::RenderFrame);
    connect(ui->menuFile, &QMenu::triggered, this, &MainWindow::OpenFile);
    connect(ui->startButton, &QPushButton::clicked, this, &MainWindow::PlayVideo);
    connect(ui->pauseButton, &QPushButton::clicked, this, &MainWindow::PauseVideo);
    connect(ui->stopButton, &QPushButton::clicked, this, &MainWindow::StopVideo);
    connect(ui->settingsButton, &QPushButton::clicked, this, &MainWindow::GetSettingsWindow);
    connect(settings, &ChangeParams::SendSettings, this, &MainWindow::SetSettings);
}

MainWindow::~MainWindow(){
    delete settings;
    delete timer;
    delete ui;
}

void MainWindow::OpenFile(){
    reader.Close();
    QString filename = QFileDialog::getOpenFileName(
        this,
        tr("Open YUV File"),
        QDir::currentPath(),
        tr("YUV files (*.yuv)")
    );
    if(!filename.isNull()){
      if(reader.Open(filename.toStdString().c_str())){
          reader.SetFrameParams(746, 420);
          ui->outCanvas->CreateFrame(YUVLib::YUV_FORMAT_YUV420, 746, 420);
          reader >> ui->outCanvas->CurrentFrame();
          ui->outCanvas->ApplyCurentFrame();
          currentFrameN = 0;
          ui->frameSlider->setMaximum(reader.GetFramesCount());
      }
    }
}

void MainWindow::PlayVideo(){
    timer->start(33);
}

void MainWindow::PauseVideo(){
    timer->stop();
}

void MainWindow::StopVideo(){
    timer->stop();
    currentFrameN = 0;
    ui->frameSlider->setValue(currentFrameN);
    reader.MoveToFrame(currentFrameN);
    RenderFrame();
}

void MainWindow::RenderFrame(){
    if(currentFrameN < reader.GetFramesCount()){
        reader >> ui->outCanvas->CurrentFrame();
        ui->outCanvas->ApplyCurentFrame();
        emit ui->outCanvas->repaint();
        currentFrameN++;
        ui->frameSlider->setValue(currentFrameN);
    }
    else{
        StopVideo();
    }
}

void MainWindow::MoveToFrame(){
    PauseVideo();
    currentFrameN = ui->frameSlider->value();
    reader.MoveToFrame(currentFrameN);
    RenderFrame();
}

void MainWindow::GetSettingsWindow(){
    settings->show();
}

void MainWindow::SetSettings(const uint32_t width, const uint32_t height, const YUVLib::YUVFormat format, const uint32_t fps)
{
    StopVideo();
    reader.SetFrameParams(width, height, format);
    ui->outCanvas->DeleteFrame();
    ui->outCanvas->CreateFrame(format, width, height);
    reader >> ui->outCanvas->CurrentFrame();
    ui->outCanvas->ApplyCurentFrame();
    currentFrameN = 0;
    ui->frameSlider->setMaximum(reader.GetFramesCount());
    RenderFrame();
}
