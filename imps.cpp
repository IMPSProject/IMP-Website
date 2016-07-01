#include "crow.h"

/*
    Crow: https://github.com/ipkn/crow
    compiler: g++ -O3 -std=c++14 imps.cpp -lboost_thread -lboost_system -pthread -o imps
*/

int main(){
    crow::SimpleApp app;
    CROW_ROUTE(app, "/")([](){
        return "Hail IMPS!";
    });
    app.port(80).multithreaded().run();
}
