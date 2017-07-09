#ifndef CHANGEPARAMS_H
#define CHANGEPARAMS_H

#include <QDialog>
#include "YUVLib.hpp"

namespace Ui {
class ChangeParams;
}

class ChangeParams : public QDialog
{
    Q_OBJECT

public:
    explicit ChangeParams(QWidget *parent = 0);
    ~ChangeParams();

signals:
    void SendSettings(const uint32_t width, const uint32_t height, const YUVLib::YUVFormat format, const uint32_t fps);

public slots:
    void ReadSettings();
    void Cancel();
    void SetFormat();
private:
    Ui::ChangeParams *ui;
    YUVLib::YUVFormat m_format;
};

#endif // CHANGEPARAMS_H
