#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_DxfRW.h"

class DxfRW : public QMainWindow
{
    Q_OBJECT

public:
    DxfRW(QWidget *parent = Q_NULLPTR);

private:
    Ui::DxfRWClass ui;
};
