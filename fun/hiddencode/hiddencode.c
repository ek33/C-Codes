#include <stdio.h>
#include <stdlib.h>
#include <string.h>

main() {

	FILE *dosya;
	char icerik[10000];
	char gizli[100];
	int i=0,i2,uzunluk,tekUzunluk,gizliUzunluk;
	dosya=fopen("text.txt","r");
	char test[6];
	
	while((icerik[i]=fgetc(dosya))!=EOF)
		i++;
    
	uzunluk=strlen(icerik);
	strncpy(test,icerik,5);

	for(i=1;i<5000;i++)
		if(test[0]==icerik[i])
			if(test[1]==icerik[i+1]
				if(test[2]==icerik[i+2])
					if(test[3]==icerik[i+3])
						if(test[4]==icerik[i+4]){
							tekUzunluk=i;
							break;
						}		
	
	gizliUzunluk=uzunluk%tekUzunluk;

	for(i=tekUzunluk;i<5000;i+=tekUzunluk){
		if(icerik[i]!=icerik[0])
			break;
	}
	FILE *cikti;
	cikti=fopen("hiddencode.txt","w");
	
	for(i2=1;i2<gizliUzunluk;i++,i2++)
		putc(icerik[i],cikti);
	
	return 0;
}
