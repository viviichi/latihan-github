SUNIB HOSPITAL

Program ini merupakan aplikasi manajemen data obat sederhana dari rumah sakit bernama SUNIB HOSPITAL. Program ini ditulis menggunakan bahasa pemrograman C dan menggunakan struktur data hash table untuk menyimpan, mencari, dan menghapus informasi obat secara mudah dan efisien.

setelah program dijalankan akan muncul tampilan sebagai berikut 
--- Sunib Hospital ---
1. View Medicine
2. Insert Medicine
3. Remove Medicine
4. Exit
Enter your choice:

- Pilih opsi 1 untuk melihat daftar semua obat yang telah dimasukkan.
Jika belum ada obat, program akan menampilkan:

Medicine ID | Medicine Name | Manufacturer | Registration Number | Batch/Lot Number
There is no medicine(s)!

--- Sunib Hospital ---
1. View Medicine
2. Insert Medicine
3. Remove Medicine
4. Exit
Enter your choice:

- Pilih opsi 2 untuk menambahkan data obat baru.
Program akan meminta user mengisi data obat secara bertahap, berikut tampilannya:

--- Sunib Hospital ---
1. View Medicine
2. Insert Medicine
3. Remove Medicine
4. Exit
Enter your choice: 2
Enter Medicine Name (between 5 and 50 characters): paracetamol
Enter Manufacturer Name (between 3 and 25 characters, ending with 'Ltd.'): idkLtd.
Enter Registration Number (10 digits): 1234567890
Enter Batch/Lot Number (16 digits): Invalid input! Batch/Lot Number must be 16 digits.
Enter Batch/Lot Number (16 digits): 1234567890123456
Medicine inserted successfully!

- Pilih opsi 3 untuk menghapus obat berdasarkan ID.
Program akan meminta user memasukkan ID dari obat yang ingin dihapus, ID adalah angka unik yang dibuat otomatis saat user memasukkan obat.
user bisa melihat ID dari hasil menu 1. View Medicine. berikut tampilannya:

--- Sunib Hospital ---
1. View Medicine
2. Insert Medicine
3. Remove Medicine
4. Exit
Enter your choice: 3
Enter Medicine ID to remove: 1
Medicine found:
Medicine ID | Medicine Name | Manufacturer | Registration Number | Batch/Lot Number
1           | paracetamol   | idkLtd.      | 1234567890           | 1234567890123456
Are you sure you want to remove this medicine? (y/n): y
Medicine removed successfully!

- Pilih opsi 4 untuk langsung keluar dari program (langkah ini tidak memunculkan output apapun)
  
