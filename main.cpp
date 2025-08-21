#include "container_DI.hpp"
#include "InfrasRepo/sql_repository.hpp"
#include "app.hpp"

using namespace std; 


int main(int argc, char* argv[]){
    ContainerDI c; 

    c.registerType<ServiceRepository, SqlRepository>(); 
    c.registerFactory<Service>([&c] {
        return std::make_shared<Service>(c.resolve<ServiceRepository>());
    }); 
    
    App app(c); 
    app.run(); 
    
    return 0 ; 
}