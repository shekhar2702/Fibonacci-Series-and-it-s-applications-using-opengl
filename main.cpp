#include <GL/glut.h>
#include<stdio.h>
#include<iostream> //for cin/cout
#include<vector> //for vectors
#include<ctime> //for time
#include<cstdlib> //for rand()
#include<math.h>
#include<string.h>
#include<stdlib.h>
void *currentfont;
#define size1 7
#define MAX 10
#define PI 3.141593


using namespace std;
static int window, window2;
static int menu_id;
static int submenu_id;
static int value = 0;
int disp2=0;
int rectd=0;
int gend=0;
int fpaged=0;
int fkey=0;

char line1[] = {"JSS ACADEMY OF TECHNICAL EDUCATION"};
char line2[] = {"Computer Science Department"};
char line3[] = {"   Computer Graphics Project"};
char line4[] = {"TOPIC: Fibonacci and Golden Sections in Nature"};
char line5[] = {"Somya Shekhar	 : 1JS16CS103"};
char line6[] = {"Shubham : 1JS16CS099"};
char line7[] = {"(Right Click for Options)"};
//End of global declarations


void instruction();

void displayText( float x, float y, int r, int g, int b, const char *string ) {
    int j = strlen (string);
    glColor3f( r, g, b );
    glRasterPos2f( x, y );
    for( int i = 0; i < j; i++ )
        glutBitmapCharacter( GLUT_BITMAP_TIMES_ROMAN_24, string[i] );
    glFlush();
}

void displayfirst(void){
    glClear(GL_COLOR_BUFFER_BIT);
    displayText(400, 450, 0, 0, 1,line1);
    displayText(470, 400, 1, 1, 1,line2);
    displayText(470, 350, 1, 1, 1,line3);
    displayText(80, 150, 0, 1, 1,line4);
    displayText(80, 100, 1, 0.3, 0.5,line5);
    displayText(80, 50, 1, 0.3, 0.5,line6);
    displayText(850,20,0,1,0,line7);

}


//DC CODE
int p=310,i=0,fnum=0;
int num[5]={0,0,0,0}; int count=0;

void restart()
{

    for(i=0;i<5;i++)
        num[i]=0;
}


void stri(char *p,int n,GLint x,GLint y)
{
    glColor3f(1,0.7,0.3);
    glRasterPos2f(x,y);
    for(int i=0;i<n;i++)
        glutBitmapCharacter( GLUT_BITMAP_TIMES_ROMAN_24 , p[i] );
}

void delay()
{
    for(int i=0;i<35000;i++)
        for(int j=0;j<5000;j++);
}

void placeval(){
    int j=0;
    fnum=0;
    for(j=i;j>=0;j--)
    {
        if(j==0&&i==4)
            fnum+=num[j]*10000;
        else if(j==0&&i==3)
            fnum+=num[j]*1000;
        else if(j==0&&i==2)
            fnum+=num[j]*100;
        else if(j==0&&i==1)
            fnum+=num[j]*10;
        else if(j==0&&i==0)
            fnum+=num[j];

        else if(j==1&&i==4)
            fnum+=num[j]*1000;
        else if(j==1&&i==3)
            fnum+=num[j]*100;
        else if(j==1&&i==2)
            fnum+=num[j]*10;
        else if(j==1&&i==1)
            fnum+=num[j];

        else if(j==2&&i==4)
            fnum+=num[j]*100;
        else if(j==2&&i==3)
            fnum+=num[j]*10;
        else if(j==2&&i==2)
            fnum+=num[j];

        else if(j==3&&i==4)
            fnum+=num[j]*10;
        else if(j==3&&i==3)
            fnum+=num[j];

        else if(j==4&&i==4)
            fnum+=num[j];
    }
        cout<<"\n"<<fnum;
}

