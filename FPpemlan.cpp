/*3. APLIKASI PENDATAAN RUMAH SAKIT												
	DATA: DATA PASIEN YANG MEMILIKI KARAKTERISTIK SEBAGAI BERIKUT											
		- ID PASIEN										
		- NAMA PASIEN										
		- JENIS PENYAKIT (DEMAM BERDARAH, KECELAKAAN, DLL)										
		- JENIS KAMAR (VIP, III, II, I)										
		- NOMOR KAMAR										
		- TANGGAL MASUK 										
												
	OPERASI:											
		- TAMBAH DATA										
		- UBAH DATA										
		- PENCARIAN DATA BERDASARKAN KRITERIA DATANYA (NAMA PASIEN, ID PASIEN, NOMOR KAMAR)										
		- PENGURUTAN DATA BERDASARKAN KRITERIA DATANYA (ID PASIEN, NAMA, JENIS PENYAKIT, JENIS KAMAR, NOMOR KAMAR, TANGGAL MASUK)	*/
		
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#include <iostream>
using namespace std;

struct pasien{
	string nama;
	int id;
	string jpenyakit;
}; pasien psn[100];

struct tanggal{
	int tanggal;
	string bulan;
	int tahun;
};

struct kamar{
	string jkamar;
	int nkamar;
	tanggal tgl;
}; kamar kmr[100];

string printBulan(string bln){
	if (bln.compare("01") == 0) return "Januari";
	else if (bln.compare("02") == 0) return "Februari";
	else if (bln.compare("03") == 0) return "Maret";
	else if (bln.compare("04") == 0) return "April";
	else if (bln.compare("05") == 0) return "Mei";
	else if (bln.compare("06") == 0) return "Juni";
	else if (bln.compare("07") == 0) return "Juli";
	else if (bln.compare("08") == 0) return "Agustus";
	else if (bln.compare("09") == 0) return "September";
	else if (bln.compare("10") == 0) return "Oktober";
	else if (bln.compare("11") == 0) return "November";
	else if (bln.compare("12") == 0) return "Desember";
}

void ubahdata(){
	int caridata,jumlah,pilihm,found=0;
	printf("Masukkan ID pasien yang ingin id ubah datanya : ");
	scanf("%d",&caridata);
	for(int i;i<jumlah;i++){
		if(caridata == psn[i].id){
			found = 1;
			break;
		}
		else if(caridata != psn[i].id){
			found = 0;
		}
	}
	
	if(found == 1){
		int pilih;
		printf("Masukkan Nama Pasien : ");
		getline(cin,psn[jumlah].nama);
		fflush(stdin);
		printf("\nMasukkan Jenis Penyakit : ");
		getline(cin,psn[jumlah].jpenyakit);
		fflush(stdin);
		printf("\nList kamar Pasien\n");
		printf("1. I\n2. II\n3. III\n4. VIP");
		printf("\nMasukkan Jenis Kamar untuk pasien : ");
		scanf("%d", &pilih);
		fflush(stdin);
				
		if (pilih == 1) kmr[jumlah].jkamar = "I";
		else if (pilih == 2) kmr[jumlah].jkamar = "II";
		else if (pilih == 3) kmr[jumlah].jkamar = "III";
		else if (pilih == 4) kmr[jumlah].jkamar = "VIP";
		
		printf("\nMasukkan Nomor Kamar : ");
		scanf("%d", &kmr[jumlah].nkamar);
		fflush(stdin);
				
		printf("\nMasukkan Tanggal Masuk : ");
		scanf("%d", &kmr[jumlah].tgl.tanggal);
		fflush(stdin);
				
		printf("\nList Bulan\n");
		printf("1.  Januari\n2.  Februari\n3.  Maret\n4.  April\n5.  Mei\n6.  Juni\n7.  Juli\n8.  Agustus\n9.  September\n10. Oktober\n11. November\n12. Desember");
		printf("\nMasukkan Bulan Masuk : ");
		scanf("%d", &pilih);
		fflush(stdin);
				
		if (pilih == 1) kmr[jumlah].tgl.bulan = "01";
		else if (pilih == 2) kmr[jumlah].tgl.bulan = "02";
		else if (pilih == 3) kmr[jumlah].tgl.bulan = "03";
		else if (pilih == 4) kmr[jumlah].tgl.bulan = "04";
		else if (pilih == 5) kmr[jumlah].tgl.bulan = "05";
		else if (pilih == 6) kmr[jumlah].tgl.bulan = "06";
		else if (pilih == 7) kmr[jumlah].tgl.bulan = "07";
		else if (pilih == 8) kmr[jumlah].tgl.bulan = "08";
		else if (pilih == 9) kmr[jumlah].tgl.bulan = "09";
		else if (pilih == 10) kmr[jumlah].tgl.bulan = "10";
		else if (pilih == 11) kmr[jumlah].tgl.bulan = "11";
		else if (pilih == 12) kmr[jumlah].tgl.bulan = "12";
				
		printf("\nMasukkan Tahun Masuk : ");
		scanf("%d", &kmr[jumlah].tgl.tahun);
		fflush(stdin);
				
		psn[jumlah].nama == psn[jumlah].nama;
		psn[jumlah].jpenyakit == psn[jumlah].jpenyakit;
		kmr[jumlah].jkamar == kmr[jumlah].jkamar;
		kmr[jumlah].tgl.tanggal == kmr[jumlah].tgl.tanggal;
		kmr[jumlah].tgl.bulan == kmr[jumlah].tgl.bulan;
		kmr[jumlah].tgl.tahun == kmr[jumlah].tgl.tahun;
	}else
		printf("DATA TIDAK DITEMUKAN");
	
	getch();
	system("cls");
}

