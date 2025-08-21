#pragma once 
#include <iostream>
#include <memory>
#include <typeindex>
#include <functional>
#include <unordered_map>

using namespace std; 

class ContainerDI {
private : 
    unordered_map<type_index, function<shared_ptr<void>()>> factories ; 
public : 
    template <typename TInterface, typename TImpl>
    void registerType(){
        factories[typeid(TInterface)] = [] {
            return make_shared<TImpl>(); 
        }; 
    }; 
    template <typename TInterface>
    void registerFactory(function<shared_ptr<TInterface>()> f){
        factories[typeid(TInterface)] = [f] {
            return f(); 
        }; 
    }; 

    template <typename TInterface>
    shared_ptr<TInterface> resolve(){
        auto it = factories.find(typeid(TInterface)); 
        if (it == factories.end()){
            throw runtime_error("Type not registerd !"); 
        }
        return static_pointer_cast<TInterface>(it->second()); 
    }; 
}; 