void itoc(int integer){
     int temp,count=0,in,cnd=0;
     char ascii[10]={0};
     if(integer>>31)
     {
     /*CONVERTING 2's complement value to normal value*/
     integer=~integer+1;
     for(temp=integer;temp!=0;temp/=10,count++);
     ascii[0]=0x2D;
     count++;
     cnd=1;
     }
     else
     for(temp=integer;temp!=0;temp/=10,count++);
     for(in=count-1,temp=integer;in>=cnd;in--)
     {

        ascii[in]=(temp%10)+0x30;
        temp/=10;
     }
     printf("\nAscii=%s ",ascii);
     in=0,p=360;
     while(ascii[in]!='\0'){
        char q=ascii[in];
        stri(&q,1,p,375-(30*4));
        p+=15;
        in++;
     }

}

//Prints the characters on screen at x,y
void strin(char *p,int n,GLint x,GLint y)
{
    glRasterPos2f(x,y);
    for(int i=0;i<n;i++)
        glutBitmapCharacter( GLUT_BITMAP_9_BY_15 , p[i] );
}

void constr() // To show the constraints
{
    glClearColor(1.0,1.0,1.0,0.0);

    int p=15,q=200;
    glColor3f(1.0,0.0,0.0);
    strin("Conversion Example:",19,p,q);
    strin("___________________",20,p,q-4);
    strin("Number 100 can be expressed as a sum of Fibonacci numbers 89 + 8 + 3.",72,p,q-(30*1));
    strin("Now, the Fibonacci number following 89 is 144.",48,p,q-(30*2));
    strin("The Fibonacci number following 8 is 13.",40,p,q-(30*3));
	strin("The Fibonacci number following 3 is 5.",40,p,q-(30*4));
	strin("Therefore the answer is 144 + 13 + 5 = 162 kilometers in 100 miles.",67,p,q-(30*5));
	strin("This is within 1% of the precise answer, which is 160.93 km.",60,p,q-(30*6));
}

void init1()
{
    //glClearColor(1,1,1,0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0,0,0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluOrtho2D(0,1200,0,500);
}//Initialisation

void valfetch()
{
    init1();
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    stri("Enter the value in Miles: ",25,15,375);
    stri("(Maximum 5 digit Number Allowed)",32,15,375-(30*1));
    constr();
    glFlush();
}

void ans()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    stri(">>> Given Miles Consist of ",27,15,375-(30*4));
    glFlush();
}

void restart1(){
     /*glClear(GL_COLOR_BUFFER_BIT);
                valfetch();
                glFlush();*/
                glColor3f(1, 1, 1);
                strin("ERROR", 5, 15, 375-(30*2));
                strin("Upto 4 digit numbers only allowed.", 34, 15, 375-(25*3));
                restart();
                i=0,p=385;
                glFlush();
                delay();
                //glClear(GL_COLOR_BUFFER_BIT);
                glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
                valfetch();
                delay();
}


void restart2(){
     /*glClear(GL_COLOR_BUFFER_BIT);
                valfetch();
                glFlush();*/
                //glColor3f(1, 1, 1);
                //strin("ERROR", 5, 15, 375-(30*2));
                //strin("Upto 4 digit numbers only allowed.", 34, 15, 375-(25*3));
                restart();
                i=0,p=385;
                glFlush();
                delay();
                //glClear(GL_COLOR_BUFFER_BIT);
                glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
                valfetch();
                delay();
}



void key(unsigned char key, int mx, int my){

    p+=15;
    char a=key;
    int n=a-'0';


    if(isdigit(key)){

        if(fkey==0){
             i=0;
             cout<<"i reset";
             fkey=1;
            }

        if(i<4)
            {
                stri(&a,1,p,375);
                i++;
                num[i]=n;
                cout<<num[i]<<"\n";
                glFlush();
            }
         else{
               restart1();
         }
    }
                if(a=='e'){
                    cout<<"ok";
                    placeval();
                    ans();
                    int ans= fnum*(1.618);
                    char an=ans;
                    cout<<"\n"<<ans;
                    itoc(ans);
                    stri("kms         Error[sqrt(n)0.5%]",31,p+5,375-(30*4));
                    restart();
                    i=0,p=385;
                    glFlush();

                }

                if(a=='r'){

                    restart2();
                }
}



