//summer olmstead assignment 6
#include <stdio.h>
#include <stdlib.h>

int global_v = 17;  //here lets declare our global variable

//lets make a function to demonstrate scope and variable shadowing
void demo_scope_and_shadowing() {
    int global_v = 13;  // here is the local variable which  shadows the global variable
    printf("in demo_scope_and_shadowing() - the local variable result 'global_v' value is: %d\n", global_v);
    
    // now lets have a nested block
    {
        int global_v = 15;  // shadowed again by a new local variable
        printf("in nested block - the local variable 'global_v' value is now: %d\n", global_v);
    }

    //now lets print the local variable from the function scope!!
    printf("after nested block, the local variable 'global_v' is value: %d\n", global_v);
}

//now lets demonstrate memory allocation and scope lifetime
void memory_management_demo() {
    //static memory allocation
    int stack_v = 1;  //local variable (stack-allocated)
    printf("stack variable 'stack_v' address: %p\n", (void*)&stack_v); //interesting to see the address

    //dynamic memory allocation/ heap
    int* heap_v = (int*)malloc(sizeof(int));
    *heap_v = 100;
    printf("heap variable 'heap_v' address: %p, value: %d\n", (void*)heap_v, *heap_v);
    
    //free the dynamically allocated memory
    free(heap_v);

    // after freeing, this is undefined behavior... dangerous
    printf("accessing memory after free: %d\n", *heap_v);

}

//function to demonstrate static vs dynamic typing!
void static_vs_dynamic_typing_demo() {
    int x = 33;  //static typing
    float y = 44.5f;  //static typing
    printf("static types: x = %d, y = %.2f\n", x, y);
    
    //dynamic behavior simulation (using `void*` and type casting)
    void* dynamic_v = malloc(sizeof(int));  //dynamically allocated memory for a variable
    *(int*)dynamic_v = 200;
    printf("dynamically allocated variable value: %d\n", *(int*)dynamic_v);
    
    //free the dynamically allocated memory
    free(dynamic_v);
}

int main() {
    //global variable access
    printf("Global variable value: %d\n", global_v);

    //calling the function to demonstrate scope and shadowing to see result
    demo_scope_and_shadowing();
    
    //calling function to demonstrate memory management
    memory_management_demo();
    
    //demonstrate static vs dynamic typing
    static_vs_dynamic_typing_demo();

    return 0;
}

//with our results, we can see that the global variable which was originally 17 when in scope of different functions changes in respect to the loop or function in the scope of which they are called and declared. we also see the variable memory addresses when we put them on the stack which is interesting... once freed we see a different number interestingly enough. for the types we see that it rounded our float var to have an extra decimal since we defined it too