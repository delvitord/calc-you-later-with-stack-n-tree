#include "calculatorMain.h"

//Method yang digunakan untuk menampilkan menu pada aplikasi calc-you-later

void menu(){
	int pilihan;
	do {
		system("cls");
		gotoxy(45,7); printf("============================");
		gotoxy(45,8);printf("==== CALC - YOU - LATER ===="); 
		gotoxy(45,9);printf("============================");
		gotoxy(52,11);printf("1. Kalkulator"); 
		gotoxy(49,12);printf("2. Biner ke Desimal"); 
		gotoxy(49,13);printf("3. Desimal ke Biner"); 
		gotoxy(53,14);printf("4.  About"); 
		gotoxy(54,15);printf("5. Exit");
		gotoxy(48,18);printf("------ Main Menu ------");
		gotoxy(47,16);printf("Masukkan Pilihan anda : "); 
		scanf("%d", &pilihan);
		char dump = getchar();
		switch (pilihan){
			case 1:
				menu_calculator();
				break;
			case 2: 
				menu_binToDec();
				break;
			case 3:
				menu_decToBin();
				break;
			case 4:
				about();
				break;
		}
	} while(pilihan < 5);
	
} 

//Modul untuk menentukan posisi output 

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Method yang digunakan untuk menampilkan info pada aplikas calc-you-later

void printUI(){
	system("cls");
	gotoxy(45,1); printf("============================");
	gotoxy(45,2);printf("==== CALC - YOU - LATER ===="); 
	gotoxy(45,3);printf("============================");
	gotoxy(75,5); printf("Operator Matematika");
	gotoxy(75,6); printf("'+' untuk tambah");
	gotoxy(75,7); printf("'-' untuk kurang dan bilangan negatif");
	gotoxy(75,8); printf("'*' untuk kali");
 	gotoxy(75,9); printf("'/' untuk bagi");
	gotoxy(75,10); printf("'^' untuk pangkat");
	gotoxy(75,11); printf("'v' untuk akar pangkat");
	
	gotoxy(75,13); printf("Operator di bawah ini ditulis");
	gotoxy(75,14); printf("setelah bilangan atau kurung yang ");
	gotoxy(75,15); printf("akan dihitung dengan operator tersebut");
	
	gotoxy(75,16); printf("'i0' untuk sin // 's0' untuk derajat");
	gotoxy(75,17); printf("'o0' untuk cos // 'c0' untuk derajat");
	gotoxy(75,18); printf("'a0' untuk tan // 't0' untuk derajat");
	gotoxy(75,19); printf("'l0' untuk logaritma");
	
	gotoxy(75,21); printf("Bilangan negatif harus disimpan dalam kurung");
	
	gotoxy(75,23); printf("Tingkatan prioritas operasi");
	gotoxy(75,24); printf("1. Bilangan negatif dan kurung'()'");
	gotoxy(75,25); printf("2. Pangkat");
	gotoxy(75,26); printf("3. Akar");
	gotoxy(75,27); printf("4. Trigonometri dan Logaritma");
	gotoxy(75,28); printf("5. Kali dan bagi");
	gotoxy(75,29); printf("6. Tambah dan kurang");

	gotoxy(0,5);
}

//Method yang digunakan untuk menampilkan info about pada aplikas calc-you-later

void about(){
	system("cls");
	printf("About: \n");
	printf("Calc-You-Later adalah aplikasi kalkulator yang dibuat oleh kelompok 5 kelas 1B yang\ndidasarkan pada kalkulator konvensional.\n");
	printf("Calc-You-Later dapat digunakan sebagaimana kalkulator konvensional (dapat menjalankan operasi tambah,\nkurang, kali, bagi, serta beberapa operasi tambahan seperti pangkat, akar, trigonometri, dan sebagainya).\n");
	printf("Calc-You-Later juga memiliki dua fitur tambahan, yaitu fitur konversi bilangan desimal \nke biner, dan fitur konversi bilangan biner ke desimal.\n");
	printf("Program ini dirilis pada tanggal 6 Juni 2022 untuk memenuhi Tugas Besar Struktur Data dan Algoritma.\n");
	printf("\nAuthor:\n");
	printf("Delvito Rahim Derivansyah\n");
	printf("Muhammad Rafi Farhan\n");
	printf("Reihan Hadi Fauzan\n");
	printf("\n");
	printf("Dosen Pengampu:\n");
	printf("Lukmanul Hakim Firdaus, S.Kom, M.T.\n");
	printf("Asri Maspupah, S.ST., M.T.\n");
	printf("\n");
	printf("2022\n");
	printf("Program Studi D4 Teknik Informatika\n");
	printf("Jurusan Teknik Komputer dan Informatika\n");
	printf("Politeknik Negeri Bandung\n");
	printf("\ncukup? (klik apa saja)");
	char isToMenu = getch();
}