void binary_search_Nama(){
	
}

void binary_search_ID(){
	int caridata, i=0, ketemu=0,jumlah;
	int awal=0, akhir;
	int tengah=(awal+akhir)/2;
	akhir = jumlah;
	printf("\nMasukkan ID pasien yang ingin di cari : "); 
    scanf("%d",&caridata);
    while(i<jumlah){
    	if(caridata == psn[tengah].id){
			ketemu=1;
			break;
		}else if(caridata > psn[tengah].id){
    		awal=tengah+1;
    		tengah=(awal+akhir)/2;
    		ketemu=1;
		}else if(caridata < psn[tengah].id){
			akhir=tengah-1;
			tengah=(awal+akhir)/2;
			ketemu=1;
		}
		i++;	
	}
	if(ketemu==1){
		printf("DATA DITEMUKAN");
		cout << "\nNama\t\t: " << psn[tengah].nama;
		printf("\nID\t\t: %d", psn[tengah].id);
		cout << "\nJenis Penyakit\t: " << psn[tengah].jpenyakit;
		cout << "\nJenis Kamar\t: "  << kmr[tengah].jkamar;
		printf("\nNomor Kamar\t: %d", kmr[tengah].nkamar);
		cout << "\nTanggal Masuk\t: " << kmr[tengah].tgl.tanggal << " " << printBulan(kmr[tengah].tgl.bulan) << " " << kmr[tengah].tgl.tahun;
	}else
		printf("DATA TIDAK DITEMUKAN");
	getch();
	system("cls");
}

void binary_search_Nkamar(){
	int caridata, i=0, ketemu=0,jumlah;
	int awal=0, akhir;
	int tengah=(awal+akhir)/2;
	akhir = jumlah;
	printf("\nMasukkan Nomor Kamar yang ingin di cari : "); 
    scanf("%d",&caridata);
    while(i<jumlah){
    	if(caridata == kmr[tengah].nkamar){
			ketemu=1;
			break;
		}else if(caridata > kmr[tengah].nkamar){
    		awal=tengah+1;
    		tengah=(awal+akhir)/2;
    		ketemu=1;
		}else if(caridata < kmr[tengah].nkamar){
			akhir=tengah-1;
			tengah=(awal+akhir)/2;
			ketemu=1;
		}
		i++;	
	}
	if(ketemu==1){
		printf("DATA DITEMUKAN");
		for (i = 0; i < kmr[tengah].nkamar ; i++) {
			cout << "\nNama\t\t: " << psn[i].nama;
			printf("\nID\t\t: %d", psn[i].id);
			cout << "\nJenis Penyakit\t: " << psn[i].jpenyakit;
			cout << "\nJenis Kamar\t: "  << kmr[i].jkamar;
			printf("\nNomor Kamar\t: %d", kmr[i].nkamar);
			cout << "\nTanggal Masuk\t: " << kmr[i].tgl.tanggal << " " << printBulan(kmr[i].tgl.bulan) << " " << kmr[i].tgl.tahun;
		}
	}else
		printf("DATA TIDAK DITEMUKAN");
	getch();
	system("cls");
}

