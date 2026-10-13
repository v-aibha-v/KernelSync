#include <stdio.h>
int main()
{
  int p, b;
  scanf("%d %d", &p, &b);
  int block[b], process[p];
  for (int i = 0; i < p; i++)
    scanf("%d", &process[i]);
  for (int i = 0; i < b; i++)
    scanf("%d", &block[i]);
  for (int i = 0; i < p; i++)
  {
    int allocated = -1;
    for (int j = 0; j < b; j++)
    {
      if (block[j] >= process[i] && allocated == -1)
      {
        allocated = j;
        // block[j]-= process[i]; we dec at end
      }
      else
      {
        if (block[j] >= process[i] && block[j] > block[allocated])
          allocated = j;
      }
    }
    if (allocated == -1)
      printf("process %d -> not allocated", i + 1);
    else
    {
      printf("process %d -> block %d", i + 1, allocated + 1);
      block[allocated] -= process[i];
    }
  }
}