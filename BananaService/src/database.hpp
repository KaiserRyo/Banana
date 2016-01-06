/*
 * database.hpp
 *
 *  Created on: 17-Dec-2014
 *      Author: perl
 */

#ifndef DATABASE_HPP_
#define DATABASE_HPP_
#include <QObject>
#include <bb/data/SqlDataAccess>
#include <bb/cascades/GroupDataModel>
#include <QtSql/QSqlDatabase>
 class bb::cascades::GroupDataModel;
 class SqlDataAcces;
 using namespace bb::data;
class Database:public QObject{
    Q_OBJECT
public:
    QSqlDatabase _database;
    QString DB_PATH;
    Database(QObject *parent);
    virtual ~Database();
    bool initDatabase();
    QVariant executeQuery(QString);
    QSqlQuery executeSqlQuery(QString q);
    bool insertQuery(QString query,QVariantMap bind);
    int getTableSize(QString tabname);
    int getTableSizeByQuery(QString query);
//    bb::cascades::GroupDataModel* getQueryModel(QString query);


private:
    SqlDataAccess *sqlda;
    bool openDatabase();
};




#endif /* DATABASE_HPP_ */
