int fibo(int n);

int main(int argc, char * argv[]) {
	return fibo(8);
}

int fibo(int n) {
	if(n==0) {
		return 1;
	} else if(n==1) {
		return 1;
	} else {
		return fibo(n-1) + fibo(n-2);
	}
}