int main() {
	
	int jumlah=0,dicari,awal=0,ketemu=0;
	
	int pilih,menu,loop=0,search,datatengah;
	
	while (loop == 0) {
		system("cls");
		printf("+------------------------------+-----------------------------+\n");
		printf("+---------------------+ Selamat Datang +---------------------+\n");
		printf("+------------------------------+-----------------------------+\n");
		printf("+-----  1. Pasien Baru                                  -----+\n");
		printf("+-----  2. Ubah Data Pasien                             -----+\n");
		printf("+-----  3. Mencari Data Pasien                          -----+\n");
		printf("+-----  4. Tampikan Data Pasien Secara Urut             -----+\n");
		printf("+-----  5. Keluar                                       -----+\n");
		printf("+---------------------------+--+--+--------------------------+\n");
		printf(" Silahkan pilih: ");
		scanf("%d", &menu);
		system("cls");
		fflush(stdin);
		
		switch(menu) {
			case 1: //Pasien Baru
				printf("Masukkan Data Pasien Baru\n\n");
				printf("Masukkan Nama Pasien : ");
				getline(cin,psn[jumlah].nama);
				fflush(stdin);
				
				printf("\nMasukkan Jenis Penyakit : ");
				getline(cin,psn[jumlah].jpenyakit);
				fflush(stdin);
				
				printf("\nList kamar Pasien\n");
				printf("1. I\n2. II\n3. III\n4. VIP");
				printf("\nMasukkan Jenis Kamar untuk pasien : ");
				scanf("%d", &pilih);
				fflush(stdin);
				
				if (pilih == 1) kmr[jumlah].jkamar = "I";
				else if (pilih == 2) kmr[jumlah].jkamar = "II";
				else if (pilih == 3) kmr[jumlah].jkamar = "III";
				else if (pilih == 4) kmr[jumlah].jkamar = "VIP";
				
				printf("\nMasukkan Nomor Kamar : ");
				scanf("%d", &kmr[jumlah].nkamar);
				fflush(stdin);
				
				printf("\nMasukkan Tanggal Masuk : ");
				scanf("%d", &kmr[jumlah].tgl.tanggal);
				fflush(stdin);
				
				printf("\nList Bulan\n");
				printf("1.  Januari\n2.  Februari\n3.  Maret\n4.  April\n5.  Mei\n6.  Juni\n7.  Juli\n8.  Agustus\n9.  September\n10. Oktober\n11. November\n12. Desember");
				printf("\nMasukkan Bulan Masuk : ");
				scanf("%d", &pilih);
				fflush(stdin);
				
				if (pilih == 1) kmr[jumlah].tgl.bulan = "01";
				else if (pilih == 2) kmr[jumlah].tgl.bulan = "02";
				else if (pilih == 3) kmr[jumlah].tgl.bulan = "03";
				else if (pilih == 4) kmr[jumlah].tgl.bulan = "04";
				else if (pilih == 5) kmr[jumlah].tgl.bulan = "05";
				else if (pilih == 6) kmr[jumlah].tgl.bulan = "06";
				else if (pilih == 7) kmr[jumlah].tgl.bulan = "07";
				else if (pilih == 8) kmr[jumlah].tgl.bulan = "08";
				else if (pilih == 9) kmr[jumlah].tgl.bulan = "09";
				else if (pilih == 10) kmr[jumlah].tgl.bulan = "10";
				else if (pilih == 11) kmr[jumlah].tgl.bulan = "11";
				else if (pilih == 12) kmr[jumlah].tgl.bulan = "12";
				
				psn[jumlah].id = jumlah+1;
				
				printf("\nMasukkan Tahun Masuk : ");
				scanf("%d", &kmr[jumlah].tgl.tahun);
				fflush(stdin);
				
				system("cls");
				printf("\nData Pasien \n");
				
				cout << "\nNama\t\t: " << psn[jumlah].nama;
				printf("\nID\t\t: %d", psn[jumlah].id);
				cout << "\nJenis Penyakit\t: " << psn[jumlah].jpenyakit;
				cout << "\nJenis Kamar\t: "  << kmr[jumlah].jkamar;
				printf("\nNomor Kamar\t: %d", kmr[jumlah].nkamar);
				cout << "\nTanggal Masuk\t: " << kmr[jumlah].tgl.tanggal << " " << printBulan(kmr[jumlah].tgl.bulan) << " " << kmr[jumlah].tgl.tahun;
				
				getch();
				
				jumlah++;
				
				break;
			case 2 : //ubah data
				ubahdata();
				break;
			case 3 : //binary search
				printf("Pengurutan berdasarkan: \n");
				printf("1. Cari Nama\n2. Cari ID\n3. Cari Nomor Kamar");
				printf("\nasukkan pilihan : ");
				scanf("%d", &pilih);
				
				if (pilih == 1)	 {
					binary_search_Nama();
				}		
				else if (pilih == 2) {
					binary_search_ID();
				}
				else if (pilih == 3) {
					binary_search_Nkamar();
				}
				break;
			case 4 : // shell sort
				printf("Pengurutan berdasarkan: \n");
				printf("1. ID Pasien\n2. Nama\n3. Jenis Penyakit\n4. Jenis Kamar\n5. Nomor Kamar\n6. Tanggal Masuk");
				printf("\nMasukkan kriteria : ");
				scanf("%d", &pilih);
				
				int gap, right, jump, i, batas[100][100];
				
				system("cls");
				
				if (pilih == 1) {
					printf("Data sesuai ID:\n");
					for (gap = jumlah/2; gap > 0; gap /= 2) {
						for (right = gap; right < jumlah; right ++) {
							int tempINT[4] = {psn[right].id, kmr[right].nkamar, kmr[right].tgl.tanggal, kmr[right].tgl.tahun};
							string tempString[4] = {psn[right].nama, psn[right].jpenyakit, kmr[right].jkamar, kmr[right].tgl.bulan};
							
							for (jump = right; jump >= gap && psn[jump-gap].id > tempINT[0]; jump -= gap) {
								psn[jump].id = psn[jump-gap].id;
								psn[jump].nama = psn[jump-gap].nama;
								psn[jump].jpenyakit = psn[jump-gap].jpenyakit;
								kmr[jump].nkamar = kmr[jump-gap].nkamar;
								kmr[jump].jkamar = kmr[jump-gap].jkamar;
								kmr[jump].tgl.tanggal = kmr[jump-gap].tgl.tanggal;
								kmr[jump].tgl.bulan = kmr[jump-gap].tgl.bulan;
								kmr[jump].tgl.tahun = kmr[jump-gap].tgl.tahun;
							}
							
							psn[jump].id = tempINT[0];
							psn[jump].nama = tempString[0];
							psn[jump].jpenyakit = tempString[1];
							kmr[jump].nkamar = tempINT[1];
							kmr[jump].jkamar = tempString[2];
							kmr[jump].tgl.tanggal = tempINT[2];
							kmr[jump].tgl.bulan = tempString[3];
							kmr[jump].tgl.tahun = tempINT[3];
						}
					}
				} else if (pilih == 2) {
					printf("Data sesuai nama:\n");
				} else if (pilih == 3) {
					printf("Data sesuai jenis penyakit:\n");
				} else if (pilih == 4) {
					printf("Data jenis kamar:\n");
					for (gap = jumlah/2; gap > 0; gap /= 2) {
						for (right = gap; right < jumlah; right ++) {
							int tempINT[4] = {psn[right].id, kmr[right].nkamar, kmr[right].tgl.tanggal, kmr[right].tgl.tahun};
							string tempString[4] = {psn[right].nama, psn[right].jpenyakit, kmr[right].jkamar, kmr[right].tgl.bulan};
							
							for (jump = right; jump >= gap && kmr[jump-gap].jkamar > tempString[2]; jump -= gap) {
								psn[jump].id = psn[jump-gap].id;
								psn[jump].nama = psn[jump-gap].nama;
								psn[jump].jpenyakit = psn[jump-gap].jpenyakit;
								kmr[jump].nkamar = kmr[jump-gap].nkamar;
								kmr[jump].jkamar = kmr[jump-gap].jkamar;
								kmr[jump].tgl.tanggal = kmr[jump-gap].tgl.tanggal;
								kmr[jump].tgl.bulan = kmr[jump-gap].tgl.bulan;
								kmr[jump].tgl.tahun = kmr[jump-gap].tgl.tahun;
								
							}
							
							psn[jump].id = tempINT[0];
							psn[jump].nama = tempString[0];
							psn[jump].jpenyakit = tempString[1];
							kmr[jump].nkamar = tempINT[1];
							kmr[jump].jkamar = tempString[2];
							kmr[jump].tgl.tanggal = tempINT[2];
							kmr[jump].tgl.bulan = tempString[3];
							kmr[jump].tgl.tahun = tempINT[3];
						}
					}
				}else if (pilih == 5) {
					printf("Data sesuai nomor kamar:\n");
					for (gap = jumlah/2; gap > 0; gap /= 2) {
						for (right = gap; right < jumlah; right ++) {
							int tempINT[4] = {psn[right].id, kmr[right].nkamar, kmr[right].tgl.tanggal, kmr[right].tgl.tahun};
							string tempString[4] = {psn[right].nama, psn[right].jpenyakit, kmr[right].jkamar, kmr[right].tgl.bulan};
							
							for (jump = right; jump >= gap && kmr[jump-gap].nkamar > tempINT[1]; jump -= gap) {
								psn[jump].id = psn[jump-gap].id;
								psn[jump].nama = psn[jump-gap].nama;
								psn[jump].jpenyakit = psn[jump-gap].jpenyakit;
								kmr[jump].nkamar = kmr[jump-gap].nkamar;
								kmr[jump].jkamar = kmr[jump-gap].jkamar;
								kmr[jump].tgl.tanggal = kmr[jump-gap].tgl.tanggal;
								kmr[jump].tgl.bulan = kmr[jump-gap].tgl.bulan;
								kmr[jump].tgl.tahun = kmr[jump-gap].tgl.tahun;
								
							}
							
							psn[jump].id = tempINT[0];
							psn[jump].nama = tempString[0];
							psn[jump].jpenyakit = tempString[1];
							kmr[jump].nkamar = tempINT[1];
							kmr[jump].jkamar = tempString[2];
							kmr[jump].tgl.tanggal = tempINT[2];
							kmr[jump].tgl.bulan = tempString[3];
							kmr[jump].tgl.tahun = tempINT[3];
						}
					}
				} else if (pilih == 6) {
					printf("Data sesuai tanggal masuk:\n");
				}
				
				for (i = 0; i < jumlah; i++) {
					printf("%d. ID: %d, ", i+1, psn[i].id);
					cout << "Nama: " << psn[i].nama;
					cout << ", Kamar " << kmr[i].jkamar << " - " << kmr[i].nkamar;
					cout << ", Penyakit: " << psn[i].jpenyakit;
					cout << ", Tanggal Masuk: " << kmr[i].tgl.tanggal << " " << printBulan(kmr[i].tgl.bulan) << " " << kmr[i].tgl.tahun << endl << endl;
				}
				
				system("pause");
				
				break;
			case 5 : //keluar
				printf("+------------------------------+-----------------------------+\n");
				printf("+----------------------+ Terima kasih +----------------------+\n");
				printf("+------------------------------+-----------------------------+\n");
				system("pause");
				loop = 1;
				break;
			default:
				printf("Mohon masukkan sesuai menu\n");
				system("pause");
				break;
		}
	}	
	
	return 0;
	
}
