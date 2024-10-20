#ifndef DMESSAGEBOX_H
#define DMESSAGEBOX_H

// 用于 Fake DMessageBox
#include <QObject>
#include <QMessageBox>
#include "dtkwidget_global.h"

DWIDGET_BEGIN_NAMESPACE

using GMessageBox = QMessageBox;
using DMessageBox = QMessageBox;

DWIDGET_END_NAMESPACE

#endif // DMESSAGEBOX_H
