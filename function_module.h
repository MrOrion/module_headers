/* 
 * File:   function_module.h
 * Author: m79lol
 *
 */

#ifndef FUNCTION_MODULE_H
#define	FUNCTION_MODULE_H

class FunctionModule {
    protected:
        FunctionModule() {}
    public: 
        virtual const char *getUID() = 0;
        virtual void prepare(colorPrintf_t *colorPrintf_p, colorPrintfVA_t *colorPrintfVA_p) = 0;
        virtual FunctionData** getFunctions(unsigned int *count_functions) = 0;
        
        virtual int readPC(void *buffer, unsigned int buffer_length) = 0;
        virtual FunctionResult* executeFunction(system_value function_index, void **args) = 0;
        virtual void *writePC(unsigned int *buffer_length) = 0;
        
        virtual void destroy() = 0;
        virtual ~FunctionModule() {}
};

typedef FunctionModule* (*getFunctionModuleObject_t)();
extern "C" {
    __declspec(dllexport) FunctionModule* getFunctionModuleObject();
}

#endif	/* FUNCTION_MODULE_H */

