#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include<dos.h>
#include<fstream.h>
#include<string.h>
#include<stdio.h>
#include<math.h>
void drawPlane(int color, int coordinates, int *x1,int *x2,int *y1,int *y2)
{	setcolor(color);
	for(int i=0;i<coordinates;i++)
		line(x1[i],y1[i],x2[i],y2[i]);

}
void main()
{
	clrscr();
	int gd=DETECT, gm;
	initgraph(&gd,&gm,"c:/turboc3/bgi");
	settextstyle(8,0,4);
	outtextxy(10,10,"Countermeasure Dispensing System");


	//ifstream fin("file.txt",ios::out);
	FILE *fp;
	fp=fopen("file.txt","r+");
	int i,j,chaffType;
	float newval,c[13]={0.0};
	int count[13]={0};
	//while(!fin.eof())
	while(!feof(fp))
	//for(int k1=0;k1<=9;k1++)
	{
		fscanf(fp,"%d%f",&chaffType,&newval);
		//fin>>chaffType>>newval;
		//cout<<chaffType<<" "<<newval<<endl;
		c[chaffType]=(c[chaffType]*count[chaffType]+newval)/(count[chaffType]+1);
		count[chaffType]++;
		//delay(1000);
	}
	fclose(fp);
	//cout<<"Final Values: ";
	//for(int k=1;k<=12;k++)
		//cout<<"chaffType: "<<k<<" average: "<<c[k];
	//cout<<endl;

		//plane
	//arc(300,150,0,180,30);
	int coordinates=13;
	//int x1[coordinates],y1[coordinates],x2[coordinates],y2[coordinates];
	int x1[]={270,330,270,330,285,315,260,272,275,220,328,325,380};
	int y1[]={150,150,150,150,250,250,270,170,200,170,170,200,170};
	int x2[]={300,300,285,315,260,340,340,220,240,240,380,360,360};
	int y2[]={120,120,250,250,270,270,270,170,190,190,170,190,190};

	int xb1[20], xb2[20];
	int yb1[20], yb2[20];
	for(i=0;i<coordinates;i++)
	{	xb1[i]=x1[i];
		xb2[i]=x2[i];
		yb1[i]=y1[i];
		yb2[i]=y2[i];
	}

	//setcolor(3);
	//for(i=0;i<coordinates;i++)
	//	line(x1[i],y1[i],x2[i],y2[i]);
	drawPlane(3,13,x1,x2,y1,y2);
	delay(1000);
	/*setcolor(0);
	for(i=0;i<coordinates;i++)
		line(x1[i],y1[i],x2[i],y2[i]);
	*/
	setcolor(WHITE);

	//chaff
	delay(100);
	int width=10, height=10, baseline=350, baselineX1=480, baselineY1=150;
	line(baselineX1,baselineY1,baselineX1-10,baselineY1-10);
	line(baselineX1-10,baselineY1-10,baselineX1-10,(baselineY1-10)+(5*height));
	line(baselineX1-10,(baselineY1-10)+(5*height),baselineX1,baselineY1+(height*5));
	line(baselineX1-10,baselineY1-10,(baselineX1-10)+(width*12),baselineY1-10);
	line((baselineX1-10)+(width*12),baselineY1-10,baselineX1+(12*width),baselineY1);

	for(baseline=baselineY1;baseline<baselineY1+5*width;baseline+=height)
	{	for(int x1=baselineX1;x1<baselineX1+12*width;x1+=width)
		{	setfillstyle(SOLID_FILL,RED);
			rectangle(x1,baseline,x1+width,baseline+height);
			floodfill(x1+1,baseline+1,WHITE);
		}
	}


	float freq= 100;
	char type [12];
	int flag =0;
	int chaff[12]={0};
	int loc;
	while(1)
	{	
		ifstream fin("file1.txt",ios::in|ios::out);
		delay(1000);
		//cout<<"file opened ..";
		//while(!fin.eof())
		{	fin>>freq>>loc;
			//cout<<"Freq="<<freq<<" ";
		}
		fin.close();
		//freq=2.0;
		//loc=1;
		if(freq==0.0)
		     continue;
		//cout<<"File closed..";
		if(freq>=0.1)
		{       FILE *fp2;
			fp2=fopen("file1.txt","w+");
			//ofstream fout("file1.txt",ios::in|ios::out);
			fprintf(fp2,"0.0 0");
			//fout<<0.0000;
			//fout.close();
			fclose(fp2);
			if(freq>=18.0 || loc>=3)
				exit(0);

		//flag=freq*2;
		flag=100;
		float d=0.0,minD=100.0;
		for(int k=1;k<=12;k++)
		{       //flag=100;
			if(c[k]!=0)
			{       //cout<<"c["<<k<<"]:"<<c[k]<<" freq:"<<freq;
				if(c[k]>freq)
					d=c[k]-freq;
				else
					d=freq-c[k];

				//d=abs(c[k]-freq);
				//cout<<" d:"<<d<<endl;
				if(d<minD)
				{	minD=d;
					flag=k;
				}
			}

			//cout<<"c["<<k<<"]: "<<c[k]<<" Flag: "<<flag<<endl;
		}
		//cout<<freq<<" "<<flag<<endl;
		//cout<<"Flag="<<flag<<"..\n";

		freq=flag;
		if(chaff[freq-1]>4)
			cout<<"No Chaff available for this range";
		else
		{	delay(1000);
			setfillstyle(SOLID_FILL,YELLOW);
			//rectangle(x1+width*flag/2,150,160,210);
			floodfill(baselineX1+width*(freq-1)+1,baselineY1+height*chaff[freq-1]+1,WHITE);
			chaff[freq-1]++;
		}
		}
		int lShift=160,rShift=65;
		if(loc==1)
		{

			/*setcolor(0);
			for(i=0;i<coordinates;i++)
				line(x1[i],y1[i],x2[i],y2[i]);
			*/
			drawPlane(0,13,x1,x2,y1,y2);
			
			//setcolor(0);
			//for(i=0;i<coordinates;i++)
			//	line(x1[i]-160,y1[i],x2[i]-160,y2[i]);
			int cx=300,cy=210;
			float a=1.0; //=b*180*7/22;
			//printf("b=%d a=%f\n",b,a);

			//setcolor(0);
			//for(i=0;i<coordinates;i++)
			//	line(x1[i]+65,y1[i],x2[i]+65,y2[i]);

			int tempX1,tempX2,tempY1,tempY2;
			for(i=0;i<coordinates;i++)
			{	tempX1=(((x1[i]-cx)*cos(a))-((y1[i]-cy)*sin(a)))+cx;
				tempY1=(((x1[i]-cx)*sin(a))+((y1[i]-cy)*cos(a)))+cy;
				tempX2=(((x2[i]-cx)*cos(a))-((y2[i]-cy)*sin(a)))+cx;
				tempY2=(((x2[i]-cx)*sin(a))+((y2[i]-cy)*cos(a)))+cy;
				x1[i]=tempX1+rShift;
				y1[i]=tempY1;
				x2[i]=tempX2+rShift;
				y2[i]=tempY2;
			}
			drawPlane(4,coordinates,x1,x2,y1,y2);
			//setcolor(4);
			//for(i=0;i<coordinates;i++)
				//line(x1[i]+65,y1[i],x2[i]+65,y2[i]);
			int color=0;
			for(int i=getmaxy();i>=0;i--)
			{
				//color=getpixel(i,i);
				//putpixel(i,i,WHITE);
				//delay(50);
				//putpixel(i,i,color);
				setcolor(3);
				setfillstyle(SOLID_FILL,9);
				circle(i,i,1);
				floodfill(i+2,i+2,3);
				delay(3);
				setcolor(0);
				setfillstyle(SOLID_FILL,0);
				circle(i,i,5);
				floodfill(i+2,i+2,3);
				//cleardevice();

			}
			/*setcolor(3);
			for(i=0;i<coordinates;i++)
				line(x1[i],y1[i],x2[i],y2[i]);*/

		}
	else if(loc==2)
	{
		/*setcolor(0);
		for(i=0;i<coordinates;i++)
			line(x1[i],y1[i],x2[i],y2[i]);
		*/
		drawPlane(0,13,x1,x2,y1,y2);

		/*setcolor(0);
		for(i=0;i<coordinates;i++)
		{	x1[i]=x1[i]+65;
			x2[i]=x2[i]+65;
		}
		for(i=0;i<coordinates;i++)
			line(x1[i],y1[i],x2[i],y2[i]);
		*/
		int cx=300,cy=210;
		float a=-1.0; //=b*180*7/22;
		//printf("b=%d a=%f\n",b,a);

		/*setcolor(0);
		for(i=0;i<coordinates;i++)
			line(x1[i]-160,y1[i],x2[i]-160,y2[i]);
		*/
		int tempX1,tempX2,tempY1,tempY2;
		for(i=0;i<coordinates;i++)
		{	tempX1=(((x1[i]-cx)*cos(a))-((y1[i]-cy)*sin(a)))+cx;
			tempY1=(((x1[i]-cx)*sin(a))+((y1[i]-cy)*cos(a)))+cy;
			tempX2=(((x2[i]-cx)*cos(a))-((y2[i]-cy)*sin(a)))+cx;
			tempY2=(((x2[i]-cx)*sin(a))+((y2[i]-cy)*cos(a)))+cy;
			x1[i]=tempX1-lShift;
			y1[i]=tempY1;
			x2[i]=tempX2-lShift;
			y2[i]=tempY2;
		}
		/*setcolor(4);
		for(i=0;i<coordinates;i++)
			line(x1[i]-160,y1[i],x2[i]-160,y2[i]);
		*/
		drawPlane(4,coordinates,x1,x2,y1,y2);
		
		//int color=0;
		for(int i=getmaxy();i>=0;i--)
		{
			setcolor(3);
			setfillstyle(SOLID_FILL,9);
			circle(getmaxy()-i,i,1);
			floodfill(getmaxy()-i-2,i+2,3);
			delay(3);
			setcolor(0);
			setfillstyle(SOLID_FILL,0);
			circle(getmaxy()-i,i,5);
			floodfill(getmaxy()-i-2,i+2,3);


		}

	}
       /*setcolor(3);
	for(i=0;i<coordinates;i++)
		line(x1[i],y1[i],x2[i],y2[i]);   */


	drawPlane(0,coordinates,x1,x2,y1,y2);
	for(i=0;i<coordinates;i++)
	{	x1[i]=xb1[i];
		x2[i]=xb2[i];
		y1[i]=yb1[i];
		y2[i]=yb2[i];
	}
	drawPlane(0,coordinates,x1,x2,y1,y2);
	
	}
	
getch();
}
