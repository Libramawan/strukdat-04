/**
 * Program  : Data_Pegawai
 * Nama     : Prayudha Adhitia Libramawan
 * NPM      : 140810180008
 * Deskripsi : Program ini dapat memanipulasi dan mencetak data pegawai yang diinput.
 * Tahun    : 2019
 */
#include <iostream>
#include <iomanip>
#include <conio.h>
using namespace std;

struct ElemtList{
	char nama[30];
    char divisi[20];
	int gaji;
	ElemtList* next;
};
typedef ElemtList* pointer;
typedef pointer List;

void createList(List& First);
void createElmt(pointer& pBaru);
void insertFirst(List& First, pointer pBaru);
void traversal(List First);
void deleteFirst(List& First, pointer& pHapus);
void insertLast(List& First, pointer pBaru);
void deleteLast(List& First, pointer& pHapus);

int main(){
	pointer p;
	List Pegawai;
	int pil,n;
	char loop='Y';
	do{
		system("CLS");
		cout<<setfill('-')<<setw(60);
		cout << "\n\t  SELAMAT DATANG\n\t\tDI "<<endl;
   		cout << "\tPROGRAM DATA PEGAWAI" << endl;
    	cout<<setfill('-')<<setw(60);
		cout<<"\nBanyak Data Pegawai : ";cin>>n;
		createList(Pegawai);
		for(int i=0; i<n; i++){
			cout<<"\nData Pegawai ke-"<<i+1<<endl;
			createElmt(p);
			insertLast(Pegawai,p);
		}
		do{
			system("CLS");
			cout<<"1. Buat Data Pegawai Baru di Awal\t4. Hapus Data Pegawai Paling Akhir\n";
			cout<<"2. Buat Data Pegawai Baru di Akhir\t5. Cetak Data Pegawai\n";
			cout<<"3. Hapus Data Pegawai Paling Awal\t6. Buat List Data Pegawai Baru\n";
			do{
				cin>>pil;
			}while(pil<1 || pil>6);
			switch(pil){
				case 1:
					createElmt(p);
					insertFirst(Pegawai,p);
					cout<<"\nData berhasil dibuat! silahkan tekan enter lagi\n";
					getch();
					break;
				case 2:
					createElmt(p);
					insertLast(Pegawai,p);
					cout<<"\nData berhasil dibuat! silahkan tekan enter lagi\n";
					getch();
					break;
				case 3:
					deleteFirst(Pegawai,p);
					cout<<"\nData berhasil dihapus! silahkan tekan enter lagi\n";
					getch();
					break;
				case 4:
					deleteLast(Pegawai,p);
					cout<<"\nData berhasil dihapus! silahkan tekan enter lagi\n";
					getch();
					break;
				case 5:
                    cout<<"No\tNama\t\t\t\tDivisi\t\t\tGaji"<<endl;
                    cout<<setfill('-')<<setw(100);
					traversal(Pegawai);
					cout<<"\nKembali ke menu? (Y/N) ";
					do{
						cin>>loop;
					}while(loop!='Y' && loop!='y' && loop!='N' && loop!='n');
					break;
				case 6:
					loop='s';
					break;
			}
		}while(loop=='Y' || loop=='y');
	}while(loop=='s');
}

void createList(List& First){
	First=NULL;
}
void createElmt(pointer& pBaru){
	pBaru=new ElemtList;
	cout<<"Nama\t\t: ";cin.ignore();cin.getline(pBaru->nama,30);
    cout<<"Divisi\t\t: ";cin.getline(pBaru->divisi,20);
	cout<<"Gaji\t\t: Rp. ";cin>>pBaru->gaji;
    pBaru->next=NULL;
}
void insertFirst(List& First, pointer pBaru){
	if(First==NULL){
		First=pBaru;
	}else{
		pBaru->next=First;
		First=pBaru;
	}
}
void traversal(List First){
	pointer pBantu;
	int i=1;
	if(First==NULL){
		cout<<"List Kosong"<<endl;
	}else{
		pBantu=First;
        while(pBantu!=NULL){
			cout<<"\n"<<i<<"\t";
			cout<<pBantu->nama<<"\t\t\t";
            cout<<pBantu->divisi<<"\t\t";
			cout<<"Rp. "<<pBantu->gaji;
			pBantu=pBantu->next;
			i++;
        }
	}
	cout<<endl;
}
void deleteFirst(List& First, pointer& pHapus){
	if(First==NULL){
		pHapus=NULL;
		cout<<"List kosong, tidak ada yang dihapus"<<endl;
	}else if(First->next==NULL){
		pHapus=First;
		First=NULL;
	}else{
		pHapus=First;
		First=First->next;
		pHapus->next=NULL;
	}
}
void insertLast(List& First, pointer pBaru){
	pointer last;
	if(First==NULL){
		First=pBaru;
	}else{
		last=First;
		while(last->next!=NULL){
			last=last->next;
		}
		last->next=pBaru;
	}
}
void deleteLast(List& First, pointer& pHapus){
	pointer last,precLast;
	if(First==NULL){
		cout<<"List Kosong";
	}else if(First->next==NULL){
		pHapus=First;
		First=NULL;
	}else{
		last=First;
		precLast=NULL;
		while(last->next!=NULL){
			precLast=last;
			last=last->next;
		}
		pHapus=last;
		precLast->next=NULL;
	}
}
