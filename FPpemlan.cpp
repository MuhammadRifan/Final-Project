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
		- PENGURUTAN DATA BERDASARKAN KRITERIA DATANYA (ID PASIEN, NMA, JENIS PENYAKIT, JENSI KAMAR, NOMOR KMAR, TANGGAL MASUK)	*/
		
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct pasien{
	char nama[100];
	int id;
	char jpenyakit[100];
}; pasien psn[100];

struct tanggal{
	char hari[100];
	int tanggal;
	char bulan[100];
	int tahun;
};

struct kamar{
	char jkamar[100];
	int nkamar;
	tanggal tgl;
}; kamar kmr[100];

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
		printf("+-----  4. Tampilan Data Pasien Secara Urut             -----+\n");
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
				
				printf("Masukkan Jenis Penyakit : ");
				gets(psn[jumlah].jpenyakit);
				
				printf("\nList kamar Pasien\n");
				printf("1. I\n2. II\n3. III\n4. VIP");
				printf("\nMasukkan Jenis Kamar untuk pasien : ");
				scanf("%d",&pilih);
				fflush(stdin);
				
				if (pilih == 1) strcpy(kmr[jumlah].jkamar, "I");
				else if (pilih == 2) strcpy(kmr[jumlah].jkamar, "II");
				else if (pilih == 3) strcpy(kmr[jumlah].jkamar, "III");
				else if (pilih == 4) strcpy(kmr[jumlah].jkamar, "VIP");
				
				printf("\nMasukkan Nomor Kamar : ");
				scanf("%d",&kmr[jumlah].nkamar);
				fflush(stdin);
				
				printf("\nMasukkan Hari Masuk : ");
				gets(kmr[jumlah].tgl.hari);
				fflush(stdin);
				
				printf("\nMasukkan Tanggal Masuk : ");
				scanf("%d",&kmr[jumlah].tgl.tanggal);
				fflush(stdin);
				
				printf("\nList Bulan\n");
				printf("1.  Januari\n2.  Februari\n3.  Maret\n4.  April\n5.  Mei\n6.  Juni\n7.  Juli\n8.  Agustus\n9.  September\n10. Oktober\n11. November\n12. Desember");
				printf("\nMasukkan Bulan Lahir : ");
				scanf("%d",&pilih);
				fflush(stdin);
				
				if (pilih == 1) strcpy(kmr[jumlah].tgl.bulan, "Januari");
				else if (pilih == 2) strcpy(kmr[jumlah].tgl.bulan, "Februari");
				else if (pilih == 3) strcpy(kmr[jumlah].tgl.bulan, "Maret");
				else if (pilih == 4) strcpy(kmr[jumlah].tgl.bulan, "April");
				else if (pilih == 5) strcpy(kmr[jumlah].tgl.bulan, "Mei");
				else if (pilih == 6) strcpy(kmr[jumlah].tgl.bulan, "Juni");
				else if (pilih == 7) strcpy(kmr[jumlah].tgl.bulan, "Juli");
				else if (pilih == 8) strcpy(kmr[jumlah].tgl.bulan, "Agustus");
				else if (pilih == 9) strcpy(kmr[jumlah].tgl.bulan, "September");
				else if (pilih == 10) strcpy(kmr[jumlah].tgl.bulan, "Oktober");
				else if (pilih == 11) strcpy(kmr[jumlah].tgl.bulan, "November");
				else if (pilih == 12) strcpy(kmr[jumlah].tgl.bulan, "Desember");
				
				psn[jumlah].id = jumlah+1;
				
				printf("\nMasukkan Tahun Masuk : ");
				scanf("%d",&kmr[jumlah].tgl.tahun);
				fflush(stdin);
				system("cls");
				printf("\n\nData Pasien \n");
				printf("\nNama\t\t\t: %s",psn[jumlah].nama);
				printf("\nID\t\t\t: %d",psn[jumlah].id);
				printf("\nJenis Penyakit\t\t: %s",psn[jumlah].jpenyakit);
				printf("\nJenis Kamar\t\t: %s",kmr[jumlah].jkamar);
				printf("\nNomor Kamar\t\t: %d",kmr[jumlah].nkamar);
				printf("\nHari dan Tanggal Masuk\t: %s, %d %s %d",kmr[jumlah].tgl.hari,kmr[jumlah].tgl.tanggal,kmr[jumlah].tgl.bulan,kmr[jumlah].tgl.tahun);
				getch();
				
				jumlah++;
				
				break;
			case 2 : //ubah data
				break;
			case 3 : //binary search
				break;
			case 4 : //
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
