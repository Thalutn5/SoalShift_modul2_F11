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

# Nomor 2
# Nomor 3
# Nomor 4
# Nomor 5
