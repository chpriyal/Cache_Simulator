#include <iostream>
#include <string>

using namespace std;

class Cache_Set{

private:
	int num_words_in_block;//Number of words in each block
	int num_sets; //Size of each set
	int * mem; //Cache memory
	int * tag;
	int * valid;
	int * lru_count;
	int * dirty;


public:

	int miss;
	int reads;
	int writes;
	//Constructor
	Cache_Set(int block_size, int num_sets){
		this.num_words_in_block = block_size/4; //each word is 4 bytes
		this.num_sets = num_sets;
		mem = new int[num_sets*this.num_words_in_block];//allocating memory
		valid = new int[num_sets];
		lru_count = new int[num_sets];
		tag = new int[num_sets];
		dirty = new int[num_sets];
		miss=0;
		reads=0;
		writes=0;
	}

	//Destructor
	
	~Cache_Set(){
		delete [] mem;
		delete [] valid;
		delete [] lru_count;
		delete [] dirty;
		delete [] tag;
	}

	int read_address(int address){
		this.read++;
		int set_offset=0;
		for(int i =0; i<num_sets; ++i){
			if(tag[i]==)
		}

	}

	int write2address(int data, int address){
		this.write++;

	}
	void evictblock(){

	}

	void fetchblock(int address){
		this.miss++;
	}
}

