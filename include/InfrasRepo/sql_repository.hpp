#pragma once 
#include <iostream>
#include "ServiceRepo/service_repository.hpp"


struct SqlRepository : ServiceRepository {
    void query() override ; 
}; 