//Fitur kalkulator utama
   
void menu_calculator(){
	// Kamus Data
	String input, postfix;
	addrTree t;
	double result;
	

	// Algoritma
	printUI();
	printf("Masukkan operasi matematika :");
	gotoxy(0,6);
	gotoxy(0,6); scanf("%s", &input);
	
	if (cekInput(input) == false) {
		input[0] = '\0'; // Kosongkan string
		gotoxy(0,9); system("pause");
		system("cls");
		menu_calculator();
	}
	InfixToPostfix(input, postfix);
	t = insertNode(postfix);
	result = calculateTree(t);
	
	// Jika hasil desimal melebihi 2 digit
	if(ceil(result) > result){
		gotoxy(0, 7); printf("= %0.2f", result);
	}else{
		gotoxy(0, 7); printf("= %0.f", result);
	}
	
	//opsi untuk mengubah nilai ke dalam biner
	if(result >= 1){
    printf("\n\nIngin merubahnya ke dalam bentuk biner? (Klik Y untuk Ya): ");
    char isToBiner = getch();
    if (isToBiner == 'Y' || isToBiner == 'y'){
    	int toBiner = result;
    	decToBin(toBiner);
	} else {
		printf("\n\n");
	}
	}

	// opsi jika ingin memasukan nilai lainnya
	printf("\n\nKlik spasi jika ingin memasukkan operasi matematika yang lain: ");
    char isToMenu = getch();
    if (isToMenu == ' '){
    	menu_calculator();
	}

	
}

//  Mengembalikan nilai true jika input user sesuai dengan aturan
boolean cekInput(String input){
    int i, j, length;
    boolean inputTrue = true, nextAngka = true;   // cek inputan selanjutnya

    //Melakukan cek agar input awal dan akhir bukan operator
    if(cekOperator(input[0]) == true || cekOperator(input[length-1]) == true){
        gotoxy(0, 6); printf("Input gagal!");
		gotoxy(0, 7); printf("Mohon masukan input sesuai data yang tersedia");
        return false;
    }

    // Cek keseluruhan inputan
    for(i=0; i<strlen(input)-1; i++){
        if(cekParentheses(input[i]) == true){
        	
			// Jika input yang diberikan bernilai negatif
			if(input[i] == '(' && input[i+1] == '-'){
				length = strlen(input);
        		for(j=length-1; j>=i+1; j--){
        			input[j+1] = input[j];
				}
				input[i+1] = '0';
				input[length+1] = '\0';
			}
            continue;
        }

        if (cekAngka(input[i]) == true)
        {
            nextAngka = false;
            continue;
        }

        // Cek apakah ada operator yang bersebelahan
        if((cekOperator(input[i]) == true) && (nextAngka == false)){
            nextAngka = true;
            // Cek apakah ada pembagian angka dengan nol (contoh: 2/0)
	        if(input[i] == '/' && input[i+1] == '0'){
	        	gotoxy(0,7); printf("Tidak Terdefinisi!");
	        	return false;
			}
            continue;
        }else{
            gotoxy(0,7); printf("Inputan tidak sesuai!");
            return false;
        }
    }
    return inputTrue;
}

/*  Mengembalikan nilai true jika opr berupa operator matematis */
boolean cekOperator(char opr){
    if(opr == '^' || opr == 'v' || opr == '*' || opr == '/' || opr == '+' || opr == '-' || opr == '.'|| opr == 'i'|| opr == 'o'|| opr == 'a'|| opr == 'l'|| opr == 's'|| opr == 'c'|| opr == 't'){
        return true;
    }else{
        return false;
    }
}

/*  Mengembalikan nilai true jika num berupa angka */
boolean cekAngka(char num){
    if (num >= '0' && num <= '9'){
        return true;
    }else{
        return false;
    }
}

/* Mengembalikan nilai true jika par berupa tanda kurung */
boolean cekParentheses(char par){
    if(par == '(' || par == ')'){
        return true;
    }else{
        return false;
    }
}

