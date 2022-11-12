/*
This program uses the "Sieve of Erastosthones" to find primes below a max val

From Wikipedia: Algorithm Sieve of Eratosthenes is

    input: an integer n > 1.
    output: all prime numbers from 2 through n.

    let A be an array of Boolean values, indexed by integers 2 to n,
    initially all set to true.

    for i = 2, 3, 4, ..., not exceeding √n do
        if A[i] is true
            for j = i^2, i^2+i, ..., not exceeding n do
                set A[j] := false

    return all i such that A[i] is true.
*/

#include <iostream>
#include <vector>

void sieve_of_eras(int max_val)
{
  std::vector<bool> b_values(max_val);
  int counter; // Counter for number of primes below max_val. Output at the end

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

  std::cout << "\nPrimes:\n\n";
  for(int i = 2; i < int(b_values.size()); ++i)
  {
    if(b_values[i]){
      std::cout << i << '\t';
      if (counter%10 == 0) // Split results in columns of 10
      {
        std::cout << '\n'; // Formatting results
      }
      ++counter;
    }
  }
  std::cout << "\n\nTotal: " << counter << " primes below " << max_val << "\n\n";
}

int main()
{
  std::vector<int> primes;
  int max;

  std::cout << "+-------------+\n";
  std::cout << "| Find Primes |\n";
  std::cout << "+-------------+\n\n";

  std::cout << "Find all primes below: ";
  std::cin >> max;

  sieve_of_eras(max);
  return 0;
}
