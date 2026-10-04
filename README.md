# Janji
Saya Andina Dwi Listiana dengan NIM 2501065 mengerjakan TP 3 dalam mata kuliah Desain Pemrograman Berorientasi Objek untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin

# Desain Diagram Program
Diagram program yang mengggambarkan hubungan antar-class pada program disertakan di folder Desain Diagram

# Penjelasan Atribut dan Method
## Client
Class Client digunakan untuk menyimpan data client yang melakukan pemesanan artwork. 
Atribut:
1. Id : untuk menyimpan ID client
2. Name : untuk menyimpan nama client
3. Email : untuk menyimpan email client
4. Commission : untuk menyimpan pointer yang menunjuk ke Commission milik client
Method:
1. Client() : constructor untuk membuat object Client.
2. getId() : untuk mengambil ID client.
3. getName() : untuk mengambil nama client.
4. getEmail() : untuk mengambil email client.
5. setId() : untuk mengubah ID client.
6. setName() : untuk mengubah nama client.
7. setEmail() : untuk mengubah email client.
8. addCommission() : untuk menyimpan Commission ke dalam Client.
9. getCommission() : untuk mengambil Commission yang disimpan oleh Client.

## Commission
Class Commission digunakan untuk menyimpan data pesanan artwork dari client.
Atribut:
1. IdReq : untuk menyimpan ID request/pesanan.
2. Request : untuk menyimpan permintaan atau pesanan dari client.
3. Deadline : untuk menyimpan batas waktu pengerjaan pesanan. artwork : untuk
4. menyimpan pointer yang menunjuk ke Artwork milik commission.
Method:
1. Commission() : constructor untuk membuat object Commission.
2. getIdreq() : untuk mengambil ID request.
3. getRequest() : untuk mengambil data request.
4. getDeadline() : untuk mengambil deadline.
5. setIdReq() : untuk mengubah ID request.
6. setRequest() : untuk mengubah data request.
7. setDeadline() : untuk mengubah deadline.
8. addArtwork() : untuk menyimpan Artwork ke dalam Commission.
9. getArtwork() : untuk mengambil Artwork yang disimpan oleh Commission.

## Artwork
Class Artwork merupakan parent class yang menyimpan data umum yang dimiliki oleh artwork.
Atribut:
1. ArtStyle : untuk menyimpan gaya atau style artwork.
2. CreationDate : untuk menyimpan tanggal pembuatan artwork.
3. Price : untuk menyimpan harga artwork.
Method:
1. Artwork() : constructor untuk membuat object Artwork.
2. getArtStyle() : untuk mengambil style artwork.
3. getCreationDate() : untuk mengambil tanggal pembuatan artwork.
4. getPrice() : untuk mengambil harga artwork.
5. setArtStyle() : untuk mengubah style artwork.
6. setCreationDate() : untuk mengubah tanggal pembuatan artwork.
7. setPrice() : untuk mengubah harga artwork.

## DigitalArtwork
Class DigitalArtwork merupakan turunan dari Artwork yang digunakan untuk menyimpan data khusus artwork digital.
Atribut:
1. Resolution : untuk menyimpan resolusi artwork digital.
2. FileFormat : untuk menyimpan format file artwork digital.
Note : Selain atribut tersebut, DigitalArtwork juga mewarisi atribut ArtStyle, CreationDate, dan Price dari class Artwork.
Method:
1. DigitalArtwork() : constructor untuk membuat object DigitalArtwork.
2. getResolution() : untuk mengambil resolusi artwork.
3. getFileFormat() : untuk mengambil format file artwork.
4. setResolution() : untuk mengubah resolusi artwork.
5. setFileFormat() : untuk mengubah format file artwork.

