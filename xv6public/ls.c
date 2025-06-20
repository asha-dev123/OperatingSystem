#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"

int a_flag = 0;
int d_flag = 0;

char*
fmtname(char *path)
{
  static char buf[DIRSIZ+1];
  char *p;

  // Find first character after last slash.
  for(p=path+strlen(path); p >= path && *p != '/'; p--)
    ;
  p++;
  int len = strlen(p);
  if (d_flag == T_DIR) {
        p[len] = '/';
        p[++len] = '\0';
    }

  // Return blank-padded name.
  if(strlen(p) >= DIRSIZ)
    return p;
  memmove(buf, p, strlen(p));
  memset(buf+strlen(p), ' ', DIRSIZ-strlen(p));
  return buf;
}

void
ls(char *path)
{
  char buf[512], *p;
  int fd;
  struct dirent de;
  struct stat st;

  if((fd = open(path, 0)) < 0){
    printf(2, "ls: cannot open %s\n", path);
    return;
  }

  if(fstat(fd, &st) < 0){
    printf(2, "ls: cannot stat %s\n", path);
    close(fd);
    return;
  }
  
  switch(st.type){
    case T_FILE:
      d_flag = st.type;
    
      if(a_flag == 1)
        printf(1, "%s %d %d %d\n", fmtname(path), st.type, st.ino, st.size);
      else if(a_flag == 0 && path[0] != '.')
        printf(1, "%s %d %d %d\n", fmtname(path), st.type, st.ino, st.size);
      break;

    case T_DIR:
      if(strlen(path) + 1 + DIRSIZ + 1 > sizeof(buf)){
        printf(1, "ls: path too long\n");
        break;
      }
      strcpy(buf, path);
      p = buf+strlen(buf);
      *p++ = '/';
      while(read(fd, &de, sizeof(de)) == sizeof(de)){
        if(de.inum == 0)
          continue;
        memmove(p, de.name, DIRSIZ);
        p[DIRSIZ] = 0;
        if(stat(buf, &st) < 0){
          printf(1, "ls: cannot stat %s\n", buf);
          continue;
        }
        d_flag = st.type;
        char* f_buffer = fmtname(buf);
        
        if(a_flag == 1)
        printf(1, "%s %d %d %d\n", f_buffer, st.type, st.ino, st.size);
        else if(a_flag == 0 && f_buffer[0] != '.')
        printf(1, "%s %d %d %d\n", f_buffer, st.type, st.ino, st.size);
        
      }
      break;
  }
  close(fd);
}

int
main(int argc, char *argv[])
{
  int i;
  if(argc > 1 && argv[1][0] == '-' && argv[1][1] == 'a' && argv[1][2] == '\0')
  {
    a_flag = 1;
    ++ argv;
    -- argc;
  }
  
  if(argc < 2){
    ls(".");
    exit();
  }
  for(i=1; i<argc; i++)
    ls(argv[i]);
  exit();
}