void menu_binToDec(){
	//Menu untuk memasukkan bilangan biner dan menampilkan hasil desimalnya
	system("cls");
	gotoxy(45,1); printf("============================");
	gotoxy(45,2);printf("==== CALC - YOU - LATER ===="); 
	gotoxy(45,3);printf("============================");
	gotoxy(41,4);printf("-Pengubah Bilangan Biner ke Desimal-");
	gotoxy(75,7); printf("Notes:");
	gotoxy(75,8); printf("Program tidak akan memproses inputan salah");
	gotoxy(75,9); printf("(ada karakter selain 1 dan 0)");
	gotoxy(0,7);
	
	stackChar s; 
	createstackChar(&s); 
	char nilaiStack;
	printf("Masukkan bilangan biner: \n");
	boolean inputSalah = false;

    do {					//Proses input biner ke stack
    	scanf("%c", &nilaiStack);
    	if (nilaiStack == '1' || nilaiStack == '0'){	
    		pushChar(&s, nilaiStack);
		} else if (nilaiStack != 10) { //jika yang diinput adalah selain 1, 0, dan enter
			inputSalah = true;
		}
	} while (nilaiStack != 10);	//10 adalah ASCII untuk enter
	
	
	if (inputSalah == false){		//inputan benar
		int hasil = binToDec(s);
		printf("\nHasil desimalnya adalah:\n");
		printf("%d\n\n", hasil);
		printf("Klik spasi jika ingin memasukkan bilangan biner yang lain: ");
	    char isToMenu = getch();
	    if (isToMenu == ' '){
	    	menu_binToDec();
		}
	} else {	//inputan salah
		printf("\nInput yang anda masukkan salah\n");
		printf("Klik apa saja untuk kembali memasukkan bilangan biner: ");
	    char isToMenu = getch();
	 	menu_binToDec();		//kembali lagi memasukkan bilangan biner
	}
}

int binToDec(stackChar s){
	//modul pengkonversi bilangan biner ke desimal
	int pilihan, hasilDesimal = 0, nilaiPop2;
	char nilaiPop1; 
	
	stackInt duaPangkatN; //Stack yang menampung 2^0 - 2^n
	createstackInt(&duaPangkatN); 
	int i = s.jumlahTumpukan;
	int value;
	
	for (i; i >= 0; i--){	//Pengisian stack dengan 2^0 - 2^n (n = s.jumlahTumpukan - 1)
		value = pow(2,i);
		pushInt(&duaPangkatN, value);
	}

	while (s.jumlahTumpukan > 0){	//Proses pop semua tumpukan masing-masing stack
		nilaiPop1 = popChar(&s);
		nilaiPop2 = popInt(&duaPangkatN);
		if (nilaiPop1 == '1'){		//Perhitungan ke desimal
			hasilDesimal += nilaiPop2;
		}
	}
	return hasilDesimal;
}

void menu_decToBin(){
	//Menu untuk memasukkan bilangan desimal dan menampilkan hasil binernya
	int desimal;
	system("cls");
	gotoxy(45,1); printf("============================");
	gotoxy(45,2);printf("==== CALC - YOU - LATER ===="); 
	gotoxy(45,3);printf("============================");
	gotoxy(41,4);printf("-Pengubah Bilangan Desimal ke Biner-");
	gotoxy(75,7); printf("Notes:");
	gotoxy(75,8); printf("Program tidak akan memproses inputan salah");
	gotoxy(75,9); printf("(selain dari bilangan bulat positif)");
	gotoxy(0,7);
	printf("\nMasukkan desimal yang akan dikonversi (Bilangan bulat positif): \n"); 
	scanf("%d", &desimal);
	if (desimal > 0){	//Cek kondisi apakah inputan benar
		decToBin(desimal);		//panggil modul konverter
		printf("Klik spasi jika ingin konversi bilangan desimal lain: ");
		char isToMenu = getch();
		if (isToMenu == ' '){
			menu_decToBin();
		}
	} else {
		printf("\nInput yang anda masukkan salah\n");
		printf("Klik apa saja untuk kembali memasukkan bilangan bulat positif: ");
	    char isToMenu = getch();
	    menu_decToBin();
	}
	
}

void decToBin(int desimal){
	//modul pengkonversi bilangan desimal ke biner dan menampilkan binernya
	int hasilModulus;
	stackInt toBin; 	//stack yang akan menampung hasil binernya (Biner dibaca dari top)
	createstackInt(&toBin); 
	while(desimal > 0){	//proses konversi
		hasilModulus = desimal % 2;
		pushInt(&toBin, hasilModulus);
		desimal /= 2;
	}
	printf("\nBilangan binernya adalah: \n");
	cetakstackBiner(toBin);
	printf("\n\n");
}
