#pragma once 

struct ServiceRepository {
    virtual void query() = 0 ; 
    virtual ~ServiceRepository() = default ; // research after 
}; 

