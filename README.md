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
      char namefile3[256];
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

- Kita juga perlu mengganti permission menjadi 777

      chmod(folderawal, S_IRWXU | S_IRWXO | S_IRWXO );

- Setelah itu kita membuat sebuah variabel integer yang dibuat untuk menampung jika perbandingan antara nama dari password dan group itu sama dengan isi dari variabel cari

      int if1 = (strcmp(pwd->pw_name, cari));
      int if2 = (strcmp(group->gr_name, cari));

- Baru deh, kita membuat suatu if dengan syarat dimana if itu bernilai salah, maka kita harus menghpus filenya

      if(if1==0 && if2==0)
      { remove(folderawal); }
      
- Dan yang terakhir adalah menyeting kodingan agar selalu menghapus file setiap 3 detik dengan
          
      sleep(3);

# Nomor 3
Diberikan file campur2.zip. Di dalam file tersebut terdapat folder “campur2”. 
Buatlah program C yang dapat :

i)  mengekstrak file zip tersebut.

ii) menyimpan daftar file dari folder “campur2” yang memiliki ekstensi .txt ke dalam file daftar.txt. 

Catatan:  
- Gunakan fork dan exec.
- Gunakan minimal 3 proses yang diakhiri dengan exec.
- Gunakan pipe
- Pastikan file daftar.txt dapat diakses dari text editor

Jawab :

 - Untuk mengerjakan soal ini kami membuat beberapa variabel dengan keterangan :
	        
        pid_t child_1;		// membuat child 1 untuk mengunzip file campur2.zip
	      pid_t child_2;		// membuat file dengan nama daftar.txt
	      pid_t child_3;		// untuk ngesort dan menggabungkan file file yang berekstensi .txt
	      int ada; 		// untuk
	      int fd[2]; 		// array untuk menyimpan hasil output sementara agar bisa di proses ke tahap selanjutnya
	      char gus [1000];	// sebagai tempat menyimpan file .txt yang sudah di list

 - Lalu kita buat 3 child dalam if dan else dengan kondisi :
	child_1 untuk mengunzip file campur2.zip
	child_2 untuk membuat file dengan nama daftar.txt
	child_3 untuk mengelist file yang berformat.txt

 - Lalu kita tambahkan 
 
        while(wait(&ada)>0); 
 
   agar ketiga child ini tidak berjalan berbarengan
 - Lalu kita pakai char gus untuk menyimpan file.txt yang baru saja di proses pada ketiga child tersebut.
 - Kita membuka directori (fdopen) dan membuat daftar.txt pada direktori ini
  
        close(fd[1]);
        FILE* temp= fdopen(fd[0], "r"); 	
        FILE *daftar = fopen("daftar.txt", "w");
 
 - Lalu dengan fungsi while kita mengsortir semua data yang memiliki format .txt untuk masuk dalam daftar.txt berbentuk nama stringnya saja.
 
       while (fgets(gus, sizeof(gus), temp) != NULL) { //buat ngambil datanya di dalem gus
	      	if (strstr(&gus[strlen(gus)-5], ".txt") != NULL) //un
		      fprintf(daftar, "%s", gus);
		   } 


# Nomor 4
Dalam direktori /home/[user]/Documents/makanan terdapat file makan_enak.txt yang berisikan daftar makanan terkenal di Surabaya. Elen sedang melakukan diet dan seringkali tergiur untuk membaca isi makan_enak.txt karena ngidam makanan enak. Sebagai teman yang baik, Anda membantu Elen dengan membuat program C yang berjalan setiap 5 detik untuk memeriksa apakah file makan_enak.txt pernah dibuka setidaknya 30 detik yang lalu (rentang 0 - 30 detik).Jika file itu pernah dibuka, program Anda akan membuat 1 file makan_sehat#.txt di direktori
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
Kerjakan poin a dan b di bawah:

