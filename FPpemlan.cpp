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

struct pasien{
	char nama[50];
	int id;
	char jpenyakit[50];
}; pasien psn[100];

struct tanggal{
	int tanggal;
	char bulan[25];
	int tahun;
};

struct kamar{
	char jkamar[10];
	int nkamar;
	tanggal tgl;
}; kamar kmr[100];

void printBulan(char bln[15]){
	if (strcmp(bln, "01") == 0) printf("Januari");
	else if (strcmp(bln, "02") == 0) printf("Februari");
	else if (strcmp(bln, "03") == 0) printf("Maret");
	else if (strcmp(bln, "04") == 0) printf("April");
	else if (strcmp(bln, "05") == 0) printf("Mei");
	else if (strcmp(bln, "06") == 0) printf("Juni");
	else if (strcmp(bln, "07") == 0) printf("Juli");
	else if (strcmp(bln, "08") == 0) printf("Agustus");
	else if (strcmp(bln, "09") == 0) printf("September");
	else if (strcmp(bln, "10") == 0) printf("Oktober");
	else if (strcmp(bln, "11") == 0) printf("November");
	else if (strcmp(bln, "12") == 0) printf("Desember");
}

void sorting(int arr1[], char arr2[][100], int jumlah, int pos) {	
	int gap, right, jump;
	
	for (gap = jumlah/2; gap > 0; gap /= 2) {
		for (right = gap; right < jumlah; right ++) {
			int tempINT[4] = {psn[right].id, kmr[right].nkamar, kmr[right].tgl.tanggal, kmr[right].tgl.tahun};
			char tempString[4][50];
			strcpy(tempString[0], psn[right].nama);
			strcpy(tempString[1], psn[right].jpenyakit);
			strcpy(tempString[2], kmr[right].jkamar);
			strcpy(tempString[3], kmr[right].tgl.bulan);
			
			if (pos == 5) {
				char tempDate[50];
				sprintf(tempDate, "%d", tempINT[3]);
				strncat(tempDate, tempString[3], 2);
				char tgl[50];
				
				if (tempINT[2] > 9) {
					sprintf(tgl, "%d", tempINT[2]);
					strncat(tempDate, tgl, 2);
				} else {
					strncat(tempDate, "0", 1);
					sprintf(tgl, "%d", tempINT[2]);
					strncat(tempDate, tgl, 1);
				}
				
				for (jump = right; jump >= gap && strcmp(arr2[jump-gap], tempDate) > 0; jump -= gap) {
					psn[jump].id = psn[jump-gap].id;
					strcpy(psn[jump].nama, psn[jump-gap].nama);
					strcpy(psn[jump].jpenyakit, psn[jump-gap].jpenyakit);
					kmr[jump].nkamar = kmr[jump-gap].nkamar;
					strcpy(kmr[jump].jkamar, kmr[jump-gap].jkamar);
					kmr[jump].tgl.tanggal = kmr[jump-gap].tgl.tanggal;
					strcpy(kmr[jump].tgl.bulan, kmr[jump-gap].tgl.bulan);
					kmr[jump].tgl.tahun = kmr[jump-gap].tgl.tahun;
				}
			} else if (strcmp(arr2[0], "kosong") == 0) {
				for (jump = right; jump >= gap && arr1[jump-gap] > tempINT[pos]; jump -= gap) {
					psn[jump].id = psn[jump-gap].id;
					strcpy(psn[jump].nama, psn[jump-gap].nama);
					strcpy(psn[jump].jpenyakit, psn[jump-gap].jpenyakit);
					kmr[jump].nkamar = kmr[jump-gap].nkamar;
					strcpy(kmr[jump].jkamar, kmr[jump-gap].jkamar);
					kmr[jump].tgl.tanggal = kmr[jump-gap].tgl.tanggal;
					strcpy(kmr[jump].tgl.bulan, kmr[jump-gap].tgl.bulan);
					kmr[jump].tgl.tahun = kmr[jump-gap].tgl.tahun;
				}
			} else {
				for (jump = right; jump >= gap && strcmp(arr2[jump-gap], tempString[pos]) > 0; jump -= gap) {
					psn[jump].id = psn[jump-gap].id;
					strcpy(psn[jump].nama, psn[jump-gap].nama);
					strcpy(psn[jump].jpenyakit, psn[jump-gap].jpenyakit);
					kmr[jump].nkamar = kmr[jump-gap].nkamar;
					strcpy(kmr[jump].jkamar, kmr[jump-gap].jkamar);
					kmr[jump].tgl.tanggal = kmr[jump-gap].tgl.tanggal;
					strcpy(kmr[jump].tgl.bulan, kmr[jump-gap].tgl.bulan);
					kmr[jump].tgl.tahun = kmr[jump-gap].tgl.tahun;
				}
			} 
			
			psn[jump].id = tempINT[0];
			strcpy(psn[jump].nama, tempString[0]);
			strcpy(psn[jump].jpenyakit, tempString[1]);
			kmr[jump].nkamar = tempINT[1];
			strcpy(kmr[jump].jkamar, tempString[2]);
			kmr[jump].tgl.tanggal = tempINT[2];
			strcpy(kmr[jump].tgl.bulan, tempString[3]);
			kmr[jump].tgl.tahun = tempINT[3];
		}
	}
}

