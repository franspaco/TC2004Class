//
// Created by franspaco on 26/04/17.
//

#ifndef TAREAFINAL_TRASHTRUCK2_H
#define TAREAFINAL_TRASHTRUCK2_H
#include <iostream>
#include <vector>
#include <algorithm>

std::vector<void*> allocs;

typedef void*(*newAlloc)(std::size_t);
typedef void (*newFree)(void*);

static void* allocInternal(std::size_t size);
static void* allocExternal(std::size_t size);
static void freeInternal(void* mem);
static void freeExternal(void* mem);

newAlloc newAlloc_i = allocExternal;
newFree  newFree_i  = freeExternal;

void* operator new(std::size_t n) throw(std::bad_alloc) {
    std::cout << "\nNEW" << std::endl;
    return newAlloc_i(n);
}

void* operator new[](std::size_t n) throw(std::bad_alloc) {
    std::cout << "\nNEW" << std::endl;
    return newAlloc_i(n);
}

void operator delete(void * p) throw() {
    std::cout << "\nDELETE: " << p << std::endl;
    newFree_i(p);
}

void operator delete[](void * p) throw() {
    std::cout << "\nDELETE: " << p << std::endl;
    newFree_i(p);
}

void switchInternals(){
    newAlloc_i = allocInternal;
    newFree_i = freeInternal;
}

void switchExternals(){
    newAlloc_i = allocExternal;
    newFree_i = freeExternal;
}

void* allocExternal(std::size_t size){
    std::cout << "Alloc ext: ";
    void * temp = malloc(size);
    std::cout << temp << std::endl;
    switchInternals();
    allocs.push_back(temp);
    switchExternals();
    return temp;
}

void* allocInternal(std::size_t size){
    void * temp = malloc(size);
    std::cout << "Alloc Int: " << temp << std::endl;
    return temp;
}

void freeExternal(void* p){
    std::cout << "Free ext: " << p << std::endl;
    switchInternals();
    std::vector<void*>::iterator it = std::find(allocs.begin(), allocs.end(), p);
    if(it != allocs.end()){
        std::cout << "FREEING: " << p << std::endl;
        allocs.erase(it);
        free(p);
    }else{
        std::cout << "DOUBLE DELETE: " << p << std::endl;
    }
    switchExternals();
}

void freeInternal(void* p){
    std::cout << "Free int: " << p << std::endl;
    free(p);
}

void clearMem(){
    switchInternals();
    while(!allocs.empty()){
        void* temp = allocs.back();
        allocs.pop_back();
        freeInternal(temp);
    }
}


#endif //TAREAFINAL_TRASHTRUCK2_H
