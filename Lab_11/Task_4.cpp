#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

class DatabaseException : public exception {
public:
    const char* what() const noexcept override {
        return "A database error occurred.";
    }
};

class ConnectionFailedException : public DatabaseException {};
class QueryTimeoutException : public DatabaseException {};

template <typename T>
class DatabaseConnector {
public:
    void connect(const string& dbName) {
        if (dbName == "invalid_db") {
            throw ConnectionFailedException();
        }
        else if (dbName == "slow_db") {
            throw DatabaseException();
        }
    }

    void executeQuery(const string& query) {
        if (query == "timeout_query") {
            throw QueryTimeoutException();
        }
    }
};

int main() {
    DatabaseConnector<int> connector;

    try {
        cout << "Attempting to connect to invalid_db..." << endl;
        connector.connect("invalid_db");
    }
    catch (const ConnectionFailedException& e) {
        cerr << "Caught ConnectionFailedException - what(): " << e.what() << endl;
    }

    try {
        cout << "Attempting to connect to slow_db..." << endl;
        connector.connect("slow_db");
    }
    catch (const DatabaseException& e) {
        cerr << "Caught a general DatabaseException - what(): " << e.what() << endl;
    }

    try {
        cout << "Attempting to execute timeout_query..." << endl;
        connector.executeQuery("timeout_query");
    }
    catch (const QueryTimeoutException& e) {
        cerr << "Caught QueryTimeoutException - what(): " << e.what() << endl;
    }

    return 0;
}
