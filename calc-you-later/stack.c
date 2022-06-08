#include "stack.h"
#include <stdio.h>
#include <conio.h>
#include <string.h>

/* Method ini berfungsi untuk membuat Stack
   I.S : S terdefinisi, tidak diketahui nilainya
   F.S : S diinisialisasi top(s) = nil */
void createstack(stack *s){
	top(*s) = nil;
}

/* Method ini mengirim sebuah address jika alokasi type Stack berhasil */
address alokasi(char x){
	//Kamus
	tabstack *p;
	
	//Algoritma
	p = (tabstack*)malloc(sizeof(tabstack));
	if(p != nil){
		info(p) = x;
		p->prev = nil;
		return p;
	} else {
		return nil;
	}
}

/* Modul berfungsi untuk melakukan dealokasi/pengembalian address P
   I.S : P terdefinisi
   F.S : P dikembalikan ke sistem */
void dealokasi(address p){
	free(p);
}

/* Method ini berfungsi untuk memasukkan info ke dalam stack. 
   I.S : S terdefinisi sembarang, mungkin kosong
   F.S : S bertambah sebuah elemen sebagai elemen pertama */
void push(stack *s, char x){
	//Kamus
	address p,q;
	
	//Algoritma
	p = alokasi(x);
	if (isstackempty(*s)) { // Stack Kosong
		top(*s) = p;
	} else { // Stack tidak kosong
		prev(p) = top(*s);
		top(*s) = p;
	}
}

/* Method ini berfungsi untuk mengeluarkan elemen yang berada paling atas
   I.S : S terdefinisi, Stack tidak kosong
   F.S : Menghapus elemen pada top(s) */
void pop(stack *s, char *x){
	//Kamus
	address pTOP,tmp2;
	int out;
	
	//Algoritma
	pTOP = top(*s);
	*x = info(pTOP);
	if(prev(pTOP) == nil){ // hanya ada 1 elemen
		top(*s) = nil;
	} else { // lebih dari satu elemen
		top(*s) = prev(pTOP);
		prev(pTOP) = nil;
	}
}

/* Method ini berfungsi untuk menampilkan data dalam stack mulai dari yang 
   paling bawah hingga yang paling atas.
   I.S : S terdefinisi, mungkin kosong
   F.S : Menampilkan seluruh elemen dalam stack ke layar dari mulai TOP sampai 
         dengan bottom jika tidak kosong */
void cetakstack(stack s){
	//Kamus
	tabstack *p, *q;
	
	//Algoritma
	printf("isi stack dari mulai TOP sampai BOTTOM : \n");
	if(!isstackempty(s)){
		p = top(s);
		printf("[ %d ]", info(p));
		p = prev(p);
		while (p != nil){
			printf(" - [ %d ]", info(p));
			p = prev(p);
		}
	} else {
		printf("[ Empty ]");
	}
}

/* Modul ini digunakan untuk mengecek apakah stack kosong atau tidak. 
Modul ini akan mengirimkan true apabila stack kosong dan false jika tidak kosong */
boolean isstackempty(stack s){
	if(top(s) == nil){
		return true;
	} else {
		return false;
	}	
}

/*******************************************************************/
/*  OPERASI STACK UNTUK CALCULATOR                                  */
/*******************************************************************/

/* Modul ini digunakan untuk mengkononversi ekspresi Infix ke Postfix
   I.S: String postfix belum terbentuk
   F.S: String postfix dari inputan user terbentuk */
void InfixToPostfix (String infix, String postfix){
	/* Kamus Data */
	int i, length, idx=0;
	char tmp;
	stack s;
	
	/* Algoritma */
	createstack(&s);
	length = strlen(infix);
	for(i=0; i<length; i++){
		
		// Jika input berupa angka
		if(cekAngka(infix[i]) || infix[i] == '.'){
			postfix[idx] = infix[i];
			idx++;
			
		// Jika input berupa '(', push ke dalam stack
		}else if(infix[i] == '('){
			push(&s, infix[i]);  //push
			
		// Jika input berupa ')', 
		// pop stack hingga karakter '(' ditemukan
		}else if(infix[i] == ')'){
			while(!isstackempty(s) && info(top(s))!= '('){
				postfix[idx] = ' ';
				idx++;
				
				pop(&s, &tmp);
				postfix[idx] = tmp;
				idx++;
				
				postfix[idx] = ' ';
				idx++;
			}
			pop(&s, &tmp);
		}else{
			
		// Jika input berupa operator
			if(isstackempty(s)){
				push(&s, infix[i]);  //push
			}else if(!cekPriority(infix[i], info(top(s)))){
				push(&s, infix[i]);  //push
			}else{
				while(!isstackempty(s) && cekPriority(infix[i], info(top(s)))){
					postfix[idx] = ' ';
					idx++;
					
					pop(&s, &tmp);
					
					postfix[idx] = tmp;
					idx++;
					
					postfix[idx] = ' ';
					idx++;
				}
				push(&s, infix[i]);  //push
			}
		}
		if(!cekAngka(infix[i+1]) && infix[i+1] != '.'){
			postfix[idx] = ' ';
			idx++;
		}
	}
	
	// Pop semua operator dari dalam stack
	while(!isstackempty(s)){
		postfix[idx] = ' ';
		idx++;
		
		pop(&s, &tmp);
		
		postfix[idx] = tmp;
		idx++;
	}
	postfix[idx] = '\0';
}

/* Mengembalikan nilai prioritas dari suatu operator*/
int priority(char x){
	switch(x){
		case ')':
			return 0;
		case '(':
			return 0;
		case '-':
			return 1;
		case '+':
			return 1;
		case '/':
			return 2;
		case '*':
			return 2;
		case 'v': //akar
			return 3;
		case '^': //pangkat
			return 4;
		case 'i': //sin
			return 5;
		case 'o': //cos
			return 5;
		case 'a': //tan
			return 5;
		case 'l': //log
			return 5;
		case 's': //sin sudut
			return 5;		
		case 'c': //cos sudut
			return 5;
		case 't': // tan sudut
			return 5;	
	}
}

/* Mengembalikan nilai true, jika operator a memiliki 
   prioritas yang lebih rendah dibanding operator b */
boolean cekPriority(char a, char b){
	return (priority(a) <= priority(b));
}
