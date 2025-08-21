#pragma once 
#include "container_DI.hpp"
#include "service.hpp"

class App {
private : 
	ContainerDI& c; 
public : 
	App(ContainerDI& container) : c(container){};

	void run(); 
}; 