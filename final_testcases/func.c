int f(int a){	
	printf("%d ", a);
	return a;
}

int main(){
        int a;
	int b;
	a = 2;
	if(a < 2)
		b = 2;
	else
		b = 3;
	return f(10);
}