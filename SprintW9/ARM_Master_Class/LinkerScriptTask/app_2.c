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
