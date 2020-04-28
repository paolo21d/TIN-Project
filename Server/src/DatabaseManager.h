//
// Created by alexe on 18.04.2020.
//

#ifndef SERVER_DATABASEMANAGER_H
#define SERVER_DATABASEMANAGER_H


#include "IDatabaseManager.h"
#include <occi.h>
#include <iostream>
#include <string>

typedef std::vector<std::string> journal;

class DatabaseManager : public IDatabaseManager {
private:
    oracle::occi::Environment *environment;
    oracle::occi::Connection *connection;

public:
    DatabaseManager(std::string userName, std::string password, std::string connectString);
	~DatabaseManager();
    void addMeasurement(IMeasurement* measurement) override;
    void printTest();
};

#endif //SERVER_DATABASEMANAGER_H