void binary_search_Nama(int jumlah){
	int i=1, hasil;
	char caridata[50];
	int awal=0, tengah, akhir=jumlah;
	
	fflush(stdin);
	printf("\nMasukkan nama pasien yang ingin di cari : "); 
    gets(caridata);
    
    while(i != 0){
    	tengah = (awal+akhir)/2;
    	hasil=strcmp(psn[tengah].nama, caridata);
    	
	    if(hasil == 0){
			printf("DATA DITEMUKAN");
			printf("\n\nNama\t\t: %s\nKamar\t\t: %s - %d\nPenyakit\t: %s\nTanggal Masuk\t: %d ", psn[tengah].nama, kmr[tengah].jkamar, kmr[tengah].nkamar, psn[tengah].jpenyakit, kmr[tengah].tgl.tanggal);
			printBulan(kmr[tengah].tgl.bulan);
			printf(" %d\n\n",kmr[tengah].tgl.tahun);
	    	i = 0;
			break;
		}else if(awal >= akhir){
			printf("DATA TIDAK DITEMUKAN\n\n");
			break;
		}else if(hasil < 0){
    		awal = tengah+1;
		}else if(hasil > 0){
			akhir = tengah-1;
		}
	}
	
	system("pause");
	system("cls");
}

void binary_search_ID(int jumlah){
	int i=1, caridata, awal=0, tengah, akhir=jumlah;
	
	printf("\nMasukkan ID pasien yang ingin di cari : "); 
    scanf("%d", &caridata);
    
    while(i != 0){
    	tengah=(awal+akhir)/2;
    	
    	if(psn[tengah].id == caridata){
			printf("DATA DITEMUKAN");
			printf("\n\nNama\t\t: %s\nKamar\t\t: %s - %d\nPenyakit\t: %s\nTanggal Masuk\t: %d ", psn[tengah].nama, kmr[tengah].jkamar, kmr[tengah].nkamar, psn[tengah].jpenyakit, kmr[tengah].tgl.tanggal);
			printBulan(kmr[tengah].tgl.bulan);
			printf(" %d\n\n",kmr[tengah].tgl.tahun);
    		i = 0;
			break;
		}else if(awal >= akhir){
			printf("DATA TIDAK DITEMUKAN\n");
			break;
		}else if(caridata > psn[tengah].id){
    		awal=tengah+1;
		}else if(caridata < psn[tengah].id){
			akhir=tengah-1;
		}
	}
	
	system("pause");
	system("cls");
}

void binary_search_Nkamar(int jumlah){
	int i=1, caridata, awal=0, tengah, akhir=jumlah;
	
	printf("\nMasukkan nomor kamar yang ingin di cari : "); 
    scanf("%d",&caridata);
    
   	while(i != 0){
    	tengah=(awal+akhir)/2;
    	
   		if(kmr[tengah].nkamar == caridata){
			printf("DATA DITEMUKAN");
			printf("\n\nNama\t\t: %s\nKamar\t\t: %s - %d\nPenyakit\t: %s\nTanggal Masuk\t: %d ", psn[tengah].nama, kmr[tengah].jkamar, kmr[tengah].nkamar, psn[tengah].jpenyakit, kmr[tengah].tgl.tanggal);
			printBulan(kmr[tengah].tgl.bulan);
			printf(" %d\n\n",kmr[tengah].tgl.tahun);
			i = 0;
			break;
		}else if(awal >= akhir){
			printf("DATA TIDAK DITEMUKAN\n");
			break;
		}else if(caridata > kmr[tengah].nkamar){
    		awal=tengah+1;
		}else if(caridata < kmr[tengah].nkamar){
			akhir=tengah-1;
		}
	}
	
	system("pause");
	system("cls");
}

