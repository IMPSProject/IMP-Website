//#define CROW_ENABLE_SSL
#include "crow_all.h"

/*
    Crow: https://github.com/ipkn/crow
    compiler: g++ -O3 -std=c++14 imps.cpp -lboost_thread -lboost_system -pthread -o imps
*/

int main(){
	crow::SimpleApp app;
	crow::mustache::set_base(".");

	// Home
	CROW_ROUTE(app, "/")([](){
		crow::mustache::context ctx;
        return crow::mustache::load("home.html").render();
	});

	// Lagertha
	CROW_ROUTE(app, "/admin/")([](){
		return "Lagertha.";
	});

	// Close session
	CROW_ROUTE(app, "/admin/sair")([](){
		return "Sair do Lagertha.";
	});

	// Client Admin
	CROW_ROUTE(app, "/publicidade/")([](){
		return "Publicidade.";
	});

	// Get IP
	CROW_ROUTE(app, "/ip")([](){
		return "IP";
	});
	
	// POST
	CROW_ROUTE(app, "/post/").methods(crow::HTTPMethod::POST)([](const crow::request& req){
		auto x = crow::json::load(req.body);
		if(!x) return crow::response(400);
		int sum = x["a"].i()+x["b"].i();
        std::ostringstream os;
        os << sum;
        return crow::response{os.str()};
	});
	
	// Log
	crow::logger::setLogLevel(crow::LogLevel::DEBUG);
	
	// SSL/HTTPS .ssl_file("test.crt", "test.key")
	
	// App
	app.port(80).multithreaded().run();
}
