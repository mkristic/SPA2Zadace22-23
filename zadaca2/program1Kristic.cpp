#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <random>
#include <math.h>
#include <time.h>  

using namespace std;

class universal_hash
{
	private:
    vector<list<pair<int,float>>> table {7};
    vector<int> prob_coeff;

	public:
    universal_hash();
    int hash_func(int key);

    void insert(int key, float value);
    float search(int key);

    void print_coeff() const;
    void print_table() const;
};

universal_hash::universal_hash()
{
    default_random_engine generator; 
    uniform_int_distribution<int> distribution(0,6);
    generator = default_random_engine(time(0));

    for(int i = 0; i < 7; i++)
	{
        prob_coeff.push_back(distribution(generator)); 
    }
}

void universal_hash::print_coeff() const
{
    for(auto i : prob_coeff)
	{
        cout << i << " ";
    }

    cout << endl;
}

int universal_hash::hash_func(int key)
{
    int sum = 0;
    int n = floor(log10(key));
	
    for(int i = 0; i <= n; i++)
	{
        int digit = key % 10;
        sum += digit * prob_coeff[i];
        key /= 10;
    }

    return sum % 7;
}

void universal_hash::insert(int key, float value)
{
    int index = hash_func(key);
    pair<int,float> insert = {key, value};

    for(auto &i : table[index])
	{
        if(i.first == key)
		{
            i.second = value;
            return;
        }
    }

    table[index].push_back(insert);
    return;
}

void universal_hash::print_table() const
{
    for(int i = 0; i < 7; i++)
	{
        cout << "List" << endl;
		
        for(auto &j : table[i])
		{
            cout << "Key:" << j.first << " Value:" << j.second << " ";
        }
        cout << endl;
    }
}

float universal_hash::search(int key)
{
    int index = hash_func(key);
	
    for(auto &i : table[index])
	{
        if(i.first == key)
		{
            return i.second;
        }
    }

    return -1e9;
}

int main(){

    universal_hash H;

    auto generator = default_random_engine(time(0));
    auto distribute = uniform_real_distribution<float>(-1, 1);

    vector<int> keys = {127, 99, 331, 381, 35, 434, 372, 72, 383, 12, 309, 500, 146, 81, 132, 316, 222, 329, 15, 377, 92};

    for(const auto& i : keys) 
	{
        H.insert(i, distribute(generator)); 
    }

    H.print_table();
	
    cout << endl;
    cout << H.search(127) << endl;
	
    return 0;
}