void ubahdata(int jumlah){
	int caridata, found = -1, i, pilih, arr1[jumlah], awal=0, akhir=jumlah;
	int tengah=(awal+akhir)/2;
	char arr2[][100] = {{"kosong"}};
	
	for (i = 0; i < jumlah; i++) {
		arr1[i] = psn[i].id;
	}
	
	sorting(arr1, arr2, jumlah, 0);
	
	for (i = 0; i < jumlah; i++) {
		printf("%d. ID: %d, ", i+1, psn[i].id);
		printf("Nama: %s, Kamar %s - %d, Penyakit: %s, Tanggal Masuk: %d ", psn[i].nama, kmr[i].jkamar, kmr[i].nkamar, psn[i].jpenyakit, kmr[i].tgl.tanggal);
		printBulan(kmr[i].tgl.bulan);
		printf(" %d\n\n",kmr[i].tgl.tahun);
	}
	
	printf("\nMasukkan ID pasien yang ingin di cari : "); 
    scanf("%d", &caridata);
    fflush(stdin);
    
    i = 1;
    
    while(i != 0){
    	tengah=(awal+akhir)/2;
    	if(psn[tengah].id == caridata){
    		i = 0;
    		found = tengah;
			printf("DATA DITEMUKAN\n\n");
			break;
		}if(awal >= akhir){
			printf("DATA TIDAK DITEMUKAN\n\n");
			break;
		}else if(caridata > psn[tengah].id){
    		awal=tengah+1;
		}else if(caridata < psn[tengah].id){
			akhir=tengah-1;
		}
	}
	
	if (found >= 0) {
		printf("Edit data: \n\n");
		
		printf("Masukkan Nama Pasien : ");
		gets(psn[found].nama);
		fflush(stdin);
		
		printf("\nMasukkan Jenis Penyakit : ");
		gets(psn[found].jpenyakit);
		fflush(stdin);
		
		printf("\nList kamar Pasien\n");
		printf("1. I\n2. II\n3. III\n4. VIP");
		printf("\nMasukkan Jenis Kamar untuk pasien : ");
		scanf("%d", &pilih);
		fflush(stdin);
				
		if (pilih == 1) strcpy(kmr[found].jkamar, "I");
		else if (pilih == 2) strcpy(kmr[found].jkamar, "II");
		else if (pilih == 3) strcpy(kmr[found].jkamar, "III");
		else if (pilih == 4) strcpy(kmr[found].jkamar, "VIP");
		
		printf("\nMasukkan Nomor Kamar : ");
		scanf("%d", &kmr[found].nkamar);
		fflush(stdin);
				
		printf("\nMasukkan Tanggal Masuk : ");
		scanf("%d", &kmr[found].tgl.tanggal);
		fflush(stdin);
				
		printf("\nList Bulan\n");
		printf("1.  Januari\n2.  Februari\n3.  Maret\n4.  April\n5.  Mei\n6.  Juni\n7.  Juli\n8.  Agustus\n9.  September\n10. Oktober\n11. November\n12. Desember");
		printf("\nMasukkan Bulan Masuk : ");
		scanf("%d", &pilih);
		fflush(stdin);
				
		if (pilih == 1) strcpy(kmr[found].tgl.bulan, "01");
		else if (pilih == 2) strcpy(kmr[found].tgl.bulan, "02");
		else if (pilih == 3) strcpy(kmr[found].tgl.bulan, "03");
		else if (pilih == 4) strcpy(kmr[found].tgl.bulan, "04");
		else if (pilih == 5) strcpy(kmr[found].tgl.bulan, "05");
		else if (pilih == 6) strcpy(kmr[found].tgl.bulan, "06");
		else if (pilih == 7) strcpy(kmr[found].tgl.bulan, "07");
		else if (pilih == 8) strcpy(kmr[found].tgl.bulan, "08");
		else if (pilih == 9) strcpy(kmr[found].tgl.bulan, "09");
		else if (pilih == 10) strcpy(kmr[found].tgl.bulan, "10");
		else if (pilih == 11) strcpy(kmr[found].tgl.bulan, "11");
		else if (pilih == 12) strcpy(kmr[found].tgl.bulan, "12");
				
		printf("\nMasukkan Tahun Masuk : ");
		scanf("%d", &kmr[found].tgl.tahun);
		fflush(stdin);
				
		system("cls");
		printf("Data Pasien: \n");
		
		printf("\nID\t\t: %d", psn[found].id);
		printf("\nNama\t\t: %s", psn[found].nama);
		printf("\nJenis Penyakit\t: %s", psn[found].jpenyakit);
		printf("\nJenis Kamar\t: %s", kmr[found].jkamar);
		printf("\nNomor Kamar\t: %d", kmr[found].nkamar);
		printf("\nTanggal Masuk\t: %d ", kmr[found].tgl.tanggal);
		printBulan(kmr[found].tgl.bulan);
		printf(" %d\n\n", kmr[found].tgl.tahun);
	}
	
	system("pause");
	system("cls");
}

