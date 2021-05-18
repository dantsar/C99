int a_globl;
int main(){
	int a_local, b, c;
	a_local = 2;
	b = 3;
	c = 4;
	a_globl = a_local + b * c / 4;
	printf("a: %d ", a_globl);
	return a;
}