// GENERATOR CODE HERE
class button
{
	int x1,y1,x2,y2;
	int state;
	char str[10];

public:
	button()
	{

	}
	button(int x11,int y11,int x22,int y22,char *str1)
	{
		x1=x11;
		y1=y11;
		x2=x22;
		y2=y22;
		state=1;
		strcpy(str,str1);
	}
	void draw();
	void togglestate();
	int insidebutton(int x,int y);
};
class fib
{
   button s[size1];
   int top;

public:
   fib()
   {
	   top=-1;
   }
   int stfull();
   button pop();
   void push(int item);
   int stempty();
   void displayfib();
};
fib st;

void setFont(void *font)
{
	currentfont=font;
}
void drawstring(float x,float y,char *string)
{
    char *c;
	glRasterPos2f(x,y);

	for(c=string;*c!='\0';c++)
	{	glColor3f(0.0,0.0,0.0);
		glutBitmapCharacter(currentfont,*c);
	}
}
void button::draw()
{
	setFont(GLUT_BITMAP_HELVETICA_18);
	glColor3f(1.0,1.0,1.0);
    drawstring(x1+10,y1+10,str);
	glColor3f(0.3,0.7,0.4);
	glLineWidth(1.0);
	glBegin(GL_POLYGON);
	glVertex2f(x1,y1);
	glVertex2f(x2,y1);
	glVertex2f(x2,y2);
	glVertex2f(x1,y2);
	glEnd();
	if(state==0)
	{
	glColor3f(0,0,0);
	glBegin(GL_LINES);
	glVertex2f(x1,y1);
	glVertex2f(x2,y1);
	glVertex2f(x2,y1);
	glVertex2f(x2,y2);
	glEnd();
	}
	else if(state==1)
	{
		glColor3f(0,0,0);
		glBegin(GL_LINES);
		glVertex2f(x1,y1);
		glVertex2f(x1,y2);
		glVertex2f(x1,y2);
		glVertex2f(x2,y2);
		glEnd();
	}
}
void button::togglestate(void)
{
	/*if(state==1)
		state=0;
	else if(state==0)
		state=1;*/
	state=(state==1)?0:1;
}
int button::insidebutton(int x,int y)
{
	if(x>x1&&x<x2&&y>y1&&y<y2)
		return 1;
	else return 0;
}
button btn1(175,100,275,150,"Generate");
button btn2(325,100,425,150,"Delete");
//
// Stack functions start
//
int fib::stfull() {
   if (st.top >= size1-1)
      return 1;
   else
      return 0;
}

void fib::push(int item) {
	char str[10];

	snprintf(str, sizeof(str), "%d", item);
    button btn(175,250+st.top*50,425,300+st.top*50,str);
	st.top++;

   st.s[st.top] = btn;

}

int fib::stempty() {
   if (st.top == -1)
      return 1;
   else
      return 0;
}

button fib::pop() {
   button item;
   item = st.s[st.top];
   st.top--;

   return (item);
}

void fib::displayfib() {
   int i;

      drawstring(10,40,"Click Generate for FIBONACCI SERIES!");
      drawstring(10,10,"(Display Limit:7, Delete to Gen. More Series.)!");

      for (i = st.top; i >= 0; i--)
    	  st.s[i].draw();

}
//
//stack functions end
//
//
void init(){

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,960,0,640);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

}

void generator()
{
	glClearColor(1.0,1.0,1.0,0.0);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    init();
    glEnable(GL_DEPTH_TEST);
    btn1.draw();
    btn2.draw();
    st.displayfib();
    glFlush();
    glutSwapBuffers();
//glutPostRedisplay();
}

//Bezier Curve

//Point class for taking the points
class Point {
public:
    float x, y;
    void setxy(float x2, float y2)
    {
        x = x2; y = y2;
    }
    //operator overloading for '=' sign
    const Point & operator=(const Point &rPoint)
    {
        x = rPoint.x;
        y = rPoint.y;
        return *this;
    }

};

int factorial(int n)
{
    if (n<=1)
        return(1);
    else
        n=n*factorial(n-1);
    return n;
}

