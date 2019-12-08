#include <vector>
#include <iostream>
#include <fstream>

//--- Reverse -----------------------------------------------------
std::vector<int> reverse(const std::vector<int>& x)
{
	std::vector<int> rev (x.size());
	int *start = &(*(rev.begin()));
	const int *last = &(*(x.cend() - 1));
	
	for(int i = 0; i < x.size(); i++)
	{
		*start = *last;
		start++;
		last--;
	}
	return rev;
}
//--- Convolution -------------------------------------------------------------
std::vector<int> conv(const std::vector<int>& x, const std::vector<int>& z)
{
	std::vector<int> y(z.size());           // declare vector y
	y = reverse(z);                         // reverse the order of b into y
	size_t siz = (x.size() + y.size()) - 1; // size of solution vector
	std::vector<int> solution(siz);         // declare solution vector
	const int *yback = &(*(y.cend() - 1));  // pointer to the last element of vector y
	const int *xStart = &(*(x.begin()));    // pointer to begining of vector x
	int sum = 0;                          
	int xSize = x.size();
	int ySize = y.size(); 
	int a = 0;                            // counter for steping throught x values
	int b = 0;                            // couunter for steping throught y values
	int product;
	int result = 0;
	
	int step = 0;
	while( step != (siz + 1))
	{
		a = 0;                         // reset a count
		b = step;                      // set b to value of step
		while( a != step + 1 && b >= 0)   
		{
			if(a < xSize && b < ySize)
			{
				product = *(yback - b) * (*(xStart + a)); 
			}
			else
			{
				product = 0;
			}
			sum += product;
			a++;
			b--;
		}
		result = sum;
		sum = 0;                               // reset the sum;
		solution[step] = result;              // store results in the soultion vector
		step++;
	}
	return solution;
}

//--- Cross Correlation --------------------------------------------------------------------
std::vector<int> xcorr(const std::vector<int>& x, const std::vector<int>& y)
{
	size_t siz = (x.size() + y.size()) - 1; // size of solution vector
	std::vector<int> solution(siz);         // declare solution vector
	const int *yback = &(*(y.cend() - 1));  // pointer to the last element of vector y
	const int *xStart = &(*(x.begin()));    // pointer to begining of vector x
	int sum = 0;                          
	int xSize = x.size();
	int ySize = y.size(); 
	int a = 0;                            // counter for steping throught x values
	int b = 0;                            // couunter for steping throught y values
	int product;
	int result = 0;
	
	int step = 0;
	while( step != (siz + 1))
	{
		a = 0;                         // reset a count
		b = step;                      // set b to value of step
		while( a != step + 1 && b >= 0)   
		{
			if(a < xSize && b < ySize)
			{
				product = *(yback - b) * (*(xStart + a)); 
			}
			else
			{
				product = 0;
			}
			sum += product;
			a++;
			b--;
		}
		result = sum;
		sum = 0;                               // reset the sum;
		solution[step] = result;              // store results in the soultion vector
		step++;
	}
	return solution;
}
	

int main()
{
	const std::vector<int> one = {1,2,3,4};
	const std::vector<int> two = {1,2,3,4};
	

	std::cout << "Vecotor one = ";
	for(int  w = 0; w < one.size(); w++)
	{
		std::cout << one[w] << " "; 
	}
	std::cout << "\n";
	
	std::cout << "Vecotor two = ";
	for(int w = 0; w < two.size(); w++)
	{
		std::cout << two[w] << " "; 
	}
	std::cout << "\n";
	
	std::vector<int> xcros;
	xcros = xcorr(one, two);
	
	std::cout << "Cross Correlation = ";
	for(int w = 0; w < xcros.size(); w++)
	{
		std::cout << xcros[w] << " "; 
	}
	std::cout << "\n";
	
	std::vector<int>con;
	con = conv(one, two);
	std::cout << "Convolution = ";
	for(int w = 0; w < con.size(); w++)
	{
		std::cout << con[w] << " "; 
	}
	std::cout << "\n";
	
	//1 4 10 20 25 24 16 
	
	
	return 0;
}

	

