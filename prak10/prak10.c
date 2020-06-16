#include <stdio.h>
#include <stdlib.h>

void getMatrix()
{
	int matrix[10][10];
	int jmlh, y, x, x2=1, y2=1;
	char jwb[3];
	
	do{
		printf("How Many Vertices ? <Max=10> : ");
		scanf("%d",&jmlh);
		fflush(stdin);			
	}
	while (jmlh<1||jmlh>10);
	printf("\n");
	
	for(y = 1; y < jmlh+1; y++){
		for(x = 1; x < jmlh+1; x++){
			if(x!=y){
				do{
					printf("Vertices %d & %d are Adjacent ? <Y/N> : ", y, x);
					fflush(stdin);
					scanf("%s",jwb);
				}
				while(strcmp(jwb,"Y")!=0&&strcmp(jwb,"y")!=0&&strcmp(jwb,"N")!=0&&strcmp(jwb,"n")!=0);
				fflush(stdin);
				if(strcmp(jwb,"y")!=1||strcmp(jwb,"Y")!=1)
				{
					matrix[x][y]=1;
				}				
				
				if(strcmp(jwb,"N")==0||strcmp(jwb,"n")==0)
				{
					matrix[x][y]=0;
				}
				fflush(stdin);
			}
		}
	}
	
	printf("\n\nAdjecency Matrix of This Graph\n");
	printf("------------------------------\n");
	printf("Vertex   ");
	while(x2!=jmlh+1){
		printf("%d ",x2);
		x2++;
	};
	printf("\n");
	
	for(y2 = 1; y2 < jmlh+1; y2++){
		printf("%6d   ",y2);
		for(x2 = 1; x2 < jmlh+1; x2++){
			if(x2!=y2){
				printf("%d ",matrix[x2][y2]);
			}
			else{
				printf("0 ");
			}
		}
		printf("\n");
	};
	
	getch();
};

void getDegree()
{
	int ot[10], in[10];
	int jmlh, y, x, z=1;
	char jwb[3];
	
	do{
		printf("How Many Vertices ? <Max=10> : ");
		scanf("%d",&jmlh);
		fflush(stdin);			
	}
	while (jmlh<1||jmlh>10);
	printf("\n");
	
	for(y=1;y<11;y++){
		for(x=1;x<11;x++){
			ot[y]=0;
			in[x]=0;
		}
	}

	
	for(y = 1; y < jmlh+1; y++){
		for(x = 1; x < jmlh+1; x++){
			if(x!=y){
				do{
					printf("Vertices %d & %d are Adjacent ? <Y/N> : ", y, x);
					fflush(stdin);
					scanf("%s",jwb);
				}
				while(strcmp(jwb,"Y")!=0&&strcmp(jwb,"y")!=0&&strcmp(jwb,"N")!=0&&strcmp(jwb,"n")!=0);
				fflush(stdin);
				if(strcmp(jwb,"y")!=1||strcmp(jwb,"Y")!=1)
				{
					ot[y]=ot[y]+1;
					in[x]=in[x]+1;
				}				
				
				if(strcmp(jwb,"N")==0||strcmp(jwb,"n")==0)
				{
					ot[y]=ot[y]-1;
					in[x]=in[x]-1;
				}
				fflush(stdin);
			}
			else if(x==y){
				ot[y]=ot[y];
				in[x]=in[x];
			}
		}
	}
	
	printf("\n\nVertex \t\t In_Degree \t\t Out_Degree \t\t Total_Degree\n");
	while(z!=jmlh+1){
		printf("%4d \t\t %6d \t\t %6d \t\t %6d",z ,in[z] ,ot[z], in[z]+ot[z] );
		printf("\n");
		z++;
	};
	getch();
}


int main()
{
	int menu;
	do{
		menu=0;
		system("cls");
		fflush(stdin);
		printf("Directed Graph Representation\n");
		printf("=============================\n\n");
		printf("1. Show Adjacency Matrix\n");
		printf("2. Show Degree of all vertices\n");
		printf("3. Exit\n\n");
		printf(">> Input your choice : ");
		scanf("%d",&menu);
		fflush(stdin);
		printf("\n\n");
		switch(menu)
		{
			default :
				{
					printf("Pilih Menu Yang Tersedia");
					getch();
					break;
				}
			case(1) :
				{
					getMatrix();
					break;
				}
			case(2) :
				{
					getDegree();
					break;
				}
			case(3) :
				{
					getch();
					break;
				}
			}
	}while(menu!=3);
	return 0;
}