float binomial_coff(float n,float k)
{
    float ans;
    ans = factorial(n) / (factorial(k)*factorial(n-k));
    return ans;
}




Point abc[20];
int SCREEN_HEIGHT = 640;
int points = 0;
int clicks = 4;


void myInit() {
    glClearColor(1.0,1.0,1.0,0.0);
    glColor3f(0.0,0.0,0.0);
    glPointSize(3);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluOrtho2D(0.0,960.0,0.0,640.0);

}

void drawDot(int x, int y) {
    glBegin(GL_POINTS);
     glVertex2i(x,y);
    glEnd();
    glFlush();
}

void drawLine(Point p1, Point p2) {
    glBegin(GL_LINES);
      glVertex2f(p1.x, p1.y);
      glVertex2f(p2.x, p2.y);
    glEnd();
    glFlush();
}


//Calculate the bezier point
Point drawBezier(Point PT[], double t) {
    Point P;
    P.x = pow((1 - t), 3) * PT[0].x + 3 * t * pow((1 -t), 2) * PT[1].x + 3 * (1-t) * pow(t, 2)* PT[2].x + pow (t, 3)* PT[3].x;
    P.y = pow((1 - t), 3) * PT[0].y + 3 * t * pow((1 -t), 2) * PT[1].y + 3 * (1-t) * pow(t, 2)* PT[2].y + pow (t, 3)* PT[3].y;

    return P;
}


//Calculate the bezier point [generalized]
Point drawBezierGeneralized(Point PT[], double t) {
    Point P;
    P.x = 0; P.y = 0;
    for (int i = 0; i<clicks; i++)
    {
        P.x = P.x + binomial_coff((float)(clicks - 1), (float)i) * pow(t, (double)i) * pow((1 - t), (clicks - 1 - i)) * PT[i].x;
        P.y = P.y + binomial_coff((float)(clicks - 1), (float)i) * pow(t, (double)i) * pow((1 - t), (clicks - 1 - i)) * PT[i].y;
    }
    //cout<<P.x<<endl<<P.y;
    //cout<<endl<<endl;
    return P;
}


void myDisplay() {
    //glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}



//Bezier Curve End

void mouse(int button, int state, int x, int y)
{
    static int itemno=0, itemno1=1,flag1=0;
	y=640-y;
	if(button==GLUT_MIDDLE_BUTTON && state == GLUT_DOWN)
	{
	if(btn1.insidebutton(x,y))
	{
		btn1.togglestate();

		if(!st.stfull()){
		    if(flag1 == 0){
                st.push(itemno);
                flag1 = 1;
		    }
            int newitem=itemno+itemno1;
			st.push(newitem);
			itemno=itemno1;
			itemno1=newitem;

		}
	}
	if(btn2.insidebutton(x,y))
		{
			btn2.togglestate();
			if(!st.stempty())
					st.pop();

		}
	}
	if(button==GLUT_MIDDLE_BUTTON && state == GLUT_UP)
	{
		if(btn1.insidebutton(x,y))
			{
				btn1.togglestate();
			}
		if(btn2.insidebutton(x,y))
            {
				btn2.togglestate();
			}
	glutPostRedisplay();
    }


	//FOR GS

	 // If left button was clicked
  if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
    // Store where mouse was clicked, Y is backwards.
    abc[points].setxy((float)x,(float)(y));
    points++;

    // Draw the red  dot.
    myInit();
    drawDot(x, y);


    // If (click-amout) points are drawn do the curve.
    if(points == clicks)
    {
        glColor3f(0.0,0.0,0.0);
        glLineWidth(2);
        // Drawing the control lines
        //for(int k=0;k<clicks-1;k++)
            //drawLine(abc[k], abc[k+1]);

        Point p1 = abc[0];
        /* Draw each segment of the curve.Make t increment in smaller amounts for a more detailed curve.*/
        for(double t = 0.0;t <= 1.0; t += 0.02)
        {
            Point p2 = drawBezierGeneralized(abc,t);
            cout<<p1.x<<"  ,  "<<p1.y<<endl;
            cout<<p2.x<<"  ,  "<<p2.y<<endl;
            cout<<endl;


            drawLine(p1, p2);
            p1 = p2;
        }
        glColor3f(0.0,0.0,0.0);

        points = 0;
    }
  }


}

