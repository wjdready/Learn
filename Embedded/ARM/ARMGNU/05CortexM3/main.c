#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int aaa = 12345;

char array[1024];

void *_sbrk(ptrdiff_t incr)
{
    extern char _end[];
    extern char _heap_end[];
    static char *curbrk = _end;

    if ((curbrk + incr < _end) || (curbrk + incr > _heap_end))
        return NULL - 1;

    curbrk += incr;
    return curbrk - incr;
}

extern void initialise_monitor_handles(void);

int main(int argc, char const *argv[])
{
    initialise_monitor_handles();

    char *data = malloc(0x2000 - 0x100);
    if (data == NULL)
        return -1;

    strcpy(data, "I am Jack");
    printf("Hello World, %s, aaa is %d\n", data, aaa);

    extern uint32_t _data_start;
    extern uint32_t _data_end;
    extern uint32_t _bss_start;
    extern uint32_t _bss_end;
    extern uint32_t _heap_start;
    extern uint32_t _init_data_start;

    uint32_t *p_data_start = &_data_start;
    uint32_t *p_data_end = &_data_end;
    uint32_t *p_bss_start = &_bss_start;
    uint32_t *p_bss_end = &_bss_end;
    uint32_t *p_heap_start = &_heap_start;
    uint32_t *p_init_data_start = &_init_data_start;
    
    printf("_data_start %p\n", &_data_start);
    printf("_data_end %p\n", &_data_end);
    printf("_bss_start %p\n", &_bss_start);
    printf("_bss_end %p\n", &_bss_end);
    printf("_heap_start %p\n", &_heap_start);
    printf("_init_data_start %p\n", &_init_data_start);

    scanf("%s", array);

    printf("%s\n", array);

    return 0;
}
