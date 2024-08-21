#ifndef DAPPLICATIONHELPER_H
#define DAPPLICATIONHELPER_H

#include <QObject>
#include <QWidget>
#include <QPalette>
#include "dpalette.h"

class DApplicationHelper
{
public:
    DApplicationHelper();

    DPalette palette(const QWidget *widget, const QPalette &base = QPalette()) const;
    void setPalette(QWidget *widget, const QPalette &palette);
    void resetPalette(QWidget *widget);
};

#endif // DAPPLICATIONHELPER_H