## TraditionalArtwork
Class TraditionalArtwork merupakan turunan dari Artwork yang digunakan untuk menyimpan data khusus artwork tradisional.
Atribut:
1. Medium untuk menyimpan media atau bahan yang digunakan untuk membuat artwork, seperti canvas, paper, wood, dan sebagainya.
2. Size : untuk menyimpan ukuran artwork.
Note : Selain atribut tersebut, TraditionalArtwork juga mewarisi atribut ArtStyle, CreationDate, dan Price dari class Artwork.
Method:
1. TraditionalArtwork() : constructor untuk membuat object TraditionalArtwork.
2. getMedium() : untuk mengambil media yang digunakan.
3. getSize() : untuk mengambil ukuran artwork.
4. setMedium() : untuk mengubah media artwork.
5. setSize() : untuk mengubah ukuran artwork.

# Penjelasan Desain Program
Program Art Studio dirancang berdasarkan alur pemesanan artwork. Proses dimulai ketika seorang Client ingin melakukan pemesanan artwork. Client memberikan data pribadinya, kemudian membuat sebuah Commission yang berisi data mengenai pesanan artwork, seperti request dan deadline.

Hubungan antara Client dan Commission menggunakan composition karena dalam konteks program ini, sebuah Commission bergantung pada adanya Client yang melakukan pemesanan. Jika tidak ada Client yang melakukan pemesanan, maka Commission tersebut tidak akan dibuat. Oleh karena itu, Commission dianggap sebagai bagian dari Client dalam proses pemesanan.

Selanjutnya, hubungan antara Commission dan Artwork juga menggunakan composition. Hal ini karena Artwork pada program ini dibuat sebagai bagian dari pesanan yang terdapat pada Commission. Jika tidak ada Commission atau pesanan yang dibuat, maka data Artwork yang dipesan juga tidak akan ada. Dengan demikian, Artwork menjadi bagian dari Commission.

Setelah itu, Artwork memiliki dua jenis turunan, yaitu DigitalArtwork dan TraditionalArtwork. Keduanya menggunakan inheritance karena DigitalArtwork dan TraditionalArtwork merupakan jenis dari Artwork. Atribut yang bersifat umum seperti ArtStyle, CreationDate, dan Price ditempatkan pada parent class Artwork, sedangkan atribut khusus masing-masing jenis artwork ditempatkan pada subclass.

DigitalArtwork memiliki FileFormat dan Resolution, sedangkan TraditionalArtwork memiliki Medium dan Size. Hubungan ini termasuk Hierarchical Inheritance karena satu parent class (Artwork) memiliki lebih dari satu child class.

# Penjelasan Alur Program
Alur program pada implementasi Python dan C++ secara umum adalah sebagai berikut:
1. Program dimulai.
2. Program membaca data yang tersimpan pada data.txt.
3. Data dari file digunakan untuk membentuk object Client, Commission, dan Artwork beserta hubungan antar-object.
4. Program menampilkan menu utama yang terdiri dari:
   a. Show Data : untuk menampilkan data pesanan yang tersimpan.
   b. Add Commission : menambahkan pesanan baru.
   c. Exit : untuk mengakhiri program.
5. Jika pengguna memilih Show Data, program mengambil dan menampilkan data Client, Commission, serta Artwork.
6. Jika pengguna memilih Add Commission, program meminta:
   a. Data client,
   b. Data commission,
   c. Data artwork,
   d. Jenis artwork yang dipesan.
7. Jika pengguna memilih Digital, program membuat object DigitalArtwork beserta FileFormat dan Resolution.
8. Jika pengguna memilih Traditional, program membuat object TraditionalArtwork beserta Medium dan Size.
9. Artwork yang telah dibuat disimpan ke dalam Commission, kemudian Commission disimpan ke dalam Client.
10. Data yang telah ditambahkan disimpan ke dalam data.txt.
11. Program kembali ke menu utama dan dapat digunakan kembali.
12. Jika pengguna memilih Exit, program selesai.

# Dokumentasi
Dokumentasi program disertakan pada Folder Dokumentasi di setiap masing-masing folder bahasa pemrograman
