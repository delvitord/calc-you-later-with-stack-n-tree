#ifndef tree_H
#define tree_H

#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define Nil NULL
#define Info(P) (P)->info
#define Num(P) (P)->info.num
#define Num_operator(P) (P)->info.num_operator
#define isOpr(P) (P)->info.isOpr
#define Left(P) (P)->left
#define Right(P) (P)->right
#define Next(P) (P)->next

typedef char String[100];

typedef struct{
	double num; // Untuk menampung angka numerik
	char num_operator; // Untuk menampung operator matematis
	boolean isOpr; // Penanda bahwa info dalam node berupa operator
}infotype;
typedef struct tElmtNode *addrTree;
typedef struct tElmtNode {
	infotype info;
	addrTree left;
	addrTree right;
} ElmtNode;

addrTree createNode(infotype X); // membuat node dalam suatu tree
addrTree AlokasiNode (addrTree *newNode); // mengembalikan address hasil alokasi
void printInfoTree(addrTree P); // menampilkan element pada tree
addrTree insertNode(String postfix); // memasukkan ekspresi postfix ke dalam node binary tree dan mengembalikan alamatnya
addrTree buildTree(infotype X, addrTree root); // membangun Tree yang terdiri dari node-node yang telah dibuat dan mengembalikan alamatnya
infotype createInfo(double num, char num_operator, boolean isOpr); // membuat info dalam node Tree dan mengembalikan tipe data infotype
double calculateTree (addrTree root); // melakukan operasi perhitungan matematis dari ekspresi aritmatik binary tree dengan traversal in order dan mengembalikan hasil akhir perhitungan
double calculateMath (char num_operator, double left, double right); // Melakukan operasi perhitungan

#endif
