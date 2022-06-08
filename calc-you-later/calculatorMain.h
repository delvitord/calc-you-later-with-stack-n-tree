#ifndef calculatorMain_H
#define calculatorMain_H

#include <string.h>
#include <windows.h>
#include <math.h>
#include "tree.h"
#include "stack.h"
#include "stackInt.h"
#include "stackChar.h"
#include "boolean.h"

/*  Method yang digunakan untuk menampilkan menu pada aplikas calc-you-later
    I.S: Menu belum ditampilkan pada layar
    F.S: Menu ditampilkan pada layar */
void menu();

/*  Modul untuk menentukan posisi output 
    I.S: Posisi output tidak diatur
    F.S: Posisi output telah diatur */
void gotoxy(int x, int y);

/*  Method yang digunakan untuk menampilkan info UI pada aplikas calc-you-later
    I.S: Info belum ditampilkan pada layar
    F.S: Info ditampilkan pada layar */
void printUI();

/*  Method yang digunakan untuk menampilkan info about pada aplikas calc-you-later
    I.S: About belum ditampilkan pada layar
    F.S: About ditampilkan pada layar */
void about();

/*  Method untuk menjalankan fitur kalkulator utama
    I.S: Fitur kalkulator dasar belum dijalankan
    F.S: Fitur kalkulator dasar dijalankan */
void menu_calculator();

/*  Mengembalikan nilai true jika input user sesuai dengan aturan */
boolean cekInput(String input);

/*  Mengembalikan nilai true jika c berupa operator matematis */
boolean cekOperator(char c);

/*  Mengembalikan nilai true jika c berupa angka */
boolean cekAngka(char c);

/* Mengembalikan nilai true jika c berupa tanda kurung */
boolean cekParentheses(char c);

/* Menampilkan menu binToDec */
void menu_binToDec();

/* Menampilkan menu decToBin */
void menu_decToBin();

/*  Method untuk menjalankan fitur konversi
    I.S: Fitur konversi dasar belum dijalankan
    F.S: Fitur konversi dasar dijalankan */
void decToBin(int desimal);


#endif
