#include "table_model.h"

tableViewModel::tableViewModel(QObject* parent) : QAbstractTableModel(parent){

}

int tableViewModel::rowCount(const QModelIndex & /*parent*/) const{
    return id.size();
}

int tableViewModel::columnCount(const QModelIndex & /*parent*/) const{
    return 3;
}


// Roles definition for this model
QHash<int, QByteArray> tableViewModel::roleNames() const{
    QHash<int, QByteArray> roleMap;
    roleMap[idRole] = "id";
    roleMap[nameRole] = "name";
    roleMap[phoneRole] = "phone";
    return roleMap;
}


// Read text file
void tableViewModel::readTextFile(QUrl path){
    QString tmp_file_path = path.toLocalFile();
    if(tmp_file_path == file_path)
        return;
    clearData();
    file_path = std::move(tmp_file_path);
    QFile file(file_path);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream out(&file);
    QVector<QString> line = out.readLine().split(';').toVector();
    readRow(line);
    while(!out.atEnd()){
        line = out.readLine().split(';').toVector();
        readRow(line);
    }
    file.close();
}

QString tableViewModel::file() const{
    return file_path;
}

void tableViewModel::clearData(){
    beginRemoveRows(QModelIndex(), 0, id.size() - 1);
    this->id.clear();
    this->user_names.clear();
    this->phone_numbers.clear();
    endRemoveRows();
}

void tableViewModel::readRow(QVector<QString>& row){
    if(row.size() != 3){
        row.resize(3);
    }
    beginInsertRows(QModelIndex(), id.size(), id.size());
    // Add user_id;
    id.push_back(std::move(row[0]));
    // Add user_name;
    user_names.push_back(std::move(row[1]));
    // Add phone_number;
    phone_numbers.push_back(std::move(row[2]));
    endInsertRows();

}

QVariant tableViewModel::data(const QModelIndex &index, int role) const{
    if (index.isValid()){
        switch(role){
            case idRole:
                return this->id[index.row()];
            case nameRole:
                return this->user_names[index.row()];
            case phoneRole:
                return this->phone_numbers[index.row()];
            default:
                return QVariant();
        }
    }
    return QVariant();
}
