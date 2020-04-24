//
// Created by alexe on 18.04.2020.
//

#ifndef SERVER_DATABASEMANAGER_H
#define SERVER_DATABASEMANAGER_H


#include "IDatabaseManager.h"
#include <occi.h>
#include <iostream>
#include <string>
//#include <SQLAPI.h>

class DatabaseManager : public IDatabaseManager {
private:
    oracle::occi::Environment *env;

    const std::string userName = "ADMIN";
    const std::string password = "Seikonnoqwaser1!";
    const std::string connectString = "tin_high";

public:
    void run();

    //void gotMeasurement(IMeasurement* measurement) override;
};

#endif //SERVER_DATABASEMANAGER_H
