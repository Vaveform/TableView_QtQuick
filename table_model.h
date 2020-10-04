#ifndef TABLE_MODEL_H
#define TABLE_MODEL_H

#include <QAbstractTableModel>
#include <QDebug>
#include <QFile>
#include <QVector>
#include <qqml.h>
#include <QQmlEngine>

class tableViewModel : public QAbstractTableModel{
    Q_OBJECT
    Q_PROPERTY(QString file READ file WRITE readTextFile)
public:
    tableViewModel(QObject *parent = nullptr);
    enum TableRoles{
        idRole = 0,
        nameRole = 1,
        phoneRole = 2
    };
    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    int columnCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;
    void readRow(QVector<QString>& row);
    void clearData();
    Q_INVOKABLE void readTextFile(QUrl path);
    QString file() const;
private:
    QVector<QString> id;
    QVector<QString> user_names;
    QVector<QString> phone_numbers;
    QString file_path;
};

#endif // TABLE_MODEL_H
