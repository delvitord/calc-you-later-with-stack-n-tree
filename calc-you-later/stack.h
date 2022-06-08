#ifndef _stack_H
#define _stack_H

#include "boolean.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

#define nil NULL
#define info(p) (p)->info
#define prev(p) p->prev
#define top(s) (s).top

typedef char String[100];
typedef struct telmstack *address;
typedef struct telmstack{
	char info;
	address prev;
}tabstack;

typedef struct{
	address top;
}stack;

void createstack(stack *s); // membuat Stack
address alokasi(char x); // mengalokasikan address dalam stack
void dealokasi(address p);// mendealokasikan address dalam stack
void push(stack *s, char x);// masukan element ke stack
void pop(stack *s, char *x);// keluarkan element dari stack
void cetakstack(stack s); // menampilkan data dalam stack
boolean isstackempty(stack s); //cek apakah stack kosong
void InfixToPostfix (String infix, String postfix); //konversi infix ke postfix
int priority(char x); //memberi prioritas pada tiap operator
boolean cekPriority(char a, char b); //mengembalikan true jika operator a > operator b

#endif

