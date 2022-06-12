#include "aboutdialog.h"
#include "./ui_aboutdialog.h"
#include "QPaintEvent"
#include "QPainter"

AboutDialog::AboutDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutDialog)
{
    ui->setupUi(this);

}

AboutDialog::~AboutDialog()
{
    delete ui;
}

void AboutDialog::paintEvent(QPaintEvent *event)
{
    QPainter p(this);

    p.setPen(QPen(Qt::darkCyan, 7, Qt::SolidLine, Qt::FlatCap));
    p.drawLine(295,50,200,200);
    p.drawLine(200,200,312,200);
    p.drawLine(295,50,340,100);
    p.drawLine(295,130,360,230);
    p.drawLine(420,80,360,230);
    p.drawLine(420,80,500,200);
    p.drawLine(500,200,430,200);

    //    p.drawLine(312,30,200,200);
}