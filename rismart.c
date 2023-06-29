/*TUGAS AKHIR ALGORITMA DAN PEMROGRAMAN
Prodi S1 Sistem Informasi / Kelas C
UPN Veteran Jakarta

MUHAMMAD ARIF RAHMAN			2110512092
ANDES ANDEDIA FANANSA			2110512101
RISMA NURCAHYANI				2110512102
MUHAMMAD ZAKI PRADANA		    2110512106
BRAMASTASETYA ARIE NUGROHO		2110512118
ANGELINE MEGA KRISTINA			2110512120

Program Minimarket (RISMART)                */

#include<stdio.h>
#include<string.h>

int a=0 , b, d, e=1000, user, kode['0'], c, menu=0, harga['0'], jumlah['0'], tunai['0'], jumharga['0'], ppn['0'], totharga['0'], pemasukan;
char nama['0'][32],baris[64];

FILE *jual;

int login(int *user);
void input();
void view();
void searching();
void cari();
void cekjual();
void update();
void hapus();
int pilih(int user);

void main()
{
    jual=fopen("Data penjualan.txt","a+");
    cekjual();
    int menu;
    login(&user);
    pilih(user);
}


int pilih(int user)
{
    int menu;
    while(menu!=6){
    if (user==1){
        system("cls");
        printf("\n\n   +-------------------------------------------------+\n");
        printf("   |                                                 |\n");
        printf("   |                       MENU                      |\n");
        printf("   |                                                 |\n");
        printf("   | 1 <- Input Penjualan      Update Penjualan -> 4 |\n");
        printf("   |                                                 |\n");
        printf("   | 2 <- View Penjualan       Delete Penjualan -> 5 |\n");
        printf("   |                                                 |\n");
        printf("   | 3 <- Search Penjualan               KELUAR -> 6 |\n");
        printf("   |                                                 |\n");
        printf("   +-------------------------------------------------+\n");
        scanf("%d",&menu);
    } else if (user==2){
        system("cls");
        printf("\n\n   +-------------------------------------------------+\n");
        printf("   |                                                 |\n");
        printf("   |                       MENU                      |\n");
        printf("   |                                                 |\n");
        printf("   | 1 <- Input Penjualan                            |\n");
        printf("   |                                                 |\n");
        printf("   | 2 <- View Penjualan                             |\n");
        printf("   |                                                 |\n");
        printf("   | 3 <- Search Penjualan               KELUAR -> 6 |\n");
        printf("   |                                                 |\n");
        printf("   +-------------------------------------------------+\n");
        scanf("%d",&menu);
        }

    if (user==1){
        switch(menu)
        {
        case 1 :
                system("cls");
                input();
                getch();
                break;
        case 2 :
                system("cls");
                view();
                getch();
                break;
        case 3 :
                system("cls");
                searching();
                getch();
                break;
        case 4 :
                system("cls");
                update();
                getch();
                break;
        case 5 :
                system("cls");
                hapus();
                getch();
                break;
        case 6 :
                system("cls");
                printf("\n  +-------------------+\n");
                printf("  |   RRR   M     M   |\n");
                printf("  |   R RR  M M M M   |\n");
                printf("  |   RRR   M  M  M   |\n");
                printf("  |   R  R  M     M   |\n");
                printf("  +-------------------+\n");
                printf("  |      RisMart      |\n");
                printf("  |   logging out...  |\n");
                printf("  +-------------------+\n\n");
                sleep(3);
                catat();
                fclose(jual);
                login(&user);
                break;
        default :
                system("cls");
                printf("\n  +----------------------+\n");
                printf("  |   INPUT MENU SALAH   |\n");
                printf("  |   SILAKAN COBA LAGI  |\n");
                printf("  +----------------------+\n");
                getch();
        }
    }else if (user==2){
        switch(menu)
        {
        case 1 :
                system("cls");
                input();
                getch();
                break;
        case 2 :
                system("cls");
                view();
                getch();
                break;
        case 3 :
                system("cls");
                searching();
                getch();
                break;
        case 6 :
                system("cls");
                printf("\n  +-------------------+\n");
                printf("  |   RRR   M     M   |\n");
                printf("  |   R RR  M M M M   |\n");
                printf("  |   RRR   M  M  M   |\n");
                printf("  |   R  R  M     M   |\n");
                printf("  +-------------------+\n");
                printf("  |      RisMart      |\n");
                printf("  |   logging out...  |\n");
                printf("  +-------------------+\n\n");
                sleep(3);
                catat();
                fclose(jual);
                login(&user);
                break;
        default :
                system("cls");
                printf("\n  +----------------------+\n");
                printf("  |   INPUT MENU SALAH   |\n");
                printf("  |   SILAKAN COBA LAGI  |\n");
                printf("  +----------------------+\n");
                getch();
            }
        }
    }
}

