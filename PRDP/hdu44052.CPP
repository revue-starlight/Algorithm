 
 #include<stdio.h>
 #include<string.h>
 #include<algorithm>
 using namespace std;
 const int maxn = 100005;
 int fly[ maxn ];
 double ex[ maxn ];
 int main(){
     int n,m;
     while( scanf("%d%d",&n,&m)!=EOF ,n+m ){
         for( int i=0;i<=n;i++ ){
             ex[ i ]=0;
             fly[ i ]=-1;
         }
         for( int i=0;i<m;i++ ){
             int a,b;
             scanf("%d%d",&a,&b);
             fly[a]=b;
         }
         ex[ n ]=0;
         for( int i=n-1;i>=0;i-- ){
             if( fly[i]!=-1 ){
                 ex[ i ]=ex[ fly[i] ];
             }
             else {
                 for( int j=1;j<=6;j++ ){
                     if( i+j>=n )
                         ex[ i ]+=((1.0/6.0)*ex[ n ]);
                     else
                         ex[ i ]+=((1.0/6.0)*ex[ i+j ]);
                 }
                 ex[ i ]+=1.0;
             }
         }
         printf("%.4lf\n",ex[ 0 ]);
     }
     return 0;
 }