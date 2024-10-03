// Function to solve Tower of Hanoi
void tower(int n, char beg, char aux, char end)
{   if(n<=0)
   {
    printf(" illegal entry");
   }
 else if (n == 1)
    {
        printf("\nMove disc 1 from rod %c to rod %c", beg,end);
        return;
    }
    else{
    tower(n - 1, beg, end,  aux);
    tower(1 ,beg , aux , end);
    tower(n - 1, aux, beg , end);
}
}

int main()
{
    int n;
    printf("Enter the number of discs: ");
    scanf("%d", &n);
    printf("Tower of Hanoi with %d discs:\n", n);
    tower(n, 'A', 'B', 'C'); // A, B, C are the names of the rods
}