// This program takes an input n and finds the first n primes

#include <iostream>
#include <vector>

std::vector<int> sieve_of_erastosthenes()
{
  int max_val = 7910; // for at least 1000 primes
  std::vector<bool> b_values(max_val);
  std::vector<int> primes;

  for (int i = 0; i < max_val; ++i)
    b_values[i] = true; // Initialize all vector values to true

  for (int i = 2; i*i < max_val; ++i)
  {
    if(b_values[i]) // ignore index values to false. Indexes = Multiples
      for (int j = i*i; j < max_val; j+=i)
      {
        b_values[j] = false; // set the multiples of i false
      }
  }

  for(int i = 2; i < int(b_values.size()); ++i)
  {
    if(b_values[i]){
      primes.push_back(i);
    }
  }
  return primes;
}

int main()
{
  int n; // number of primes
  std::vector<int> primes = sieve_of_erastosthenes();

  std::cout << "+----------------+\n";
  std::cout << "| First N Primes |\n";
  std::cout << "+----------------+\n\n";

  std::cout << "\nHow this program works:";
  std::cout << "\n---------------------------------------------------";
  std::cout << "\n- It takes an input N and finds the first N primes.";
  std::cout << "\n- Limited to first 1000 primes.";
  std::cout << "\n- To exit the program enter - .";
  std::cout << "\n---------------------------------------------------";

  std::cout << "\n\nN: ";
  while(std::cin >> n)
  {
    std::cout << "\nPrimes:\n";
    for (int i = 0; i < n; ++i)
    {
      std::cout << primes[i] << '\t';
      if ((i+1)%10 == 0) // Split results in columns of 10
      {
        std::cout << '\n'; // Formatting results
      }
    }
    std::cout << "\n\nN:";
  }
  std::cout << "\nPeace!\n";
  return 0;
}
