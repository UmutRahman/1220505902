#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> //tolower ve isalpha fonksiyonlar� i�in k�t�phane koydum


int main() {
	
	  FILE *dosya1; //dosya olu�turmak i�in F�LE kullanarak dosya1 ve dosya2 yi tan�mlad�m
	  FILE *dosya2;
	
   	  int secim; 
	
	  printf("Lutfen yapacaginiz islemi seciniz:\n"); //kullan�c�y� y�nlendirmek amac�yla ekrana �ifre olu�turma ve ��zme ad�nda 2 se�enek sundum ve girmesini istedim
	  printf("1. Sifre olusturma:\n 2. Sifre cozme:\n");
	  scanf("%d",&secim);
	
	
	switch(secim) //switch case kullanarak �ifre olu�turmak ve ��zmek i�in 2 durum olu�turdum
	{
		
case 1 : //case 1 de dosya1 ve dosya2 nin konumlar�n� fopen kullanarak girdim	
	
		dosya1=fopen("C:\\Users\\polat\\OneDrive\\Masa�st�\\input 1.txt","r");
		dosya2=fopen("C:\\Users\\polat\\OneDrive\\Masa�st�\\output 1.txt","wa+");
		
		int anahtar; //de�i�kenleri tan�mlad�m
		int karakter;
		char harf;
		
		printf("Sifreleme anahtarini giriniz:"); //kullan�c�n�n �ifreleme anahtar�n� girmesi i�in y�nlendirdim
		scanf("%d",&anahtar);
	

		
		if(anahtar==harf)//kullan�c� anahtara harf girdi�inde uyarmak i�in if kullanarak uyar� kodu yazd�m.
		{
				
				printf("Harf girdiniz.\nLutfen harf yerine sayi girerek tekrar deneyiniz.");
	
		break;
       }
		
		
		
	do //do while kullanarak �nce i�lemi ger�ekle�tirdim daha sonra ko�ulu sorgulatt�m
		{
			karakter=getc(dosya1); // karakteri dosya1 de okumas� i�in bunu yapt�m
		
			
			if(karakter==32) // burada kelimeler aras� bo�luk kullanmas� i�in ve 2. c�mleyi alt sat�rda yazd�rmas� i�in if blo�unu kulland�m
			{                     //32 bo�luk 10 alt sat�r dan olu�tu�u i�in b�yle bir e�itleme yapt�m
				printf("  ");
			}
			else if(karakter==10)
			{
				printf(" \n ");
			}
			
			
			
			if(isalpha(karakter)) //isalpha kullanarak karakterin alfabede yer al�p almad�g�na bakar e�er yer al�yorsa yazd�r�r.
			{
				
				
				//�ifrelemeyi ger�ekle�tirmek i�in kullanmam�z gereken i�lemler bunlard�r
				karakter=tolower(karakter); //karakterleri k���k harfle yazd�r�r
				karakter-='a';              //harfi eksiltir ve karaktere e�itler
				karakter+=abs(anahtar);     //anahtar�n mutlak de�erini al�r ve karaktere ekler
				karakter%=26;               //karakterin 26ya g�re modunu al�r
				karakter+='a';              //harfi artt�r�r ve karaktere e�itler
				
				printf("%c",karakter);      //olu�an karakterleri ekrana yazd�r�r
				
				putc(karakter,dosya2);      //olu�an karakterleri dosya2 ye yazd�r�r
				
			}
			
		}
	while(karakter!=EOF); //ko�ulumuz i�lemi sona erdirir
	
		
		fclose(dosya1); //dosya1 ve dosya2 yi kapat�r
		fclose(dosya2);
		
		break;
			
case 2: //case 1 de yapt���m�z �o�u �eyi burada da yapt�k
			
	      dosya1=fopen("C:\\Users\\polat\\OneDrive\\Masa�st�\\input 1.txt","r");
	      dosya2=fopen("C:\\Users\\polat\\OneDrive\\Masa�st�\\output 1.txt","wa+");
		
		
		  printf("sifreleme anahtarini giriniz:");
		  scanf("%d",&anahtar);
		  
		  
		  	if(anahtar==harf)//kullan�c� anahtara harf girdi�inde uyarmak i�in if kullanarak uyar� kodu yazd�m.
		 {
				
				printf("Harf girdiniz.\nLutfen harf yerine sayi girerek tekrar deneyiniz.");
	
		break;
         }
         
			
	do
		{
			karakter=getc(dosya1);
			
			if(karakter==32)
			{
				printf("  ");
			}
			else if(karakter==10)
			{
				printf(" \n ");
			}
			
		
			if(isalpha(karakter))
			{
			
				
				karakter=tolower(karakter); 
				karakter-='a';              
				anahtar-=anahtar; //case 1 den farkl� olarak burada �ifre ��zece�imiz i�in anahtar� eksiltip anahtara e�itledim b�ylece harfler geri gelmi� oldu
				karakter%=26;               
				karakter+='a';      
				
				printf("%c",karakter);
				
				putc(karakter,dosya2);
				
			}
		}
	while(karakter!=EOF);
		
		fclose(dosya1);
		fclose(dosya2);
		
		break;
	}
	return 0;
}
