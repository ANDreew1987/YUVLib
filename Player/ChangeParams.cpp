#include "ChangeParams.h"
#include "ui_ChangeParams.h"

ChangeParams::ChangeParams(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChangeParams)
{
    ui->setupUi(this);
    ui->formatsComboBox->addItem("yuv420");
    m_format = YUVLib::YUVFormat::YUV_FORMAT_YUV420;
    connect(ui->okButton, &QPushButton::clicked, this, &ChangeParams::ReadSettings);
    connect(ui->cancelButton, &QPushButton::clicked, this, &ChangeParams::Cancel);
}

ChangeParams::~ChangeParams()
{
    delete ui;
}

void ChangeParams::ReadSettings()
{
    uint32_t frameWidth = ui->widthEdit->text().toUInt();
    uint32_t frameHeight = ui->heightEdit->text().toInt();
    uint32_t fps = ui->fpsEdit->text().toInt();

    emit SendSettings(frameWidth, frameHeight, m_format, fps);
}

void ChangeParams::Cancel()
{
    close();
}

void ChangeParams::SetFormat()
{

}
