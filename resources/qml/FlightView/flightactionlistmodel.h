#ifndef FLIGHTACTIONLISTMODEL_H
#define FLIGHTACTIONLISTMODEL_H

#include <QAbstractListModel>

class FlightActionListModel : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit FlightActionListModel(QObject *parent = nullptr);

    // Header:
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

private:
};

#endif // FLIGHTACTIONLISTMODEL_H
