#pragma once 
#include "ServiceRepo/service_repository.hpp"

struct Service {
    shared_ptr<ServiceRepository> repo; 
    Service(shared_ptr<ServiceRepository> r) : repo(r){}; 
    void doSomething(){
        repo->query(); 
    }
}; 
