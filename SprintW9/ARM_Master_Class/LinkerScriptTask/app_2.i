# 1 "app_2.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "app_2.c"
extern char u8InitGLobalVar ;

int const Sprints[] __attribute__ ((section (".sprints")))=
{
 10,20,30,50,80
};

void vidFunc(short int *u16FuncArgPtr)
{
 (*u16FuncArgPtr)++;
 u8InitGLobalVar--;
}
