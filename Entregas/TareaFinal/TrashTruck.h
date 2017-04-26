//
// Created by franspaco on 26/04/17.
//

#ifndef TAREAFINAL_TRASHTRUCK_H
#define TAREAFINAL_TRASHTRUCK_H

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <typeinfo>
#include <list>
/*
typedef void*(*newAlloc)(std::size_t size);
typedef void (*newFree)(void*);

static void* myAlloc_init(std::size_t size);
static void* myAlloc_init2(std::size_t size);
static void* myAlloc_run(std::size_t size);
static void* myAlloc_shutdown(std::size_t size);

static void myFree_run( void* mem );
static void myFree_shutdown( void* mem );

newAlloc myAlloc_i = myAlloc_init;
newFree  myFree_i  = myFree_run;

void* operator new(std::size_t n) throw(std::bad_alloc) {
    return newAlloc(n);
}

void* operator new[](std::size_t n) throw(std::bad_alloc) {
    return newAlloc(n);
}

void operator delete(void * p) throw() {
    newFree(p);
}

void operator delete[](void * p) throw() {
    newFree(p);
}

class MemManager{
private:
    std::vector<void*> allocs;
public:
    void* alloc(std::size_t size){
        void * temp = malloc(size);
        allocs.push_back(temp);
    }
};

static char memGlobals[sizeof(MemManager)] = { 0 };

// and we create a fake class reference to this memory.
static MemManager& gMem = *(reinterpret_cast<MemManager*>(&memGlobals[0]));

static void* myAlloc_init(std::size_t size) {
    myAlloc_i = myAlloc_init2;
    static MemManager* mem = new(memGlobals, NULL) MemManager;
    myAlloc_i = myAlloc_run;
    return myAlloc_run( size );
}

// This gets called during the initialization of memGlobals only.
static void* myAlloc_init2(std::size_t size) {
    return malloc( size );
}

// The normal allocator that runs after heap construction, and before
// its eventual destruction.
static void* myAlloc_run(std::size_t size ) {
    return gMem.alloc(size);
}

// Allocates memory during shutdown of the memory manager
static void* myAlloc_shutdown(std::size_t size) {
    return malloc( size );
}
*/
#endif //TAREAFINAL_TRASHTRUCK_H
