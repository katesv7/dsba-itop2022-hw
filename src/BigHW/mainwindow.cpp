#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "customproxymodel.h"
#include "examplemodel.h"
#include "aboutdialog.h"
#include <QFileDialog>
#include <QTextStream>
#include <QRegularExpression>
#include <QSortFilterProxyModel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->GarmentTable->horizontalHeader()->setSectionResizeMode(1, QHeaderView::ResizeToContents);
    ui->GarmentTable->horizontalHeader()->setStretchLastSection(true);
    QObject::connect(ui->loadButton, SIGNAL(clicked()), this, SLOT(loadFile()));
    QObject::connect(ui->nameFilterlineEdit, SIGNAL(textChanged(const QString &)), this, SLOT(updateFilter(const QString &)));
    QObject::connect(ui->categoryFilter, SIGNAL(currentIndexChanged(int)), this, SLOT(updateFilter2(int)));
    QObject::connect(ui->brandFilter, SIGNAL(currentIndexChanged(int)), this, SLOT(updateFilter3(int)));
    QObject::connect(ui->sexFilter, SIGNAL(currentIndexChanged(int)), this, SLOT(updateFilter4(int)));
    QObject::connect(ui->seasonFilter, SIGNAL(currentIndexChanged(int)), this, SLOT(updateFilter5(int)));
    QObject::connect(ui->colorFilter, SIGNAL(currentIndexChanged(int)), this, SLOT(updateFilter6(int)));
    QObject::connect(ui->sizeFilter, SIGNAL(currentIndexChanged(int)), this, SLOT(updateFilter7(int)));
    QObject::connect(ui->actionLoad, SIGNAL(triggered()), this, SLOT(loadFile()));
    QObject::connect(ui->fareFromSlider, SIGNAL(valueChanged(int)), this, SLOT(updateFilterMinFare(int)));
    QObject::connect(ui->fareToSlider, SIGNAL(valueChanged(int)), this, SLOT(updateFilterMaxFare(int)));
    QObject::connect(ui->btnAccount, SIGNAL(clicked()), this, SLOT(showAbout()));

    _exampleModel = new ExampleModel(this);
    proxyModel = new QSortFilterProxyModel(this);
    proxyModelFare = new CustomProxyModel(this);

    proxyModel->setSourceModel(_exampleModel);
    proxyModelFare->setSourceModel(proxyModel);

    ui->GarmentTable->setModel(proxyModelFare);
    ui->GarmentTable->setSortingEnabled(true);

    // Size of Boxes
    ui->categoryFilter->setMaximumWidth(100);
    ui->brandFilter->setMaximumWidth(100);
    ui->sexFilter->setMaximumWidth(100);
    ui->seasonFilter->setMaximumWidth(100);
    ui->colorFilter->setMaximumWidth(100);
    ui->sizeFilter->setMaximumWidth(100);
    ui->nameFilterlineEdit->setMaximumWidth(250);
    ui->fareGroupBox->setMaximumWidth(200);

    // Category
    ui->categoryFilter->addItem("Pants and trousers");
    ui->categoryFilter->addItem("Coats and jackets");
    ui->categoryFilter->addItem("Skirts and dresses");
    ui->categoryFilter->addItem("Shirts");

    // Brand
    ui->brandFilter->addItem("Zara");
    ui->brandFilter->addItem("Uniqlo");
    ui->brandFilter->addItem("H&M");

    // Sex
    ui->sexFilter->addItem("Women");
    ui->sexFilter->addItem("Men");
    
    // Season
    ui->seasonFilter->addItem("Spring-summer");
    ui->seasonFilter->addItem("Autumn-winter");

    // Color
    ui->colorFilter->addItem("White");
    ui->colorFilter->addItem("Blue");
    ui->colorFilter->addItem("Yellow");
    ui->colorFilter->addItem("Green");
    ui->colorFilter->addItem("Black");
    ui->colorFilter->addItem("Brown");
    ui->colorFilter->addItem("Multicolor");
    
    // Size
    ui->sizeFilter->addItem("XS");
    ui->sizeFilter->addItem("S");
    ui->sizeFilter->addItem("M");
    ui->sizeFilter->addItem("L");
    ui->sizeFilter->addItem("XL");

    _shownDetailsColumn = 0;
}

