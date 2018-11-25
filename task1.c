#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

void cleanup() {
  unlink("temp.cmp");
}
int main(void) {
  int fd,i;
  char jono[]="Tässä on tekstiä\n";

  if ((fd = creat("temp.cmp", S_IRUSR | S_IWUSR)) < 0) {
    perror("creat error");
  }
  for (i=1;i<31;++i) {
    write(fd,jono,strlen(jono));
    sleep(1);

  }
  close(fd);
  atexit(cleanup);



  return 0;
}