int main() {
	int jumlah=0, pilih, menu, loop=0;
	
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
				gets(psn[jumlah].nama);
				fflush(stdin);
				
				printf("\nMasukkan Jenis Penyakit : ");
				gets(psn[jumlah].jpenyakit);
				fflush(stdin);
				
				printf("\nList kamar Pasien\n");
				printf("1. I\n2. II\n3. III\n4. VIP");
				printf("\nMasukkan Jenis Kamar untuk pasien : ");
				scanf("%d", &pilih);
				fflush(stdin);
				
				if (pilih == 1) strcpy(kmr[jumlah].jkamar, "I");
				else if (pilih == 2) strcpy(kmr[jumlah].jkamar, "II");
				else if (pilih == 3) strcpy(kmr[jumlah].jkamar, "III");
				else if (pilih == 4) strcpy(kmr[jumlah].jkamar, "VIP");
				
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
				
				if (pilih == 1) strcpy(kmr[jumlah].tgl.bulan, "01");
				else if (pilih == 2) strcpy(kmr[jumlah].tgl.bulan, "02");
				else if (pilih == 3) strcpy(kmr[jumlah].tgl.bulan, "03");
				else if (pilih == 4) strcpy(kmr[jumlah].tgl.bulan, "04");
				else if (pilih == 5) strcpy(kmr[jumlah].tgl.bulan, "05");
				else if (pilih == 6) strcpy(kmr[jumlah].tgl.bulan, "06");
				else if (pilih == 7) strcpy(kmr[jumlah].tgl.bulan, "07");
				else if (pilih == 8) strcpy(kmr[jumlah].tgl.bulan, "08");
				else if (pilih == 9) strcpy(kmr[jumlah].tgl.bulan, "09");
				else if (pilih == 10) strcpy(kmr[jumlah].tgl.bulan, "10");
				else if (pilih == 11) strcpy(kmr[jumlah].tgl.bulan, "11");
				else if (pilih == 12) strcpy(kmr[jumlah].tgl.bulan, "12");
				
				psn[jumlah].id = jumlah+1;
				
				printf("\nMasukkan Tahun Masuk : ");
				scanf("%d", &kmr[jumlah].tgl.tahun);
				fflush(stdin);
				
				system("cls");
				printf("Data Pasien Baru: \n");
				
				printf("\nID\t\t: %d", psn[jumlah].id);
				printf("\nNama\t\t: %s", psn[jumlah].nama);
				printf("\nJenis Penyakit\t: %s", psn[jumlah].jpenyakit);
				printf("\nJenis Kamar\t: %s", kmr[jumlah].jkamar);
				printf("\nNomor Kamar\t: %d", kmr[jumlah].nkamar);
				printf("\nTanggal Masuk\t: %d ", kmr[jumlah].tgl.tanggal);
				printBulan(kmr[jumlah].tgl.bulan);
				printf(" %d\n\n", kmr[jumlah].tgl.tahun);
				
				system("pause");
				jumlah++;
				break;
			case 2 : //ubah data
				ubahdata(jumlah);
				break;
			case 3 : //binary search
				printf("Pilih Menu Search: \n");
				printf("1. Cari Nama\n2. Cari ID\n3. Cari Nomor Kamar");
				printf("\nMasukkan pilihan : ");
				scanf("%d", &pilih);
				
				if (pilih == 1) {
					int i, arr1[jumlah]; char arr2[100][100];
					for (i = 0; i < jumlah; i++) {
						strcpy(arr2[i], psn[i].nama); 
					}
					
					sorting(arr1, arr2, jumlah, 0);
					
					binary_search_Nama(jumlah);
				}		
				else if (pilih == 2) {
					int i, arr1[jumlah]; char arr2[][100] = {{"kosong"}};
					for (i = 0; i < jumlah; i++) {
						arr1[i] = psn[i].id;
					}
					
					sorting(arr1, arr2, jumlah, 0);
					
					binary_search_ID(jumlah);
				}
				else if (pilih == 3) {
					int i, arr1[jumlah]; char arr2[][100] = {"kosong"};
					for (i = 0; i < jumlah; i++) {
						arr1[i] = kmr[i].nkamar;
					}
					
					sorting(arr1, arr2, jumlah, 1);
					
					binary_search_Nkamar(jumlah);
				}
				break;
			case 4 : // shell sort
				printf("Pengurutan berdasarkan: \n");
				printf("1. ID Pasien\n2. Nama\n3. Jenis Penyakit\n4. Jenis Kamar\n5. Nomor Kamar\n6. Tanggal Masuk");
				printf("\nMasukkan kriteria : ");
				scanf("%d", &pilih);
				
				int i;
				
				system("cls");
				
				if (pilih == 1) {
					printf("Data sesuai ID Pasien:\n\n");
					
					int arr1[jumlah]; char arr2[][100] = {{"kosong"}};
					for (i = 0; i < jumlah; i++) {
						arr1[i] = psn[i].id;
					}
					
					sorting(arr1, arr2, jumlah, 0);
				} else if (pilih == 2) {
					printf("Data sesuai nama:\n\n");
					
					int arr1[jumlah]; char arr2[100][100];
					for (i = 0; i < jumlah; i++) {
						strcpy(arr2[i], psn[i].nama); 
					}
					
					sorting(arr1, arr2, jumlah, 0);
				} else if (pilih == 3) {
					printf("Data sesuai jenis penyakit:\n\n");
					
					int arr1[jumlah]; char arr2[100][100];
					for (i = 0; i < jumlah; i++) {
						strcpy(arr2[i], psn[i].jpenyakit); 
					}
					
					sorting(arr1, arr2, jumlah, 1);
				} else if (pilih == 4) {
					printf("Data sesuai jenis kamar:\n\n");
					
					int arr1[jumlah]; char arr2[100][100];
					for (i = 0; i < jumlah; i++) {
						strcpy(arr2[i], kmr[i].jkamar); 
					}
					
					sorting(arr1, arr2, jumlah, 2);
				}else if (pilih == 5) {
					printf("Data sesuai nomor kamar:\n\n");
					
					int arr1[jumlah]; char arr2[][100] = {"kosong"};
					for (i = 0; i < jumlah; i++) {
						arr1[i] = kmr[i].nkamar;
					}
					
					sorting(arr1, arr2, jumlah, 1);
				} else if (pilih == 6) {
					printf("Data sesuai tanggal masuk:\n\n");
					
					int arr1[jumlah]; char arr2[100][100];
					for (i = 0; i < jumlah; i++) {
						char str[50];
						sprintf(str, "%d", kmr[i].tgl.tahun);
						strncat(str, kmr[i].tgl.bulan, 2);
						char tgl[50];
						
						if (kmr[i].tgl.tanggal > 9) {
							sprintf(tgl, "%d", kmr[i].tgl.tanggal);
							strncat(str, tgl, 2);
						} else {
							strncat(str, "0", 1);
							sprintf(tgl, "%d", kmr[i].tgl.tanggal);
							strncat(str, tgl, 1);
						}
						strcpy(arr2[i], str);
					}
					
					sorting(arr1, arr2 , jumlah, 5);
				}
				
				for (i = 0; i < jumlah; i++) {
					printf("%d. ID: %d, ", i+1, psn[i].id);
					printf("Nama: %s, Kamar %s - %d, Penyakit: %s, Tanggal Masuk: %d ", psn[i].nama, kmr[i].jkamar, kmr[i].nkamar, psn[i].jpenyakit, kmr[i].tgl.tanggal);
					printBulan(kmr[i].tgl.bulan);
					printf(" %d\n\n",kmr[i].tgl.tahun);
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
