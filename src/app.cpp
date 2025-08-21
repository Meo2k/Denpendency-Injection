#include "app.hpp"

void App::run(){

	auto service = c.resolve<Service>(); 
    service->doSomething(); 
}