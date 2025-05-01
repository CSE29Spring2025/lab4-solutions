#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* XXX: You may need to make LARGE-SCALE CHANGES.
 *       It may even be helpful to consider rewriting getQueries while reusing parts of our code.
 *       Please collaborate with your group on this!!
 */
char *getQueries(char *url) {

  // search for ?
  char *ptr = url;
  while (*ptr != '?' && *ptr != 0) {
    ptr++;
  }
  if (*ptr == '?') {
    ptr += 1;
  }

  // find the length of our target
  int toRetLength = 0;
  char *ptr2 = ptr;
  while (*ptr2 != 0) {
      toRetLength += 1;
      ptr2 += 1;
  }

  // create another intermediate string to store our answer
  char *toRet = malloc(sizeof(char) * (toRetLength + 1));
  for (int i = 0; i < toRetLength; i++) {
      toRet[i] = tolower(ptr[i]);
  }
  toRet[toRetLength] = 0;
  return toRet;

}

/*
 * XXX: You MAY need to modify the main function.
 */
int main(int argc, char *argv[]) {
  char s[] = "https://example.com/over/there?Name=Ferret";

  //expect output to be name=ferret
  char *queries = getQueries(s);
  printf("%s\n", queries);
  if (queries) {
      free(queries);
  }

  return 0;
}
