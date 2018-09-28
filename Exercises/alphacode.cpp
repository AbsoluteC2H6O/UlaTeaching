/*************************************************************
	Solution for problem 394.alphacode of spoj.
	Formal solution can be found here: 
		https://github.com/juankipedia/CompetitiveProgramming/blob/master/spoj/ALPHACODE.cpp 
**************************************************************/
# include <bits/stdc++.h>
using namespace std;

/**********************************************************************
	Description: recursive version of function to count all 
				 possible ways a given string can be decoded.
				 Time Complexity: O(n).
	Parameters: 
		-p: current position on given string.
		-s: encoded string.
		-n: size of encoded string. 
		-m: memory for Dynamic Programming
	Return: void, count can be found on m[0]
**********************************************************************/
void count_recursive(size_t p, string &s, size_t n, unsigned int m []){

	if(p == n - 1){
		if(s[p] == '0')
			m[p] = 0;
		else
			m[p] = 1;
		return;
	}

	count_recursive(p + 1, s, n, m);

	if(p + 1 != n and (s[p] == '1' or s[p] == '2' and s[p + 1] <= '6')){
		if(p + 2 != n and s[p + 2] == '0')
			m[p] = m[p + 1];
		else if(s[p + 1] == '0')
			m[p] = m[p + 2];
		else
			m[p] = m[p + 1] + m[p + 2];
		return;
	}
	else{
		m[p] = m[p + 1];
		return;
	}

}

/**********************************************************************
	Description: iterative version of function to count all 
				 possible ways a given string can be decoded.
				 Time Complexity: O(n).
	Parameters: 
		-s: encoded string.
		-n: size of encoded string. 
		-m: memory for Dynamic Programming
	Return: void, count can be found on m[0]
**********************************************************************/
void count_opt(string &s, size_t n, unsigned int m []){
	m[n] = 1;
	if(s[n - 1] == '0')
		m[n - 1] = 0;
	else
		m[n - 1] = 1;

	for (int p = n - 1; p >= 0; p--){
		if(p + 1 != n and (s[p] == '1' or s[p] == '2' and s[p + 1] <= '6')){
			if(p + 2 != n and s[p + 2] == '0')
				m[p] = m[p + 1];
			else if(s[p + 1] == '0')
				m[p] = m[p + 2];
			else
				m[p] = m[p + 1] + m[p + 2];
		}
		else
			m[p] = m[p + 1];
	}
}

int main (){
	string s;
	cin >> s;
	size_t n = s.length();
	unsigned int m [n + 1];
	cout << "count_recursive______________________________________________________\n";
	clock_t begin = clock();
	count_opt(s, n, m);
	clock_t end = clock();
  	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
  	cout << "Result Found with iterative version= {" << m[0] << "}, found on: {" << elapsed_secs << "} seconds\n";

	cout << "count iterative_______________________________________________________\n";
	unsigned int m2 [n + 1];
	m2[n] = 1;
	begin = clock();
	count_recursive(0, s, n, m2);
	end = clock();
  	elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	cout << "Result Found with recursive version = {" << m2[0] << "}, found on: {" << elapsed_secs << "} seconds\n";
	return 0;
}