/*void idle()
{
	glutPostRedisplay();
}
*/


//Fibonacci Clock


// all 5 square co-ordinates
float sc[5][4] = { -0.5f, 0.2f, -0.25f, 0.6f,
-0.5f, 0.6f, -0.25f, 1.0f,
-1.0f, 0.2f, -0.5f, 1.0f,
-1.0f, -1.0f, -0.25f, 0.2f,
-0.25f, -1.0f, 1.0f, 1.0f };
int nr=0; //no repeat color

//prints rectangle
void rect(float x1, float y1, float x2, float y2)
{
	glBegin(GL_POLYGON);
	glVertex2f(x1, y1);
	glVertex2f(x2, y1);
	glVertex2f(x2, y2);
	glVertex2f(x1, y2);
	glEnd();
}

// All 5 fibonacci numbers
int fib[5] = { 1, 1, 2, 3, 5 }, j, hours, minutes;
// All possible value from fibonacci numbers stored in this vector(values)
vector <vector<int> > values[13];
// Tells which value to choose for hour and minute
vector <int> h, m;
// Marks values to be taken
bool hp[5], mp[5];

// Finds color according to state of block(hour,minute)
void color1(bool h, bool m)
{
	if (h && m) glColor3f(0.0f, 0.0f, 1.0f); //Blue
	else if (h) glColor3f(1.0f, 0.0f, 0.0f); //Red
	else if (m) glColor3f(0.0f, 1.0f, 0.0f); //Green
	else glColor3f(1.0f, 1.0f, 1.0f); //White
}

void fibc()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
	glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer
    glDisable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// Takes hours and minutes from local time
	time_t t = time(NULL);
	struct tm *tmp = localtime(&t);
	hours = tmp->tm_hour;
	minutes = tmp->tm_min / 5;
	if (hours > 12) hours -= 12;
	cout << hours << ":" << minutes * 5 << endl;

	//Randomly takes possible indexes for hour and minutes and marks them
	srand(time(NULL));
	h = values[hours][rand() % values[hours].size()];
	m = values[minutes][rand() % values[minutes].size()];
	//Marks them
	for (i = 0; i < 5; i++) hp[i] = mp[i] = false;
	for (auto i : h) hp[i] = true;
	for (auto i : m) mp[i] = true;


	color1(hp[0], mp[0]);
	rect(sc[0][0], sc[0][1], sc[0][2], sc[0][3]);

	color1(hp[1], mp[1]);
	rect(sc[1][0], sc[1][1], sc[1][2], sc[1][3]);

	color1(hp[2], mp[2]);
	rect(sc[2][0], sc[2][1], sc[2][2], sc[2][3]);

	color1(hp[3], mp[3]);
	rect(sc[3][0], sc[3][1], sc[3][2], sc[3][3]);

	color1(hp[4], mp[4]);
	rect(sc[4][0], sc[4][1], sc[4][2], sc[4][3]);


	//LINES
	glLineWidth(2.5);
	glColor3f(0.0, 0.0, 0.0);

	glBegin(GL_LINES);
	glVertex3f(sc[2][0], sc[2][1], 0.0);
	glVertex3f(sc[3][2], sc[3][3], 0);
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(sc[4][0], sc[4][1], 0.0);
	glVertex3f(sc[4][0], sc[1][3], 0);
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(sc[0][0], sc[0][1], 0.0);
	glVertex3f(sc[2][2], sc[2][3], 0);
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(sc[1][0], sc[1][1], 0.0);
	glVertex3f(sc[0][2], sc[0][3], 0.0);
	glEnd();

	//Border Lines
	glLineWidth(5.5);

	glBegin(GL_LINES);
	glVertex3f(-1.0, 1.0, 0.0);
	glVertex3f(1.0, 1.0, 0);
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(1.0, 1.0, 0.0);
	glVertex3f(1.0, -1.0, 0);
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(-1.0, 1.0, 0.0);
	glVertex3f(-1.0, -1.0, 0);
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(-1.0, -1.0, 0.0);
	glVertex3f(1.0, -1.0, 0);
	glEnd();

	glFlush();  // Render now
	Sleep(2000);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glutPostRedisplay();
}



