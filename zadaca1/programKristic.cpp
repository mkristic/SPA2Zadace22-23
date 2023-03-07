#include<iostream>
#include<vector>

using namespace std;

class Dictionary
{
	private:
	vector< pair<int, float> > hash_table;
	
	// insert
	void insert(int k, float value);

	// search
	pair<int, float> search(int k);
	
	// delete
	void delete_p(int k);
    
};

void Dictionary::insert(int k, float value)
{
	bool found = false;
	for (auto h : hash_table)
	{
		if (k == h.first) // ako k vec postoji
		{
			found = true;
			h.second = value;
		}
	}

	if (found == false) // ako k ne postoji
	{
		auto p = make_pair(k, value);
		hash_table.push_back(p);
	}
}

pair<int, float> Dictionary::search(int k)
{	
	for (auto h : hash_table)
	{
		if (k == h.first)
		{
			return h;
		}	
	}
	return make_pair(NULL, NULL);	
}

void Dictionary::delete_p(int k)
{
	int i = 0;
	for (auto h : hash_table)
	{
		i++;
		if (k == h.first)
		{
			hash_table.erase(hash_table.begin()+i);
		}
	}
}

int main()
{
	vector< pair<int, float> > hash_table;

    int keys[10] = {77, 69, 39, 70, 6, 8, 40, 89, 49, 15};
	
	// pairs
    pair<int, float> p1;
    pair<int, float> p2;
    pair<int, float> p3;
    pair<int, float> p4;
    pair<int, float> p5;
    pair<int, float> p6;
    pair<int, float> p7;
    pair<int, float> p8;
    pair<int, float> p9;
    pair<int, float> p10;
    
    hash_table = {p1, p2, p3, p4, p5, p6, p7, p8, p9, p10};
	
	// ubacivanje keyjeva
    for (int i = 0; i < 10; i++)
    {
        hash_table[i].first = keys[i]; 
    }
	
	// ubacivanje valuesa
	for (int i = 0; i < 10; i++)
    {
        hash_table[i].second = (float) (i+1) / 10; 
    }
    
	// ispis
    for (auto c : hash_table)
    {
        cout << "K:" << c.first << " " << "V:" << c.second << " ";
    }
	
	

    return 0;
}
