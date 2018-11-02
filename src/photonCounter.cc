#include <iostream>

#include "photonCounter.hh"

void photonCounter::push_back(const int &id){
	while(size <= id){
		Nphotons.push_back(0);
		size++;
	}
}

void photonCounter::addPhoton(const int &id){
	if(id >= size) return;
	Ntotal++;
	Nphotons.at(id)++;
}
	
int photonCounter::getPhotonCount(const int &id) const {
	if(id >= size) return -1;
	return Nphotons.at(id);
}
	
void photonCounter::print() const {
	if(size == 0) return;
	std::cout << " maxID=" << size-1 << ", total=" << Ntotal << std::endl;
	for(size_t i = 0; i < Nphotons.size(); i++){
		std::cout << "  id=" << i << " N=" << Nphotons.at(i) << std::endl;
	}
}

void photonCounter::clear(){
	Nphotons.clear();
	Ntotal = 0;
	size = 0;
}