//Golden Spiral

void color()
{
	if (nr==0){
		glColor3f(0.0f, 0.0f, 1.0f); //Blue
		nr++;
	}
	else if (nr==1){
		glColor3f(1.0f, 0.0f, 0.0f); //Red
		nr++;
	}
	else if (nr==2){
		glColor3f(0.0f, 1.0f, 0.0f); //Green
		nr++;
	}
	else if (nr==3){
		glColor3f(0.7f, 0.7f, 0.3f); //Green
		nr++;
	}
	else{
		glColor3f(0.6f, 0.7f, 0.7f); //White
		nr=0;
	}
}

void gs()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
	glClear(GL_COLOR_BUFFER_BIT);// Clear the color buffer
    glDisable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();


	color();
	rect(sc[0][0], sc[0][1], sc[0][2], sc[0][3]);

	color();
	rect(sc[1][0], sc[1][1], sc[1][2], sc[1][3]);

	color();
	rect(sc[2][0], sc[2][1], sc[2][2], sc[2][3]);

	color();
	rect(sc[3][0], sc[3][1], sc[3][2], sc[3][3]);

	color();
	rect(sc[4][0], sc[4][1], sc[4][2], sc[4][3]);


	//LINES
	glLineWidth(2.5);
	glColor3f(0.0, 0.0, 0.0);

	glBegin(GL_LINES);
	glVertex3f(sc[2][0], sc[2][1], 0.0);
	glVertex3f(sc[3][2], sc[3][3], 0);
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(sc[4][0], sc[4][1], 0.0);
	glVertex3f(sc[4][0], sc[1][3], 0);
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(sc[0][0], sc[0][1], 0.0);
	glVertex3f(sc[2][2], sc[2][3], 0);
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(sc[1][0], sc[1][1], 0.0);
	glVertex3f(sc[0][2], sc[0][3], 0.0);
	glEnd();

	//Border Lines
	glLineWidth(5.5);

	glBegin(GL_LINES);
	glVertex3f(-1.0, 1.0, 0.0);
	glVertex3f(1.0, 1.0, 0);
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(1.0, 1.0, 0.0);
	glVertex3f(1.0, -1.0, 0);
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(-1.0, 1.0, 0.0);
	glVertex3f(-1.0, -1.0, 0);
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(-1.0, -1.0, 0.0);
	glVertex3f(1.0, -1.0, 0);
	glEnd();

	glFlush();  // Render now

}



// Menu

void menu(int num){
    if(num == 0){
        glutDestroyWindow(window);
        exit(0);
    }
    else{
        value = num;
        printf("%d",value);
        glutPostRedisplay();
    }

}
void createMenu(void){
 submenu_id = glutCreateMenu(menu);
 glutAddMenuEntry("Distance Converter", 2);
 glutAddMenuEntry("Golden Spiral", 3);
 glutAddMenuEntry("Fibonacci Clock", 4);

 menu_id = glutCreateMenu(menu);
 glutAddMenuEntry("Series Generator", 1);
 glutAddSubMenu("Golden Spiral & Applications", submenu_id);
 glutAddMenuEntry("Quit", 0);

glutAttachMenu(GLUT_RIGHT_BUTTON);
}
void display(void){

    if(fpaged==0){
        init1();
        displayfirst();
        fpaged=1;
        glFlush();
    }
    //glClear(GL_COLOR_BUFFER_BIT);


    if(value == 1)
    {
        generator();
        rectd=0;
        instruction();
    }
    else if(value == 2)
    {
        valfetch();
        rectd=0;
        instruction();

    }
    else if(value == 3 && rectd == 0)
    {
        gs();
        rectd=1;
        instruction();

    }
    else if(value == 4){
        fibc();
        rectd=0;
        instruction();
    }
    glFlush();
}

