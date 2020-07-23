#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Cache_Set{

private:
	int num_words_in_block;//Number of words in each block
	int num_sets; //Number of sets
	int set_index;//Set index
	int size_sets; //Size of each set
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
	Cache_Set(int block_size, int size_sets, int num_sets, int set_index){
		this.num_words_in_block = block_size/4; //each word is 4 bytes
		this.size_sets = size_sets;
		this.num_sets = num_sets;
		this.set_index = set_index;
		mem = new int[size_sets*this.num_words_in_block];//allocating memory
		valid = new int[size_sets];
		lru_count = new int[size_sets];
		tag = new int[size_sets];
		dirty = new int[size_sets];
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
		int set_offset=-1;
		int block_offset=1;
		for(int i=0; i< log2(num_words_in_block)-1;++i){
			block_offset=(block_offset<<1)|1;
		}
		block_offset = block_offset & address;
		int data;
		int tagc= (address/num_sets)/num_words_in_block;
		for(int i =0; i<size_sets; ++i){
			if(tag[i]==tagc && valid[i]=1){
				set_offset=i;
				break;
			}
		}
		if(set_offset==-1){
			bool flag = false;
			for(int i = 0; i < size_sets; ++i){
				if(valid[i]==0)	flag = true;
			}
			if(!flag)	this.evictblock();
			this.fetchblock(address);
			for(int i =0; i<size_sets; ++i){
				if(tag[i]==tagc && valid[i]=1){
					set_offset=i;
					break;
				}
			}
			data = mem[set_offset*num_words_in_block + block_offset];
			for(int i=0; i<size_sets; ++i)	lru_count[i]++;

		}
		else{
			data = mem[set_offset*num_words_in_block + block_offset];
			for(int i=0; i<size_sets; ++i)	lru_count[i]++;
			lru_count[set_offset]=1;
		}
		return data;
	}

	int write2address(int data, int address){
		this.write++;


	}
	void evictblock(){
		int set_offset = -1, temp = -1;
		for(int i = 0; i < size_sets; ++i)	if(temp<lru_count[i])	set_offset=i;
		int address = tag[set_offset]*num_sets*num_words_in_block;
		address |= (set_index*num_words_in_block); 
		if(dirty[set_offset]=1){
			for(int i = 0; i < num_words_in_block; ++i) memory[address+i] = mem[set_offset+i];
		}
		valid[set_offset]=0;
	}

	void fetchblock(int address){
		this.miss++;
		int set_offset;
		for(int i = 0; i < size_sets; ++i) 	if(valid[i]=0)	set_offset=i;
		int quot = address/
	}
}

