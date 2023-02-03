#include "mainwindow.h"

#include <QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QPieSeries* series = new QPieSeries();
    series->append("Vegetables", .40);
    series->append("Beans", .20);
    series->append("Fruit", .15);
    series->append("Seed/Nuts", .10);
    series->append("Whole Grains", .15);

    QPieSlice* slice0 = series->slices().at(0);
    slice0->setLabelVisible();

    QPieSlice* slice1 = series->slices().at(1);
    slice1->setExploded();
    slice1->setLabelVisible();
    slice1->setPen(QPen(Qt::darkGreen, 2));
    slice1->setBrush(Qt::green);

    QPieSlice* slice2 = series->slices().at(2);
    slice2->setLabelVisible();

    QPieSlice* slice3 = series->slices().at(3);
    slice3->setLabelVisible();

    QPieSlice* slice4 = series->slices().at(4);
    slice4->setLabelVisible();

    QChart* chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Which type of goal Icardi scored this season");
    chart->legend()->hide();

    // Used to display the chart
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // Create the main app window
    QMainWindow window;

    // Set the main window widget
    window.setCentralWidget(chartView);
    window.resize(420, 300);
    window.show();
    return a.exec();
}
