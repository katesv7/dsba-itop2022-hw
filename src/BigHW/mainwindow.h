#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSortFilterProxyModel>
#include "examplemodel.h"
#include "customproxymodel.h"
#include "aboutdialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void loadFile();
    void updateFilterMinFare(int value);
    void updateFilterMaxFare(int value);
    void updateFilter(const QString & text);
    void updateFilter2(int);
    void updateFilter3(int);
    void updateFilter4(int);
    void updateFilter5(int);
    void updateFilter6(int);
    void updateFilter7(int);
    void showAbout();
    
private:
    size_t _shownDetailsColumn;
    ExampleModel *_exampleModel;
    QSortFilterProxyModel *proxyModel;
    CustomProxyModel *proxyModelFare;
    Ui::MainWindow *ui;
    AboutDialog *dialog;
};

#endif // MAINWINDOW_H