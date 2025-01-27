#include <string>
#include <iostream>

void InputString(std::string& target){
	std::getline(std::cin >> std::ws, target);
}

class Contact{
	public:
		std::string nama,tempat_tinggal,alamat,kekuatan;
		
		Contact(){
			nama = tempat_tinggal = alamat = kekuatan = "";
		}
};

class PhoneBook{
	private:
		int size;
		int idx;
		Contact contact[8];

		int GetIndex(std::string name){
			int ret = -1;
			for(int i = 0; i < size ; i++) if( contact[i].nama == name ) ret = i;
			return ret;
		}
	public:
		PhoneBook(){
			size = 0;
			idx = 0;
			for(auto &c : contact) c = Contact();
		}
		
		void ADD(){
			std::cout<<"Masukkan nama: ";
			InputString( contact[idx].nama );
			std::cout<<"Masukkan tempat tinggal: "; 
			InputString( contact[idx].tempat_tinggal );
			std::cout<<"Masukkan alamat: "; 
			InputString( contact[idx].alamat );
			std::cout<<"Masukkan kekuatan: "; 
			InputString( contact[idx].kekuatan );
			idx = (idx+1)%8;
			size++;
			size = std::min(size,8);
		}
		
		void SEARCH(){
			for(int i = 0; i < size ; i++) std::cout<<i+1<<". "<<contact[i].nama<<"\n";
			std::cout<<"Masukkan nama kontak yang ingin dicari: ";
			std::string nama_kontak;
			InputString(nama_kontak);
			while( GetIndex(nama_kontak) == -1 ){
				std::cout<<"Nama kontak tidak valid!\n\n";
				std::cout<<"Masukkan nama kontak yang ingin dicari: ";
				InputString(nama_kontak);
			}
			int index = GetIndex(nama_kontak);
			std::cout<<"Nama : "<<contact[index].nama<<"\n";
			std::cout<<"Tempat tinggal : "<<contact[index].tempat_tinggal<<"\n";
			std::cout<<"Alamat : "<<contact[index].alamat<<"\n";
			std::cout<<"Kekuatan : "<<contact[index].kekuatan<<"\n\n";
		}
};

int main(){
	std::string operasi;
	PhoneBook BukuKontak;
	while(true){
		std::cin>>operasi;
		if( operasi == "ADD" ) BukuKontak.ADD();
		else if( operasi == "SEARCH" ) BukuKontak.SEARCH();
		else break;
	}
	return 0;
}
