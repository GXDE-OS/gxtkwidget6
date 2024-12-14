/*
 * Copyright (C) 2017 ~ 2017 Deepin Technology Co., Ltd.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "buttongroup.h"

#include <QHBoxLayout>
#include <QPushButton>
#include <QButtonGroup>

class ButtonGroupPrivate
{
public:
    ButtonGroupPrivate(ButtonGroup *parent) : q_ptr(parent){}

    QHBoxLayout *layout = nullptr;
    QButtonGroup *group  = nullptr;
    ButtonGroup *q_ptr;
    Q_DECLARE_PUBLIC(ButtonGroup)
};

ButtonGroup::ButtonGroup(QWidget *parent) :
    QFrame(parent), d_ptr(new ButtonGroupPrivate(this))
{
    Q_D(ButtonGroup);
    setObjectName("ButtonGroup");
    d->group = new QButtonGroup;
    d->layout = new QHBoxLayout(this);
    d->layout->setSpacing(0);
    d->layout->setContentsMargins(0, 0, 0, 0);
    connect(d->group, &QButtonGroup::buttonReleased,
            this, [=](QAbstractButton* button){
        // 获取被释放按钮的 ID（假设 QButtonGroup 有一个 checkedId() 方法来获取当前选中的按钮 ID，
        // 但注意 buttonReleased 信号是在按钮被释放时发射的，不一定表示该按钮是被选中的。
        // 如果你需要的是被选中按钮的 ID，可能需要使用其他信号，如 buttonClicked。
        // 这里我们假设你需要的是释放按钮的某种属性或 ID，这可能需要你自定义逻辑来获取。
        // 例如，如果每个按钮都有一个唯一的对象名称，你可以使用 button->objectName() 来获取它。
        int buttonId = d->group->checkedId()/* 这里应该是获取按钮 ID 的逻辑 */;
        // 发射自定义信号，传递所需的 ID
        Q_EMIT buttonChecked(buttonId);
    });
    /*connect(d->group,static_cast<void (QButtonGroup::*)(int)>(&QButtonGroup::buttonReleased),
            this, [=](int){
        Q_EMIT buttonChecked(d->group->checkedId());
    });*/
}

ButtonGroup::~ButtonGroup()
{

}

void ButtonGroup::setCheckedButton(int id)
{
    Q_D(ButtonGroup);
    if (d->group->button(id)) {
        d->group->button(id)->setChecked(true);
    }
}

void ButtonGroup::setButtons(const QStringList &texts)
{
    Q_D(ButtonGroup);
    int i = 0;
    for (auto text: texts) {
        auto bt = new QPushButton(text);
        bt->setFixedWidth(36);
        bt->setFixedHeight(22);
        bt->setCheckable(true);

        if (texts.length() <= 1)
            bt->setObjectName("ButtonGroupSingle");
//            bt->setStyleSheet("QPushButton{border: 1px solid red; border-radius: 4.0px}");
        else {
            if (i == 0)
                bt->setObjectName("ButtonGroupBegin");
//                bt->setStyleSheet("QPushButton{"
//                                  "border: 1px solid red;"
//                                  "border-top-left-radius: 4.0px;"
//                                  "border-bottom-left-radius: 4.0px;"
//                                  "}");
            else if (i == texts.length() -1) {
                    bt->setObjectName("ButtonGroupEnd");
//                bt->setStyleSheet("QPushButton{"
//                                  "border: 1px solid red;"
//                                  "border-top-right-radius: 4.0px;"
//                                  "border-bottom-right-radius: 4.0px;"
//                                  "}");
            } else {

                    bt->setObjectName("ButtonGroupMiddle");
//                bt->setStyleSheet("QPushButton{"
//                                  "border-top: 1px solid red;"
//                                  "border-bottom: 1px solid red;"
//                                  "}");
            }
        }
        d->group->addButton(bt, i);
        d->layout->addWidget(bt);
        i++;
    }
    d->layout->addStretch();
}
