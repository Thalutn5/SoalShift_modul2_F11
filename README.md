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
Pada suatu hari Kusuma dicampakkan oleh Elen karena Elen dimenangkan oleh orang lain. Semua kenangan tentang Elen berada pada file bernama “elen.ku” pada direktori “hatiku”. 
Karena sedih berkepanjangan, tugas kalian sebagai teman Kusuma adalah membantunya untuk menghapus semua kenangan tentang Elen dengan membuat program C yang bisa mendeteksi owner 
dan group dan menghapus file “elen.ku” setiap 3 detik dengan syarat ketika owner dan grupnya menjadi “www-data”. Ternyata kamu memiliki kendala karena permission pada file “elen.ku”.
Jadi, ubahlah permissionnya menjadi 777. Setelah kenangan tentang Elen terhapus, maka Kusuma bisa move on. Catatan: Tidak boleh menggunakan crontab

Jawab :

- Pertama-tama kita membuat sebuah folder yang bernama "gambar" dan berisikan sebuah file yang bernama "elen.ku" 
- setelah kita membuat struktur daemon lalu  kita membuat struct didalam whilenya dengan jenis stat, passwd dan group
    
      struct stat info;
      
      struct passwd *pwd;
      
      struct group *group;
      
- Kita juga perlu membuat sebuah variabel dengan tipe data array of char dengan nama folderawal

      char folderawal[256];

- Serta kita juga memasukkan sebuah alamat direktori pada variabel tersebut

      strcpy(folderawal, "/home/thalutn5/modul2/soal2/hatiku/elen.ku");

- Kita juga perlu membuat sebuah variabel yang berisi "www-data"

       char cari[256] = "www-data";

- Lalu kita mengambil info yang ada pada file "elen.ku"

       stat(folderawal, &info);

- Lalu kita mengisi variabel pwd dan group dengan id user dan id grup dari owner lalu disimpan di tempat yang ditunjuk oleh pwd dan grup

      pwd = getpwuid(info.st_uid);
      
      group = getgrgid(info.st_gid);

- Setelah itu kita membuat sebuah variabel integer yang dibuat untuk menampung jika perbandingan antara nama dari password dan group itu sama dengan isi dari variabel cari

      int if1 = (strcmp(pwd->pw_name, cari));

      int if2 = (strcmp(group->gr_name, cari));

- Baru deh, kita membuat suatu if dengan syarat dimana if itu bernilai salah, maka kita harus menghpus filenya

      if(if1==0 && if2==0)
      { remove(folderawal); }
      
- Dan yang terakhir adalah menyeting kodingan agar selalu menghapus file setiap 3 detik dengan
          
      sleep(3);

# Nomor 3
# Nomor 4
4. Dalam direktori /home/[user]/Documents/makanan terdapat file makan_enak.txt yang berisikan daftar makanan terkenal di Surabaya. Elen sedang melakukan diet dan seringkali tergiur untuk membaca isi makan_enak.txt karena ngidam makanan enak. Sebagai teman yang baik, Anda membantu Elen dengan membuat program C yang berjalan setiap 5 detik untuk memeriksa apakah file makan_enak.txt pernah dibuka setidaknya 30 detik yang lalu (rentang 0 - 30 detik).Jika file itu pernah dibuka, program Anda akan membuat 1 file makan_sehat#.txt di direktori
 /home/[user]/Documents/makanan dengan '#' berisi bilangan bulat dari 1 sampai tak hingga untuk mengingatkan Elen agar berdiet.

Jawab :

- Setelah membuat struktur daemon, kita membuat sebuah variabel integer diluar while pada daemon

      int iterasi=1;

- Lalu isi dari whilenya adalah kita membuat sebuah 3 variabel yang bertipe array of char

      char fileawal[256];

      char filebaru[256];

      char ganti[3];

- Kita juga perlu membuat struct stat

      struct stat info;

- Lalu kita isikan 2 variabel tersebut dengan diretori sebuah file

      strcpy(fileawal, "home/thalutn5/Documents/makanan/makan_enak.txt");

      strcpy(filebaru, "home/thalutn5/Documents/makanan/makan_sehat");

- Kemudian kita mengkopikan isi nilai dari variabel iterasi kepada variabel ganti yang bertipe char

      sprintf(ganti, "%d", iterasi);

- Setelah itu kita mengambil informasi pada isi dari variabel fileawal

      stat(fileawal, &info);

- Lalu kita menggabungkan isi dari variabel filebaru dengan isi variabel ganti yang berupa angka iterasi

      strcat(filebaru, ganti);

- Kita juga perlu menggabungkan isi dari variabel filebaru tadi dengan sting ".txt"

      strcat(filebaru, ".txt");

- Baru deh kita membuat sebuah if dengan syarat dimana waktu pada saat programnya diajalankan dan waktu file diaksesnya kurang dar 30 detik, maka ia akan membuat sebuah file baru dengan iterasi tertentu
  
      if(difftime(time(NULL), info.st_atime)<=30)
      
      {
	
            FILE *newfile = fopen(filebaru, "w");
	
            fclose(newfile);
	
            iterasi = iterasi + 1;

      }

- Jangan lupa untuk menyeting kodingan agar selalu berjalan setiap 5 detik dengan

      sleep(5);


# Nomor 5
