#include<iostream>
#include<graphics.h>
#include<math.h>
#include<vector>
using namespace std;
class point{
public:
    int x,y;
    //point(int a,int b){
    //x=a;y=b;}
};
void drawsnake(vector<point> a){
    for(int i=1;i<a.size();i++){
        setcolor(RED);
        circle(a[i].x,a[i].y,10);
        setfillstyle(SOLID_FILL,RED);
        floodfill(a[i].x,a[i].y,RED);
                                }
        //cout<<1;
                                }
point food(vector<point> snake){
    int b=rand();
    int c=rand();
    b=b%24;
    b=b*20+15;
        c=c%24;
    c=c*20+15;
   // cout<<b<<c;
    for(int i=0;i<snake.size();i++){
            if((snake[i].x==b)&&(snake[i].y==c))
            {return food(snake);}}
    setcolor(BLUE);
    circle(b,c,10);
    setfillstyle(SOLID_FILL,BLUE);
        floodfill(b,c,BLUE);
        point r;
        r.x=b;r.y=c;
   return r;
}
int main(){
    initwindow(510,510);
    setcolor(RED);
    for(int i=0;i<6;i++)
        rectangle(0+i,0+i,510-i,510-i);
    int page=0,q=0,score=0;
    vector<point> snake(3);
    snake[0].x=55;
    snake[1].x=35;
    snake[2].x=15;
    for (int i=0;i<3;i++)
        snake[i].y=15;
    drawsnake(snake);
    point a,s,d,w,e,x;
    a.x=-20;a.y=0;
    s.x=0;s.y=20;
    d.x=20;d.y=0;
    w.x=0;w.y=-20;
    point foood=food(snake);
    setcolor(BLUE);
    circle(snake[0].x,snake[0].y,10);
    setfillstyle(SOLID_FILL,BLUE);
        floodfill(snake[0].x,snake[0].y,BLUE);
        //cout<<q;
        x.x=20;x.y=0;
    while(q!=1){

        setactivepage(1-page);
        setvisualpage(page);
        cleardevice();
        e=snake[0];
        if(GetAsyncKeyState(37)){x=a;}
        if(GetAsyncKeyState(39)){x=d;}
        if(GetAsyncKeyState(40)){x=s;}
        if(GetAsyncKeyState(38)){x=w;}
        e.x=e.x+x.x;
        e.y=e.y+x.y;
        for(int i=1;i<snake.size();i++){
            if((snake[i].x==e.x)&&(snake[i].y==e.y))
            {q=1;}
           // cout<<q;
                    }
        if((e.x<5)||(e.y<5)||(e.x>505)||(e.y>505)){
            q=1;}
           // cout<<'5'<<q;
        if((e.x==foood.x)&&(foood.y==e.y)){
        point y=snake[snake.size()-1];
        for(int i=snake.size();i>=2;i--){
        snake[i-1]=snake[i-2];}
        snake.push_back(y);
        snake[0]=e;
        foood=food(snake);
        drawsnake(snake);
        score++;
        }
        else{

        for(int i=snake.size();i>=2;i--){
        snake[i-1]=snake[i-2];

        }
         snake[0]=e;
        drawsnake(snake);
         setcolor(BLUE);
    circle(foood.x,foood.y,10);
    setfillstyle(SOLID_FILL,BLUE);
        floodfill(foood.x,foood.y,BLUE);
       }

       setcolor(BLUE);
    circle(e.x,e.y,10);
    setfillstyle(SOLID_FILL,BLUE);
        floodfill(e.x,e.y,BLUE);
        delay(150);
        page=1-page;

        }
//char sco[10]=string(10);
        setvisualpage(1-page);
        setactivepage(1-page);
        setcolor(RED);
        settextstyle(10,4,4);
        outtextxy(250,250,"gameover");
                //outtextxy(100,150,string(sc);
        delay(10000);
        cout<<"game over"<<score;

        getch();

        }
