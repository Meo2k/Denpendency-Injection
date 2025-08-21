#pragma once 
#include "container_DI.hpp"
#include "service.hpp"

class App { // composition root 
private : 
	ContainerDI& c; 
public : 
	App(ContainerDI& container) : c(container){};

	void run(); 
}; 