//Second Window

void disp2init()
{
    //glClearColor(1,1,1,0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0,0,0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluOrtho2D(0,300,0,640);
}

void instruction(){
    glutSetWindow(window2);
    disp2init();
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);


    if(value == 1)
    {
        stri("Mouse Functionalities: ",23,15,375+(30*4));
        stri("-----------------",17,15,375+(30*3));
        stri("Use middle mouse button on",26,15,375);
        stri("Generate & Delete options,",25,15,375-(30*1));

        stri("To perform respective",21,15,375-(30*2));
        stri("operations.",11,15,375-(30*3));
        glFlush();

    }

    if(value == 2)
    {
        stri("Key Functionalities: ",21,15,375+(30*4));
        stri("---------------",15,15,375+(30*3));
        stri("-> Press 'e' to Continue.",25,15,375);
        stri("      (To Register Input)",25,15,375-(30*1));
        stri("-> Press 'r' to Reset",21,15,375-(30*3));
        stri("      Window.",13,15,375-(30*4));
        glFlush();

    }
    else if(value == 3){

        stri("Dividing each number by the",27,15,375+(30*8));
        stri("previous number gives:",22,15,375+(30*7));
        stri("1/1=1, 2/1=2, 3/2 = 1.5,",23,15,375+(30*6));
        stri("The resulting sequence is:",26,15,375+(30*5));
        stri("1.666.., 1.6, 1.625, 1.615,",28,15,375+(30*4));
        stri("1.619, 1.6181, 1.6179. They",28,15,375+(30*3));
        stri("keep oscillating around 1.618",29,15,375+(30*2));
        stri("The value of phi: The golden",31,15,375+(30*1));
        stri("ratio!",6,15,375);

        stri("Golden Spiral shows its",24,15,375-(30*2));
        stri("manifestation in nature.",24,15,375-(30*3));
        stri("For E.g. Spiral Galaxy,",23,15,375-(30*4));
        stri("Growth of leaves, Shells",24,15,375-(30*5));
        stri("Pinecones, etc.",15,15,375-(30*6));

        stri("Draw curve by click. the end",29,15,375-(30*8));
        stri("points of square (Also give 2",30,15,375-(30*9));
        stri("control points(Bezier Curve))",31,15,375-(30*10));

    }
    else if(value==4)
    {
        stri("There are five square of ",25,15,375+(30*8));
        stri("size 1, 1, 2, 3 and 5.",22,15,375+(30*7));
        stri("Red colour represent hour,",26,15,375+(30*6));
        stri("Green represent minute and",26,15,375+(30*5));
        stri("Blue represent both hour",25,15,375+(30*4));
        stri("and minute.",12,15,375+(30*3));
        stri("To calculate time,",18,15,375+(30*1));
        stri("find hour and minute,",21,15,375);
        stri("then multiply minute by 5.",26,15,375-(30*1));
    }
}

int main(int argc, char**argv){
     //Generates all subsets of 5 fibonacci numbers using bitmasking technique
	for (i = 0; i < (1 << 5); i++)
	{
		int sum = 0;
		vector <int> temp;
		for (j = 0; j < 5; j++)
		{
			if (i&(1 << j))
			{
				sum += fib[j];
				temp.push_back(j); //pushes indexes
			}
		}
		values[sum].push_back(temp);
	}

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);
    glutInitWindowSize(960,640);
    glutInitWindowPosition(100,100);
    window = glutCreateWindow("Fibonacci and Golden Sections in Nature");
    createMenu();
    glClearColor(0.0,0.0,0.0,0.0);
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
	glutKeyboardFunc(key);
    //glutIdleFunc(idle);
    //glEnable(GL_DEPTH_TEST);
    //init();

    glutInitWindowSize(300,640);
    window2 = glutCreateWindow("INSTRUCTIONS");

    //define a window position for second window
    glutPositionWindow(1060,100);

    // register callbacks for second window, which is now current

    glutDisplayFunc(instruction);

    //glutKeyboardFunc(handleKeypress);

    glutMainLoop();
    return EXIT_SUCCESS;
}
