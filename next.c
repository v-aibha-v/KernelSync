#include <stdio.h>
int main()
{
  int p, b;
  scanf("%d %d", &p, &b);
  int process[p], block[b];
  for (int i = 0; i < p; i++)
    scanf("%d", &process[i]);
  for (int i = 0; i < b; i++)
    scanf("%d", &block[i]);
  int prev = 0;
  for (int j = 0; j < p; j++)
  {
    int allocated = -1;
    for (int i = 0; i < b; i++)
    {
      int k = (i + prev) % b;
      if (block[k] >= process[j])
      {
        allocated = k;
        block[k] -= process[j];
        prev = k;
        break;
      }
    }
    if (allocated != -1)
    {
      printf("process %d -> block %d\n", j + 1, allocated + 1);
    }
    else
    {
      printf("process %d -> not allocated", j + 1);
    }
  }
  return 0;
}