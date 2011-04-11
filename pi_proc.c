#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){

	int pid;
	
	pid = fork();

	if(pid==0){
		
		int precisao = 1000000;
		double x = random()%precisao;
		x = x/precisao;
	
		double y = random()%precisao;
		y = y/precisao;

		float total = 0;
		float dentro = 0;
		int i = 0;
		double verifica;
		
		for(i=0; i < precisao;i++){
			verifica = sqrt(pow(x,2)+pow(y,2));	
	
			if(verifica<=1){
				dentro=dentro+1;
			}
			total=total+1;
	
			x = random()%precisao;
			x = x/precisao;

			y = random()%precisao;
			y = y/precisao;
		}
				
		double pi = dentro/total;
		FILE *file1=fopen("file2.txt","w+");
		fwrite(&pi,sizeof(double),1,file1);
		fclose(file1);
		wait(NULL);
	}

	else{
        int pid2;

		pid2=fork();
	
		if(pid2==0){
            int precisao = 1000000;
    		double x = random()%precisao;
    		x = x/precisao;
    	
    		double y = random()%precisao;
    		y = y/precisao;
    
    		float total = 0;
    		float dentro = 0;
    		int i = 0;
    		double verifica;
    			for(i=0; i < precisao;i++){
    				verifica = sqrt(pow(x,2)+pow(y,2));	
    		
    				if(verifica<=1){
    					dentro=dentro+1;
    				}
    				total=total+1;
    		
    				x = random()%precisao;
    				x = x/precisao;
    	
    				y = random()%precisao;
    				y = y/precisao;
                }
					
			double pi = dentro/total;
			FILE *file1=fopen("file1.txt","w+");
			fwrite(&pi,sizeof(double),1,file1);
			fclose(file1);
		}
         
        else{
    		wait(NULL);
   		wait(NULL);
    		FILE *file1=fopen("file1.txt","r");
    		if(file1==NULL){
    			printf("ndeu\n");
    			return 2;
    		}
    		double pi=0;
    		fread(&pi,sizeof(double),1,file1);
    		remove("file1.txt");
    		
    		FILE *file2=fopen("file2.txt","r");
    		if(file2==NULL){
    			printf("ndeu\n");
    			return 3;
    		}
    		double pi2=0;
    		fread(&pi2,sizeof(double),1,file2);
    		remove("file2.txt");
    		
    		
    		pi = (pi*2)+(pi2*2);
    		printf("O valor de pi eh: %f\n",pi);
        }
	}

	return EXIT_SUCCESS;
}
