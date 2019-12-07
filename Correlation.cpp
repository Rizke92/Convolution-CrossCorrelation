#include <vector>
#include <iostream>


std::vector<int> reverse(std::vector<int>& x)
{
	std::vector<int> rev (x.size());
	int *start = &(*(rev.begin()));
	int *last = &(*(x.end() - 1));
	
	for(int i = 0; i < x.size(); i++)
	{
		*start = *last;
		start++;
		last--;
	}
	return rev;
}

int main()
{
	std::vector<int> ying = {1,2,3,4};

	int *last = &(*(ying.end() - 1));
	int *start = &(*(ying.begin()));
	std::cout << "\n";
	std::cout << *last << "\n";
	std::cout << *start << "\n";
	
	std::cout << "\n";
	
	std::vector<int> yang (ying.size());
	yang = reverse(ying); 
	int *star = &(*(yang.begin()));
	/*
	for(int i = 0; i < yang.size(); i++)
	{
		std::cout << *star << "\n";
		star++;
	}
	*/
	
	return 0;
}

/*	
template<typename T>
std::vector<T> xcorr(const std::vector<T>& a, const std::vector<T>& b)
{
	int result;
	int prod;
	int *w = b.end() - 1;
	int increment = 0;
	int decrement = b.size();
	
	
	for(int *x = a.begin(); x != a.end(); x++)
	{
		while( w != 0)
		{
			
			

}

template<typename T>
std::vector<T> conv(const std::vector<T>& a, const std::vector<T>& b)
{

}
*/
	

