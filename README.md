# Latar Belakang
&emsp;&emsp;Final project yang kelompok kami kerjakan berjudul “**Aplikasi Pendataan Rumah Sakit**” merupakan tugas akhir dari mata kuliah “**Pemrograman Lanjut**”. Pengerjaan final project ini menggunakan bahasa C. Pada program kami terdapat 5 menu yang di dalamnya terdapat fungsi untuk menambah data, mengubah data, mencari data, sorting data dan keluar.

&emsp;&emsp;Metode yang kami gunakan untuk mencari datanya adalah binary search dan untuk sortingnya adalah shell sort. Dan untuk pengerjaan program ini kami menggunakan github sebagai perantara untuk update pengerjaan program antar anggota kelompok dikarenakan dalam penggunaannya yang mudah.

# Rumusan Masalah
Permasalahan yang akan diselesaikan dari final project ini adalah :
1. Bagaimana implementasi algoritma binary search pada aplikasi pendataan rumah sakit?
2. Bagaimana implementasi algoritma shell sort pada aplikasi pendataan rumah sakit?

# Tujuan
Tujuan yang akan dicapai dari final project ini adalah :	
1.	Mengetahui cara implementasi dan cara kerja algoritma binary search pada studi kasus aplikasi pendataan rumah sakit.
2. Mengetahui cara implementasi dan cara kerja algoritma shell sort pada	studi kasus aplikasi pendataan rumah sakit.

# Manfaat
Manfaat dari final project ini adalah :
1. Program dapat digunakan sesuai kebutuhan pengguna berdasarkan fitur yang telah tersedia.
2. Bagi mahasiswa, final project ini dapat mengasah daya logika serta sebagai sarana penerapan dari teori yang telah didapat untuk diimplementasikan langsung berupa praktek.

# Luaran
Luaran yang diharapkan dari final project ini adalah :
1. Terbuatnya Aplikasi Pendataan Rumah Sakit dalam bentuk file yang berekstensi (.c).
2. Program Aplikasi dapat berfungsi dengan baik sesuai harapan.
3. Menyelesaikan tugas akhir dari mata kuliah pemrograman lanjut dengan baik.

# Binary Search
&emsp;&emsp;Pencarian bagi dua atau pencarian biner, hanya dapat dilakukan pada data yang sudah terurut. Bila data belum terurut dan akan dilakukan pencarian menggunakan metode ini maka terlebih dahulu harus diurutkan atau disorting. Untuk data yang besar metode ini lebih efektif.

&emsp;&emsp;Pencarian dilakukan dengan membandingkan Kunci dengan nilai array pada indeks ke Midle(tengah) dengan rumus (LEFT + RIGHT) / 2. Apabila nilai kunci lebih besar dari nilai array indeks ke-middle, maka pencarian dilakukan pada array sebelah KANAN dengan mengubah nilai indeks Left = Midle + 1. Apabila nilai kunci lebih kecil dari nilai array indeks ke-middle, maka pencarian dilakukan pada array sebelah KIRI dengan mengubah nilai indeks Right = Midle – 1.

# Shell Sort
&emsp;&emsp;Shellsort adalah generalisasi dari insertion sort yang memungkinkan penukaran item dengan jarak yang jauh. Idenya adalah untuk mengatur daftar elemen mulai dari mana saja, mengingat setiap elemen ke-h memberikan daftar diurutkan. Daftar seperti itu dikatakan h-disortir. Secara ekuivalen, ini dapat dianggap sebagai daftar yang disatukan, masing-masing diurutkan secara terpisah. 

&emsp;&emsp;Dimulai dengan nilai besar h, penataan ulang ini memungkinkan elemen untuk bergerak jarak jauh dalam daftar asli, mengurangi gangguan dari data yang berjumlah besar dengan cepat, dan meninggalkan lebih sedikit pekerjaan untuk langkah-langkah h-sort yang lebih kecil untuk dilakukan. Daftar tersebut kemudian diurutkan untuk beberapa bilangan bulat yang lebih kecil, maka daftar itu tetap diurutkan. Mengikuti ide ini untuk urutan penurunan nilai h yang berakhir dengan 1 dijamin akan meninggalkan daftar yang diurutkan di akhir.

# Deskripsi Aplikasi
&emsp;&emsp;Aplikasi Pendataan Rumah Sakit adalah aplikasi yang dibuat untuk memudahkan dalam pendataan pasien yang akan di rawat di rumah sakit yang memuat beberapa data yaitu ID, nama, jenis penyakit, jenis kamar, nomor kamar dan tanggal masuk. Pada aplikasi ini terdapat 5 menu di dalamnya yaitu :

1.	Tambah Data
<br><p>&emsp;&emsp;Pada menu pertama terdapat tambah data untuk pasien baru yang berisi inputan data yang terdiri dari input nama, jenis penyakit, jenis kamar, nomor kamar dan tanggal masuk mulai dari tanggal, bulan, tahun. Untuk id pasien kami gunakan default tergantung pada jumlah pasien itu, jika pasien tersebut adalah yang pertama maka id nya kan 1 dan pasien selanjutnya akan menyusul dengan urut sesuai jumlah pasiennya. Setelah semua selesai di input maka akan tampil data yang anda telah isi.</p>

2.	Ubah Data
<br><p>&emsp;&emsp;Pada menu kedua terdapat ubah data, jika anda pilih maka akan muncul inputan untuk mencari id yang akan anda ubah, id akan diterima secara default oleh pasien saat tambah data maka hanya id saja yang tidak dapat berubah. Jika id yang di cari ada maka akan muncul inputan seperti menu pertama, setelah menginputkan perubahan maka data pasien sesuai id yang anda cari akan berubah sesuai inputan, jika id yang and cari tidak ada maka akan tampil data tidak ditemukan.</p>

3.	Cari Data
<br><p>&emsp;&emsp;Pada menu ketiga terdapat cari data, pada menu ini terdapat 3 sub yaitu cari sesuai nama pasien, id pasien dan nomor kamar. Jika memilih salah satu dari 3 menu tersebut dan menginputkan nama, id atau nomor kamar yang tidak ada maka akan tampil data tidak ditemukan.</p>

4.	Sorting Data
<br><p>&emsp;&emsp;Pada menu keempat terdapat sorting data, dalam sorting data terdapat 6 menu sorting yaitu sorting sesuai id, nama,jenis penyakit, jenis kamar, nomor kamar dan tanggal masuk. Setelah di sorting maka akan tampil data pasien sesuai urutan yang anda pilih.</p>

5.	Keluar
<br><p>Pada menu kelima digunakan untuk mengakhiri program aplikasi pendataan rumah sakit.</p>
