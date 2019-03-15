# SoalShift_modul2_F11

# Nomor 1
Elen mempunyai pekerjaan pada studio sebagai fotografer. Suatu hari ada seorang klien yang bernama Kusuma yang meminta untuk mengubah nama file yang memiliki ekstensi .png menjadi “[namafile]_grey.png”. Karena jumlah file yang diberikan Kusuma tidak manusiawi, maka Elen meminta bantuan kalian untuk membuat suatu program C yang dapat mengubah nama secara otomatis
dan diletakkan pada direktori /home/[user]/modul2/gambar.
Catatan : Tidak boleh menggunakan crontab.

Jawab :

- Untuk mengerjakan soal ini kami membuat beberapa variabel didalam while daemon yang bertipe array of char sebanyak 6, 1 variabel char yang bertipe pointer, variabel DIR yang bertipe pointer, 
dan struct yang bertipe pointer yaitu :
  
      char namefile[256];
    
      char *namefile2;
    
      char namefile3[256
    
      char namefile4[256];
    
      char namefile5[256]="_grey.png";
    
      char folderawal[256];
    
      char folderakhir[256];
    
      DIR *d;
    
      struct dirent *dir;
- Kita juga mengisikan variabel pointer d tadi sebagai arah menuju dan membuka file awal itu berada
        
      d = opendir("/home/thalutn5/modul2/soal1/");

- Lalu kita menggunakan sebuah if dengan syarat d, dengan artian sampai file didalam folder soal1 itu sudah habis
- Didalam if tersebut ada looping dengan syarat dimana dia ngeread semua file yang ada didalam folder tersebut 

      while ((dir = readdir(d)) != NULL)

- Sementara didalam while itu kami mengisikan 2 buah array of char tersebut sebagai arah dari suatu folder awal dan folder hasil

      strcpy(folderawal, "/home/thalutn5/modul2/soal1/");

      strcpy(folderakhir, "/home/thalutn5/modul2/soal1/gambar/");
- Lalu kita juga mengkopy nama file kedalam sebuah variabel namefile

      strcpy(namefile, dir->d_name);
    
- Selain itu kami juga mengisikan namefile2 tadi dengan alamat dari titik yang ada pada sebuah nama file

      namefile2 = strrchr(namefile, '.'); 

- Lalu kita mengkopy nama file yang asli ke dalam sebuah variabel yang bernama namefile4

      strcpy(namefile4, namefile1);

- Setelah itu kami membuat if lagi dengan syarat jika namefile2 itu isinya sama dengan ".png", maka

      if(namefile2 && (strcmp(namefile2, ".png")==0))
 
- Lalu kita ganti nilai dari alamat namefile2 tadi dengan sebuah karakter null agar bisa menghapus "png"

      *namefile2 = '\0';
- Kita juga mengkopy nama dari isi variabel namefile yang sudah hilang ".png"nya kedalam sebuah variabel namefile3

      strcpy(namefile3, namefile);

- Sekarang kita mengkombinasikan isi dari variabel namefile 3 dan namefile5

      strcat(namefile3, namefile5);

- Lalu kita menggabungkan isi string dari variabel folderakhir dengan variabel namefile3

      strcat(folderakhir, namefile3);

- Kita juga perlu menggabungkan isi string dari variabel folderawal dengan variabel namefile4

      strcat(folderawal, namefile4);

- Dan kita juga perlu merename variabel folderawal dengan folderakhir

      rename(folderawal, folderakhir);

- Tidak lupa untuk menutup file yang kita baca dengan syntax

      closedir(d);

# Nomor 2
# Nomor 3
# Nomor 4
# Nomor 5
