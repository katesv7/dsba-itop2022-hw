#include "customproxymodel.h"

CustomProxyModel::CustomProxyModel(QObject *parent)
    : QSortFilterProxyModel{parent}
{
    maxFare = 28000;
    minFare = 0;
}

bool CustomProxyModel::filterAcceptsRow(int sourceRow,
                                              const QModelIndex &sourceParent) const
{
    QModelIndex indexFare = sourceModel()->index(sourceRow, 6, sourceParent);

    return fareInRange(sourceModel()->data(indexFare).toDouble());
}

bool CustomProxyModel::fareInRange(double fare) const
{
    return fare >= minFare && fare < maxFare;
}

void CustomProxyModel::setFilterMinimumFare(double fare)
{
    minFare = fare;
    invalidateFilter();
}

void CustomProxyModel::setFilterMaximumFare(double fare)
{
    maxFare = fare;
    invalidateFilter();
}