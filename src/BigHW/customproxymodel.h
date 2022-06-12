#ifndef CUSTOMPROXYMODEL_H
#define CUSTOMPROXYMODEL_H

#include <QSortFilterProxyModel>

class CustomProxyModel : public QSortFilterProxyModel
{
    Q_OBJECT

public:
    CustomProxyModel(QObject *parent = nullptr);

    double filterMinimumFare() const { return minFare; }
    void setFilterMinimumFare(double fare);

    double filterMaximumFare() const { return maxFare; }
    void setFilterMaximumFare(double fare);

protected:
    bool filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const override;

private:
    bool fareInRange(double fare) const;

    double minFare;
    double maxFare;
};

#endif // CUSTOMPROXYMODEL_H