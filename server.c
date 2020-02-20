#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 
#include <string.h> 
#include <fcntl.h> 
#include <sys/shm.h> 
#include <sys/stat.h> 
#include <sys/mman.h>

typedef struct
{

char name[10];
int pages;
float price;

}book;
  
int main() 
{ 
    /* the size (in bytes) of shared memory object */
    const int SIZE = 4096; 
  
    /* name of the shared memory object */
    const char* name = "OS"; 
  
    /* strings written to shared memory */
    const char* message_0 = "Hello"; 
    const char* message_1 = "World!"; 
  
    /* shared memory file descriptor */
    int shm_fd; 
  
    /* pointer to shared memory obect */
    void* ptr; 
  
    /* create the shared memory object */
    shm_fd = shm_open(name, O_CREAT | O_RDWR, 0666); 
  
    /* configure the size of the shared memory object */
    ftruncate(shm_fd, SIZE); 
  
    /* memory map the shared memory object */
    ptr = mmap(0, SIZE, PROT_WRITE, MAP_SHARED, shm_fd, 0); 
 
    book c_prog;
   
    sprintf(c_prog.name, "%s", "c in depth"); 
    c_prog.pages = 134;
    c_prog.price = 22.3;

    memcpy(ptr, &c_prog, sizeof(book)); 

    return 0; 
} 