int login(int *user)
{
    char username[50], password[50];
    system("cls");
    printf("\n  +-------------------+\n");
    printf("  |   RRR   M     M   |\n");
    printf("  |   R RR  M M M M   |\n");
    printf("  |   RRR   M  M  M   |\n");
    printf("  |   R  R  M     M   |\n");
    printf("  +-------------------+\n");
    printf("  |      RisMart      |\n");
    printf("  +-------------------+\n\n");
    printf(" Enter your username: ");
    scanf("%s",&username);
    printf(" Enter your password: ");
    scanf("%s",&password);

    if(strcmp(username,"owner")==0){
        if(strcmp(password,"masta123")==0){
            printf("\n  +-------------------+\n");
            printf("  |   DEMI KEAMANAN   |\n");
            printf("  |   SILAKAN GANTI   |\n");
            printf("  |    USERNAME DAN   |\n");
            printf("  |  PASSWORD SECARA  |\n");
            printf("  |      BERKALA      |\n");
            printf("  +-------------------|\n");
            printf("  |      Loading..    |\n");
            printf("  +-------------------+");
            sleep(3);
            *user=1;
        }else{
            system("cls");
            printf("\n  +----------------------+\n");
            printf("  | INPUT PASSWORD SALAH |\n");
            printf("  |   SILAKAN COBA LAGI  |\n");
            printf("  +----------------------+\n");
            sleep(3);
            login(&user);
        }
    }else if(strcmp(username,"pegawai")==0){
        if(strcmp(password,"masta")==0){
            printf("\n  +-------------------\n");
            printf("  |   DEMI KEAMANAN   |\n");
            printf("  |   SILAKAN GANTI   |\n");
            printf("  |    USERNAME DAN   |\n");
            printf("  |  PASSWORD SECARA  |\n");
            printf("  |      BERKALA      |\n");
            printf("  +-------------------|\n");
            printf("  |      Loading..    |\n");
            printf("  +-------------------");
            sleep(3);
            *user=2;
        }else{
            system("cls");
            printf("\n  +----------------------+\n");
            printf("  | INPUT PASSWORD SALAH |\n");
            printf("  |   SILAKAN COBA LAGI  |\n");
            printf("  +----------------------+\n");
            sleep(3);
            login(&user);
        }
    }else{
        system("cls");
        printf("\n  +--------------------------+\n");
        printf("  | USERNAME TIDAK DITEMUKAN |\n");
        printf("  |     SILAKAN COBA LAGI    |\n");
        printf("  +--------------------------+\n");
        sleep(3);
        login(&user);
    }
}

void input()
{
	b=1;
	d=0;
	while(b==1)
	{
		a++;
		e++;
		kode[a]=e;
		printf("\n Kode Jual              : %d\n",kode[a]);
		printf(" Masukkan Nama Barang   : ");
		scanf(" %s",nama[a]);
		printf(" Masukkan Harga Barang  : Rp.");
		scanf(" %d",&harga[a]);
		printf(" Masukkan Jumlah Barang : ");
		scanf(" %d",&jumlah[a]);
		jumharga[a]=harga[a]*jumlah[a];
		printf(" Jumlah harga           : Rp.%d\n",jumharga[a]);
		ppn[a]=jumharga[a]*10/100;
		printf(" PPN                    : Rp.%d\n",ppn[a]);
		totharga[a]=jumharga[a]+ppn[a];
		printf(" Total Harga            : Rp.%d\n",totharga[a]);
		fprintf(jual,"\nKode Barang : %d\nNama Barang : %s\nHarga Barang : %d\nJumlah Barang : %d\nJumlah harga : %d\nPPN : %d\nTotal Harga : %d",kode[a],nama[a],harga[a],jumlah[a],jumharga[a],ppn[a],totharga[a]);
		d=d+totharga[a];
		printf("\n Harga Yang Harus Dibayar : Rp.%d",d);
		printf("\n\n ketik 1 untuk input lagi : ");
		scanf("%d",&b);
	}
}

void view()
{
	pemasukan=0;
	printf("\n");
	if(a<1){
		printf(" Data Masih Kosong");
	}else{
		b=1;
		while(b<=a){
			printf("%d.Kode Jual     : %d\n",b,kode[b]);
			printf("  Nama Barang   : %s\n",nama[b]);
			printf("  Harga Barang  : Rp.%d\n",harga[b]);
			printf("  Jumlah Barang : %d\n",jumlah[b]);
			printf("  Jumlah harga  : Rp.%d\n",jumharga[b]);
			printf("  PPN           : Rp.%d\n",ppn[b]);
			printf("  Total Harga   : Rp.%d\n",totharga[b]);
			printf("------------------\n");
			pemasukan=pemasukan+totharga[b];
			b++;
		}
		printf("\n Total Pemasukan : Rp.%d",pemasukan);
	}printf("\n");
}

