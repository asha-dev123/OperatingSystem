#include "types.h"
#include "user.h"

int main(int argc, char * argv[]) {

  if(argc == 1)
  {
    printf(2,"Too few arguments. Expecting number of ticks\n");
  }
  else if(argc > 2)
  {
    printf(2,"Too many arguments.\n");
  }
  else
  {
    int x = atoi(argv[1]);
    sleep(x);
  }
  exit();
}