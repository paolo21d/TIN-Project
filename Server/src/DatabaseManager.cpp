// Created by alexe on 18.04.2020.
//

#include "DatabaseManager.h"

using namespace oracle::occi;
using namespace std;

DatabaseManager::DatabaseManager(const string userName, const string password, string connectString)
{
	this->environment = Environment::createEnvironment(Environment::OBJECT);
	this->connection = environment->createConnection(userName, password, connectString);
}

DatabaseManager::~DatabaseManager()
{
	environment->terminateConnection(connection);
	Environment::terminateEnvironment(environment);
}

void DatabaseManager::addMeasurement(IMeasurement* measurement)
{
}

void DatabaseManager::printTest()
{
	try
	{
		auto* stmt = connection->createStatement(
			"SELECT id, name FROM test1 ");

		journal c2;

		ResultSet* rs = stmt->executeQuery();

		while (rs->next())
		{
			cout << "id: " << rs->getInt(1) << " ";
			cout << rs->getString(2) << endl;
		}

		stmt->closeResultSet(rs);
		connection->terminateStatement(stmt);

	}
	catch (SQLException e)
	{
		std::cout << e.getErrorCode();
	}
}
