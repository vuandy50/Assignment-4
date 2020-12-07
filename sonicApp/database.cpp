#include "database.h"

#include <QDebug>
#include <QSqlError>
#include <QMessageBox>
#include <QFile>
#include <QFileDialog>
#include <QSqlQuery>

database::database() {}   //Constructor
database::~database() {}  //Destructor

/*!
****************************************************************************
 * METHOD - openDB
 * --------------------------------------------------------------------------
 * This method creates and opens a sqlite database connection if not
 * opened created/opened already.  It also returns if the database was
 * successfully created and opened.
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      No parameters are required.
 *
 * POST-CONDITIONS
 *      ==> Returns if database was succesfully opened or failed to open.
 ***************************************************************************/
bool database::openDB()
{
    QString DB_PATH = "sonic.sqlite";
    // If database is already opened, skip creation and connection process
    if(!db.open())
    {
        // Create database object
        db = QSqlDatabase::addDatabase("QSQLITE");
        // Create database connection
        db.setDatabaseName(DB_PATH);

        // Check if database was successfully opened
        if(!db.open())
        {
            qDebug() << "Error: connection to database failed";
        }
        else
        {
            qDebug() << "Success: database opened";
        }
    }

    return db.open();
}

/*!
 ****************************************************************************
 * METHOD - closeDB
 * --------------------------------------------------------------------------
 * This method closes the sqlite database connection.  It also
 * returns if the database is still open or not.
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      No parameters are required.
 *
 * POST-CONDITIONS
 *      ==> Returns if database is still open after attempt to close it.
 ***************************************************************************/
bool database::closeDB()
{
    // Close the database connection and delete if still open
    if(db.isOpen())
    {
        db.close();
        db.removeDatabase(QSqlDatabase::defaultConnection);
        qDebug() << ("Success: database closed");
    }

    return db.isOpen();
}

/*!
 ****************************************************************************
 * METHOD - lastError
 * --------------------------------------------------------------------------
 * This method returns the last database error created
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      No parameters are required.
 *
 * POST-CONDITIONS
 *      ==> Returns last database error
 ***************************************************************************/
QSqlError database::lastError()
{
    return db.lastError();
}

/*!
 ****************************************************************************
 * METHOD - currentDB
 * --------------------------------------------------------------------------
 * This method returns the currently connected database object
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      No parameters are required.
 *
 * POST-CONDITIONS
 *      ==> Returns current connected database
 ***************************************************************************/
QSqlDatabase database::currentDB() const
{
    return db;
}