void searching()
{
	printf(" Kode Jual Yang Akan Dicari : ");
	scanf("%d",&c);
	cari();
	if(d>0){
		b--;
		printf("%d.Kode Jual     : %d\n",b,kode[b]);
		printf("  Nama Barang   : %s\n",nama[b]);
		printf("  Harga Barang  : Rp.%d\n",harga[b]);
		printf("  Jumlah Barang : %d\n",jumlah[b]);
		printf("  Jumlah harga  : Rp.%d\n",jumharga[b]);
		printf("  PPN           : Rp.%d\n",ppn[b]);
		printf("  Total Harga   : Rp.%d\n",totharga[b]);
		printf("------------------\n");
	}else{
		printf(" Kode Jual Anda Tidak Dapat Ditemukan");
	}
}

void cari()
{
	b=1;
	d=0;
	while(b<=a && d==0){
		if(c==kode[b]){
			d++;
		}
		b++;
	}
}

void update()
{
	printf(" Kode Barang Yang Akan Diupdate : ");
	scanf("%d",&c);
	cari();
	printf("\n");
	if(d<1){
		printf(" Data Yang Akan Anda Update Tidak Ada");
	}else{
		b--;
		printf("%d.Kode Jual     : %d\n",b,kode[b]);
		printf("  Nama Barang   : %s\n",nama[b]);
		printf("  Harga Barang  : Rp.%d\n",harga[b]);
		printf("  Jumlah Barang : %d\n",jumlah[b]);
		printf("  Jumlah harga  : Rp.%d\n",jumharga[b]);
		printf("  PPN           : Rp.%d\n",ppn[b]);
		printf("  Total Harga   : Rp.%d\n",totharga[b]);
		printf("------------------\n");
		printf(" Masukkan Nama Barang   : ");
		scanf(" %s",nama[b]);
		printf(" Masukkan Harga Barang  : Rp.");
		scanf(" %d",&harga[b]);
		printf(" Masukkan Jumlah Barang : ");
		scanf(" %d",&jumlah[b]);
		jumharga[b]=harga[b]*jumlah[b];
		printf(" Jumlah harga           : Rp.%d\n",jumharga[b]);
		ppn[b]=jumharga[b]*10/100;
		printf(" PPN                    : Rp.%d\n",ppn[b]);
		totharga[b]=jumharga[b]+ppn[b];
		printf(" Total Harga            : Rp.%d\n",totharga[b]);
	}printf("\n");
}

void hapus()
{
	printf(" Kode Barang Yang Ingin Dihapus : ");
	scanf("%d",&c);
	cari();
	printf("\n");
	if(d<1){
		printf(" Data Yang Akan Anda Delete Mungkin Tidak Ada");
	}else{
		b--;
		printf(" Data %d Berhasil Didelete",kode[b]);
		while(b<a){
			kode[b]=kode[b+1];
			strcpy(nama[b],nama[b+1]);
			harga[b]=harga[b+1];
			jumlah[b]=jumlah[b+1];
			jumharga[b]=jumharga[b+1];
			ppn[b]=ppn[b+1];
			totharga[b]=totharga[b+1];
			b++;
		}
		a--;
	}printf("\n");
}
void catat()
{
	fclose(jual);
	jual=fopen("Data penjualan.txt","w+");
	fclose(jual);
	jual=fopen("Data penjualan.txt","a+");
	fprintf(jual,"Data Penjualan");
	b=1;
	while(b<=a){
		fprintf(jual,"\nKode Barang : %d\nNama Barang : %s\nHarga Barang : %d\nJumlah Barang : %d\nJumlah harga : %d\nPPN : %d\nTotal Harga : %d",kode[b],nama[b],harga[b],jumlah[b],jumharga[b],ppn[b],totharga[b]);
		b++;
	}
}

void cekjual()
{
	rewind(jual);
	if(fgets(baris,64,jual)==NULL){
		a=0;
		fprintf(jual,"Data Penjualan");
	}
    else{
		while(!feof(jual)){
			a++;
			fscanf(jual,"\nKode Barang : %d\nNama Barang : %s\nHarga Barang : %d\nJumlah Barang : %d\nJumlah harga : %d\nPPN : %d\nTotal Harga : %d",&kode[a],nama[a],&harga[a],&jumlah[a],&jumharga[a],&ppn[a],&totharga[a]);
		}e=kode[a];
	}
}
