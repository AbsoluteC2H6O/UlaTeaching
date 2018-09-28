# include <bits/stdc++.h>
using namespace std;


size_t cut_bar(size_t n, size_t * &t){
	
	if(n == 0) 
		return(0);

	size_t m = t[n];
	size_t c = 0;

	for (int i = 1; i < n; ++i){
		c = t[i] + cut_bar(n - i, t);
		m = max(c, m);
	}

	return m;
}

size_t cut_bar_opt(size_t n, size_t * &t, unordered_map<size_t, size_t> & mem){
	
	if(mem.find(n) != mem.end())
		return(mem[n]);

	size_t m = t[n];
	size_t c = 0;

	for (int i = 1; i < n; ++i){
		c = t[i] + cut_bar(n - i, t);
		m = max(c, m);
	}
	mem[n] = m;
	return m;
}

int main(){
	size_t *t = new size_t[11]; 
	t[0] = 0; t[1] = 3; t[2] = 5; t[3] = 7; t[4] = 8; t[5] = 9; t[6] = 10; t[7] = 11; t[8] = 12; t[9] = 13; t[10] = 14;

	size_t r = 0;

	unordered_map<size_t, size_t> mem;
	mem[0] = 0;
	clock_t begin = clock();
	r = cut_bar(10, t);
	clock_t end = clock();
  	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;

  	cout << "Result Found without Dynamic Programming = {" << r << "}, found on: {" << elapsed_secs << "} seconds\n";

  	begin = clock();
  	r = cut_bar_opt(4, t, mem);
  	end = clock();
  	elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	cout << "Result Found with Dynamic Programming = {" << r << "}, found on: {" << elapsed_secs << "} seconds\n";

	return 0;
}
		