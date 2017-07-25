#include <stdio.h>
#include <sqlite3.h>


static int callback(void *data, int argc, char **argv, char **azColName){
   FILE *f = fopen("a3p1task2.txt", "a");
      fprintf(f,"user:%s\n",argv[0]);
      fprintf(f,"uid:%s\n",argv[2]);
      fprintf(f,"gid:%s\n",argv[3]);
      fprintf(f,"gecos:%s\n",argv[4]);
      fprintf(f,"home:%s\n",argv[5]);
      fprintf(f,"shell:%s\n \n",argv[6]);
   //printf("\n");
   return 0;
}

static int callback1(void *data, int argc, char **argv, char **azColName){
      printf("user:%s\n",argv[0]);
      printf("uid:%s\n",argv[2]);
      printf("gid:%s\n",argv[3]);
      printf("gecos:%s\n",argv[4]);
      printf("home:%s\n",argv[5]);
      printf("shell:%s\n \n",argv[6]);
   //printf("\n");
   return 0;
}

static int callback2(void *data, int argc, char **argv, char **azColName){
   FILE *f = fopen("a3p1task4.txt", "a");
      fprintf(f,"user:%s\n",argv[0]);
      fprintf(f,"uid:%s\n",argv[2]);
      fprintf(f,"gid:%s\n",argv[3]);
      fprintf(f,"gecos:%s\n",argv[4]);
      fprintf(f,"home:%s\n",argv[5]);
      fprintf(f,"shell:%s\n \n",argv[6]);
   //printf("\n");
   return 0;
}


int main(int argc, char* argv[])
{
   sqlite3 *db;
   char *zErrMsg = 0;
   int rc;
   char * sql;

   rc = sqlite3_open("mypasswd", &db);

   if( rc ){
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
   }else{
//      fprintf(stderr, "Opened database successfully\n");
   }
   //FILE *f = fopen("a3p1task2.txt", "w");
   sql = "select * from pwtable; ";

   rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
   if( rc != SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   }
   
   sql = "select * from pwtable where uid= '27' ; ";

   rc = sqlite3_exec(db, sql, callback1, 0, &zErrMsg);
   if( rc != SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   }

   sql = "UPDATE pwtable set gecos = 'MySQL Server' where uid = '27' ; "\
            " select * from pwtable where uid= '27' ; ";

   rc = sqlite3_exec(db, sql, callback1, 0, &zErrMsg);
   if( rc != SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   }

   sql = "select * from pwtable; ";

   rc = sqlite3_exec(db, sql, callback2, 0, &zErrMsg);
   if( rc != SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   }

   sqlite3_close(db);
   return 0;
}