void MainWindow::updateFilter(const QString & text)
{
    proxyModel->setFilterKeyColumn(7);
    proxyModel->setFilterWildcard(text);
}

void MainWindow::updateFilter2(int index)
{
    proxyModel->setFilterKeyColumn(2);

    if (index == 1)
    {
        proxyModel->setFilterFixedString("pants");
    }
    else if (index == 2) 
    {
        proxyModel->setFilterRegExp(QRegExp("coat|jacket"));
    }
    else if(index == 3)
    {
        proxyModel->setFilterFixedString("dress");
    }
    else if(index == 4)
    {
        proxyModel->setFilterFixedString("t-shirt");
    }
    else if(index == 0)
    {
        proxyModel->setFilterFixedString("");
    }
} 

void MainWindow::updateFilter3(int index)
{
    proxyModel->setFilterKeyColumn(1);

    if (index == 1)
    {
        proxyModel->setFilterFixedString("Zara");
    }
    else if(index == 2)
    {
        proxyModel->setFilterFixedString("Uniqlo");
    }
    else if(index == 3)
    {
        proxyModel->setFilterFixedString("H&M");
    }
    else if(index == 0)
    {
        proxyModel->setFilterFixedString("");
    }
}

void MainWindow::updateFilter4(int index)
{
    proxyModel->setFilterKeyColumn(0);

    if (index == 1)
    {
        proxyModel->setFilterFixedString("woman");
    }
    else if(index == 2)
    {
        proxyModel->setFilterRegExp(QRegExp("^man$"));
    }
    else if(index == 0)
    {
        proxyModel->setFilterFixedString("");
    }
}

void MainWindow::updateFilter5(int index)
{
    proxyModel->setFilterKeyColumn(3);

    if (index == 1)
    {
        proxyModel->setFilterFixedString("spring-summer");
    }
    else if(index == 2)
    {
        proxyModel->setFilterFixedString("autumn-winter");
    }
    else if(index == 0)
    {
        proxyModel->setFilterFixedString("");
    }
}

void MainWindow::updateFilter6(int index)
{
    proxyModel->setFilterKeyColumn(4);

    if (index == 1)
    {
        proxyModel->setFilterFixedString("White");
    }
    else if (index == 2) 
    {
        proxyModel->setFilterFixedString("Blue");
    }
    else if(index == 3)
    {
        proxyModel->setFilterFixedString("Yellow");
    }
    else if(index == 4)
    {
        proxyModel->setFilterFixedString("Green");
    }
    else if(index == 5)
    {
        proxyModel->setFilterFixedString("Black");
    }
    else if(index == 6)
    {
        proxyModel->setFilterFixedString("Brown");
    }
    else if(index == 7)
    {
        proxyModel->setFilterFixedString("Multicolor");
    }
    else if(index == 0)
    {
        proxyModel->setFilterFixedString("");
    }
} 

void MainWindow::updateFilter7(int index)
{
    proxyModel->setFilterKeyColumn(5);

    if (index == 1)
    {
        proxyModel->setFilterFixedString("XS");
    }
    else if(index == 2)
    {
        proxyModel->setFilterRegExp(QRegExp("^S$"));
    }
    else if(index == 3)
    {
        proxyModel->setFilterFixedString("M");
    }
    else if(index == 4)
    {
        proxyModel->setFilterFixedString("L");
    }
    else if(index == 5)
    {
        proxyModel->setFilterFixedString("XL");
    }
    else if(index == 0)
    {
        proxyModel->setFilterFixedString("");
    }
}

void MainWindow::loadFile()
{
    delete _exampleModel;
    
    _exampleModel = new ExampleModel(this);

    QString fileName = QFileDialog::getOpenFileName(this, "Open File",
                                                    "../",
                                                    "Data (*.csv)");

    _exampleModel->fillDataTableFromFile(fileName);
    proxyModel->setSourceModel(_exampleModel);
} 

void MainWindow::updateFilterMinFare(int value)
{
    proxyModelFare->setFilterMinimumFare(value);
}

void MainWindow::updateFilterMaxFare(int value)
{
    proxyModelFare->setFilterMaximumFare(value);
}

void MainWindow::showAbout()
{
    dialog = new AboutDialog(this);
    dialog->exec();
}

MainWindow::~MainWindow()
{
    delete ui;
}