a. Buatlah program c untuk mencatat log setiap menit dari file log pada syslog ke /home/[user]/log/[dd:MM:yyyy-hh:mm]/log#.log
Ket:
- Per 30 menit membuat folder /[dd:MM:yyyy-hh:mm]
- Per menit memasukkan log#.log ke dalam folder tersebut
‘#’ : increment per menit. Mulai dari 1

b. Buatlah program c untuk menghentikan program di atas.

NB: Dilarang menggunakan crontab dan tidak memakai argumen ketika menjalankan program.

Jawab :

a. 

- Setelah membuat struktur daemon, kita membuat sebuah variabel integer dan char diluar while pada daemon yang berguna sebagai iterasi dan variabel passing

      int iterasi = 30;
      char univ[256];
      char univ2[256];
      
- Didalam while daemon saya membuat variabel dengan tipe data time_t untuk mendapatkan waktu sekarang, variabel char untuk menyimpan path dimana folder dan file tersebut akan disave, variabel char untuk savean waktu, dan sebuah struct tm dimana dia akan mengambil waktu secara detil dari time sekarang tadi

      time_t ddd = time(NULL);
      char folderawal[256]="/home/thalutn5/modul2/soal5/log/";
      char time[30];
      struct tm waktu = *localtime(&ddd);

- Lalu kita membuat if dengan syarat jika variabel itearasi di modulus 30 maka ia akan membuat folder

      if(iterasi % 30 == 0)
      
- Didalam if tadi kita akan membuat folder, dengan menggunakan sprintf dari format "%02d:%02d:%04d-%02d:%02d" lalu kita masukkan  kedalam variabel time 

      sprintf(time, "%02d:%02d:%04d-%02d:%02d",waktu.tm_mday,waktu.tm_mon+1,waktu.tm_year+1900,waktu.tm_hour,waktu.tm_min);
		
- Lalu setelah kita mendapatkan nama foldernya, kita gabungkan nama folder tersebut dengan variabel folderawal dimana isinya adalah path folder itu akan berada

      strcat(folderawal, time);
      
- Setelah itu kita baru membuat fungsi mkdir dimana ia akan membuat sebuah folder baru

      mkdir(folderawal, 0777);
      
- Baru lah isi dari copy isi dari variabel folderawal ke variabel univ agar bisa dipassing menuju fork selanjutnya

      strcpy(univ, folderawal);
     
- Diluar if tadi kita membuat variabel char dengan nama log yang berguna untuk menyimpan nama file log#.log 

      char log[30];
      
- Lalu copy isi dari variabel univ ke variabel univ2 agar bisa dipassing menuju fork selanjutnya
	
      strcpy(univ2, univ);
      
- Kita menggunakan sprintf untuk memasukkan nama file tersebut dengan iterasi yang berasal dari variabel iterasi kedalam variabel log tadi	

      sprintf(log, "/log%d.log",(iterasi%30)+1);
	
- Kita gabungkan variabel loga tadi dengan variabel univ2 yang isinya sama dengan variabel folderawal

      strcat(univ2, log);
     
- Barulah kita melakukan fork
	
      forkan = fork();
     
- Didalam fork kita akan membuat file dengan melakukan mengopy isi dari /var/sys/log kedalam variabel univ2 tadi

      char *cp[4] = {"cp", "/var/log/syslog", univ2, NULL};
      execv("/bin/cp", cp);
      
 - Diluar fork tadi barulah kita menaikkan iterasi dan mengatur sleepnya selama 1 menit
 
       iterasi++;
       sleep(60);
b. 

- Setelah dapat menjalankan kodingan a, maka di soal b ini kita diminta untuk mengakhiri program a tadi
- Didalam fungsi utama kita pertama membuat variabel char dengan isi argumen killall dan nama proses yang ingin kita matikan, lalu kita mengeksekusi nama variabel tersebut

      char nama[] = {"killall", "soal5", NULL};
      execv("/usr/bin/killall", nama);
