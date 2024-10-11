#include "dtkwidget_global.h"
#include <QAbstractButton>
#include <QStyleOptionButton>
#include <QPainter>
#include <QFontMetrics>
#include <QWidget>
DWIDGET_BEGIN_NAMESPACE
class DCommandLinkButton : public QAbstractButton
{
    Q_OBJECT

public:
    explicit DCommandLinkButton(const QString &text, QWidget *parent = nullptr);

    QSize sizeHint() const override;

protected:
    void initStyleOption(QStyleOptionButton *option) const;
    void paintEvent(QPaintEvent *event) override;

private:
    enum Margins {
        LeftMargins = 3,
        RightMargins = LeftMargins,
        TopLeftMargins = 3,
        BottomMargins = LeftMargins,
        TextMargins = 4
    };
};

DCommandLinkButton::DCommandLinkButton(const QString &text, QWidget *parent)
    : QAbstractButton(parent)
{
    this->setText(text);
}

QSize DCommandLinkButton::sizeHint() const
{
    QString text = this->text();
    QSize size = fontMetrics().size(0, text);
    size += QSize(LeftMargins + RightMargins + TextMargins * 2, TopLeftMargins + BottomMargins);
    return size;
}

void DCommandLinkButton::initStyleOption(QStyleOptionButton *option) const
{
    option->initFrom(this);

    if (isDown())
        option->state |= QStyle::State_Sunken;

    QPalette pa = this->palette();
    option->palette.setBrush(QPalette::ButtonText, pa.highlight());
    option->text = this->text();
}

void DCommandLinkButton::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e)

    QStyleOptionButton opt;
    initStyleOption(&opt);

    QPainter painter(this);
    style()->drawControl(QStyle::CE_PushButton, &opt, &painter, this);
}
DWIDGET_END_NAMESPACE
