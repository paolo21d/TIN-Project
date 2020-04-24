// Created by alexe on 18.04.2020.
//

#include "DatabaseManager.h"
typedef std::vector<std::string> journal;

void DatabaseManager::run() {

    try {
        std::cout<<"chuj";
        env = oracle::occi::Environment::createEnvironment(oracle::occi::Environment::OBJECT);
        std::cout<<"w dupe";
        oracle::occi::Connection *conn = env->createConnection(userName, password, connectString);
        std::cout<<"o tak";
        oracle::occi::Statement*  stmt = conn->createStatement(
            "SELECT id, name FROM test1 ");

        journal c2;

        oracle::occi::ResultSet* rs = stmt->executeQuery();
        try {
            while (rs->next())
            {
                std::cout << "id: " << rs->getInt(1) << std::endl;
                //std::cout << "id: " << rs->getInt(2) << std::endl;
                std::cout << rs->getString(2);
                //std::cout << "instructor: " << rs->getInt(2) << std::endl;
                /*getVector(rs, 2, c2);
                for (int i = 0; i < c2.size(); ++i)
                    std::cout << c2[i] << " ";
                std::cout << std::endl;*/
            }
        }
        catch (oracle::occi::SQLException ex)
        {
            std::cout << "Exception thrown for displayRow" << std::endl;
            std::cout << "Error number: " << ex.getErrorCode() << std::endl;
            std::cout << ex.getMessage() << std::endl;
        }
        stmt->closeResultSet(rs);
        conn->terminateStatement(stmt);
        env->terminateConnection(conn);

        oracle::occi::Environment::terminateEnvironment(env);
    }   catch (oracle::occi::SQLException e) {
        std::cout<<e.getErrorCode();
    }


    /*
    SAConnection con;
    try
    {
        // connect to database
        // in this example, it is Oracle,
        // but can also be Sybase, Informix, DB2
        // SQLServer, InterBase, SQLBase and ODBC
        con.Connect ("test",    // database name
                     "tester",  // user name
                     "tester",  // password
                     SA_Oracle_Client); //Oracle Client
        //printf("We are connected!\n");

        // Disconnect is optional
        // autodisconnect will occur in destructor if needed
        con.Disconnect();
        //printf("We are disconnected!\n");
    }

    catch(SAException & x)
    {
        // SAConnection::Rollback()
        // can also throw an exception
        // (if a network error for example),
        // we will be ready
        try
        {
            // on error rollback changes
            con.Rollback ();
        }
        catch(SAException &)
        {
        }
        // print error message
        //printf("%s\n", (const char*)x.ErrText());
    }*/
}

/*void DatabaseManager::gotMeasurement(IMeasurement* measurement) {

    std::cout<<"chuj";
}*/