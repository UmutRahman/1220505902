#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> //tolower ve isalpha fonksiyonlarý için kütüphane koydum


int main() {
	
	  FILE *dosya1; //dosya oluþturmak için FÝLE kullanarak dosya1 ve dosya2 yi tanýmladým
	  FILE *dosya2;
	
   	  int secim; 
	
	  printf("Lutfen yapacaginiz islemi seciniz:\n"); //kullanýcýyý yönlendirmek amacýyla ekrana þifre oluþturma ve çözme adýnda 2 seçenek sundum ve girmesini istedim
	  printf("1. Sifre olusturma:\n 2. Sifre cozme:\n");
	  scanf("%d",&secim);
	
	
	switch(secim) //switch case kullanarak þifre oluþturmak ve çözmek için 2 durum oluþturdum
	{
		
case 1 : //case 1 de dosya1 ve dosya2 nin konumlarýný fopen kullanarak girdim	
	
		dosya1=fopen("C:\\Users\\polat\\OneDrive\\Masaüstü\\input 1.txt","r");
		dosya2=fopen("C:\\Users\\polat\\OneDrive\\Masaüstü\\output 1.txt","wa+");
		
		int anahtar; //deðiþkenleri tanýmladým
		int karakter;
		char harf;
		
		printf("Sifreleme anahtarini giriniz:"); //kullanýcýnýn þifreleme anahtarýný girmesi için yönlendirdim
		scanf("%d",&anahtar);
	

		
		if(anahtar==harf)//kullanýcý anahtara harf girdiðinde uyarmak için if kullanarak uyarý kodu yazdým.
		{
				
				printf("Harf girdiniz.\nLutfen harf yerine sayi girerek tekrar deneyiniz.");
	
		break;
       }
		
		
		
	do //do while kullanarak önce iþlemi gerçekleþtirdim daha sonra koþulu sorgulattým
		{
			karakter=getc(dosya1); // karakteri dosya1 de okumasý için bunu yaptým
		
			
			if(karakter==32) // burada kelimeler arasý boþluk kullanmasý için ve 2. cümleyi alt satýrda yazdýrmasý için if bloðunu kullandým
			{                     //32 boþluk 10 alt satýr dan oluþtuðu için böyle bir eþitleme yaptým
				printf("  ");
			}
			else if(karakter==10)
			{
				printf(" \n ");
			}
			
			
			
			if(isalpha(karakter)) //isalpha kullanarak karakterin alfabede yer alýp almadýgýna bakar eðer yer alýyorsa yazdýrýr.
			{
				
				
				//þifrelemeyi gerçekleþtirmek için kullanmamýz gereken iþlemler bunlardýr
				karakter=tolower(karakter); //karakterleri küçük harfle yazdýrýr
				karakter-='a';              //harfi eksiltir ve karaktere eþitler
				karakter+=abs(anahtar);     //anahtarýn mutlak deðerini alýr ve karaktere ekler
				karakter%=26;               //karakterin 26ya göre modunu alýr
				karakter+='a';              //harfi arttýrýr ve karaktere eþitler
				
				printf("%c",karakter);      //oluþan karakterleri ekrana yazdýrýr
				
				putc(karakter,dosya2);      //oluþan karakterleri dosya2 ye yazdýrýr
				
			}
			
		}
	while(karakter!=EOF); //koþulumuz iþlemi sona erdirir
	
		
		fclose(dosya1); //dosya1 ve dosya2 yi kapatýr
		fclose(dosya2);
		
		break;
			
case 2: //case 1 de yaptýðýmýz çoðu þeyi burada da yaptýk
			
	      dosya1=fopen("C:\\Users\\polat\\OneDrive\\Masaüstü\\input 1.txt","r");
	      dosya2=fopen("C:\\Users\\polat\\OneDrive\\Masaüstü\\output 1.txt","wa+");
		
		
		  printf("sifreleme anahtarini giriniz:");
		  scanf("%d",&anahtar);
		  
		  
		  	if(anahtar==harf)//kullanýcý anahtara harf girdiðinde uyarmak için if kullanarak uyarý kodu yazdým.
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
				anahtar-=anahtar; //case 1 den farklý olarak burada þifre çözeceðimiz için anahtarý eksiltip anahtara eþitledim böylece harfler geri gelmiþ oldu
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
